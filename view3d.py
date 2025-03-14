from PySide2.QtCore import Qt, QPoint, QRect, QTimer
from PySide2.QtGui import QPainter, QMatrix4x4, QVector3D, QVector4D
#from PySide2.QtGui import QOpenGLFramebufferObjectFormat, QOpenGLFramebufferObject
from PySide2.QtWidgets import QOpenGLWidget
import OpenGL.GL
import OpenGL.GLU
import numpy as np
import math

from perf_counter_view import PerformanceCounter
from tool_camera import CameraTool
from tool_select import SelectTool

import su
def q2c(d):
    return su.CVector3D(*d.toTuple())

class ModeEnum:
    default = 1
    pick = 2

class Camera:
    def __init__(self):
        self.position = QVector3D(103, -172, 90)
        self.target   = QVector3D(52, 28, 26)
        self.fov = 35.0
        
        self.forward = (self.target-self.position).normalized()
        up = QVector3D(0, 0, 1.0)
        self.right = QVector3D.crossProduct(self.forward, up).normalized()
        self.up = QVector3D.crossProduct(self.right, self.forward).normalized()

        self.compute()
    
    def compute(self):
        self.forward = (self.target-self.position).normalized()
        self.right = QVector3D.crossProduct(self.forward, self.up).normalized()

############
# GLWidget
# OpenGL 窗口通用程序框架
#   1、创建OpenGL环境
#   2、设置矩阵
#   3、控制窗口视角
#   4、调用 draw 绘图主函数
############
class View3D(QOpenGLWidget):
    def __init__(self, parent):
        super(View3D, self).__init__( parent)
        
        self.pressButton = 0
        self.lastPos = QPoint()
        
        self.first_click = False
        self.double_click = False
        self.third_click = False
        
        self.mode = ModeEnum.default
        
        self.pc = PerformanceCounter()

        self.camera = Camera()
        self.camera_zoom = 1.0

        self.camera_tool = CameraTool(self)
        self.tool_select = SelectTool(self)
        self.current_tool = self.tool_select
        
        self.model = None
        
        self.pick_window_pos = QPoint()
        self.pick_size = 9
        
        self.last_width = 0
        self.last_height = 0

    ############
    # 创建OpenGL环境
    # Qt6 和 Qt5的主要区别在这里
    ############
    def initializeGL(self):
        self.gl = OpenGL.GL
        self.glu = OpenGL.GLU

    def setStatusBar(self, msg):
        statusbar = self.mainWindow.statusBar
        statusbar.showMessage(msg)
    
    def enableMeasureInput(self):
        mainWindow = self.mainWindow
        mainWindow.enable_input = True
        
    def disableMeasureInput(self):
        mainWindow = self.mainWindow
        mainWindow.enable_input = False
        mainWindow.clearKeyInput()
        
    ############
    # paintEvent
    ############
    def paintEvent(self, event):
        if not self.isVisible():
            return
        # GL Context
        self.pc.start(0)
        self.makeCurrent()
        self.pc.end(0)
        
        self.paintDefaultMode()

        # draw 2D
        self.draw2d()

    ############
    # Draw 2D
    ############
    def draw2d(self):
        w = self.width()
        h = self.height()
        painter = QPainter(self)
        #================
        # 后面部分是绘制2D图形
        # 需要精确到像素点上
        # 一个小Hack可解决OpenGL
        # 绘制二位图像浮点数不
        # 能精确到像素的问题
        #================
        painter.resetTransform()
        painter.translate(0.5, 0.5)
        
        if False:
            painter.setPen(Qt.black)
            painter.drawLine(0, 0, w-1, 0)
            painter.drawLine(0, h-1, w-1, h-1)
            painter.drawLine(0, 0, 0, h-1)
            painter.drawLine(w-1, 0, w-1, h-1)
        
        self.DrawPC(painter)

    ############
    # 显示性能数据
    ############
    def DrawPC(self,  painter):
        # PC
        PC_WIDTH = 120
        PC_HEIGHT = 100
        sx = self.width()-PC_WIDTH -1
        sy = self.height()-PC_HEIGHT- 1
        pc_rect = QRect( sx,  sy, PC_WIDTH, PC_HEIGHT)
        self.pc.rect = pc_rect
        #painter.setClipRect(pc_rect)
        painter.translate(pc_rect.x(),  pc_rect.y())
        painter.setPen(Qt.black)
        self.pc.Draw(painter)
        painter.resetTransform()
        
    ############
    # DefaultMode
    # 
    ############
    def paintDefaultMode(self):

        # Step 1
        self.pc.start(1)
        self.gl.glClearColor(0.85, 0.85, 0.85, 1.0)
        self.gl.glClear(self.gl.GL_COLOR_BUFFER_BIT | self.gl.GL_DEPTH_BUFFER_BIT )
        self.gl.glEnable(self.gl.GL_DEPTH_TEST)
        self.gl.glDisable(self.gl.GL_STENCIL_TEST)
        
        # Step 2
        self.SetupMatrix()
        
        # Step 3
        self.gl.glDisable(self.gl.GL_TEXTURE_2D)
        self.drawGird(self.gl)
        self.pc.end(1)
        
        # Draw model
        self.pc.start(2)
        if self.model and self.model.ok:
            self.model.draw(self.gl)
        self.pc.end(2)
        
        # Step 4
        self.pc.start(3)
        #self.current_tool.draw(self.gl)
        self.pc.end(3)
        
        self.pc.start(4)
        self.gl.glFlush()
        self.gl.glFinish()
        self.pc.end(4)

    def build_stencil_patten(self, block_size=96):
        
        self.makeCurrent()
        
        #if self.width() == self.last_width and self.height() == self.last_height:
        #    return
        
        self.last_width = self.width()
        self.last_height = self.height()
        
        bs = block_size
        
        width = self.width()
        height = self.height()
        self.gl.glViewport(0, 0, width, height)  
        self.gl.glMatrixMode(self.gl.GL_PROJECTION)
        self.gl.glLoadIdentity()
        self.gl.glOrtho( 0, width, 0, height, 0, 1)
        self.gl.glMatrixMode(self.gl.GL_MODELVIEW)
        self.gl.glLoadIdentity()

        data = np.zeros((bs, bs), dtype=np.uint8 )
        
        for y in range(int(bs/4)):
            py = y*4
            if py >= bs: 
                continue
            for x in range(int(bs/4)):
                if y & 1 == 0:
                    px = x*4
                else:
                    px = x*4+2
                if px >= bs: 
                    continue
                data[py][px] = 1
        
        self.gl.glRasterPos2i(0, 0)
        self.gl.glDrawPixels(bs, bs, self.gl.GL_STENCIL_INDEX, self.gl.GL_BYTE, data)
        
        for y in range(int(height/bs)+1):
            for x in range(int(width/bs)+1):
                self.gl.glRasterPos2i(x*bs, y*bs)
                self.gl.glCopyPixels(0, 0, bs, bs, self.gl.GL_STENCIL)

    ############
    # 设置矩阵
    # 透视矩阵和Camera矩阵
    ############
    def SetupMatrix(self):
        w = self.width()
        h = self.height()

        # Viewport
        self.gl.glViewport(0, 0, w, h)  
        
        # Projection
        self.gl.glMatrixMode(self.gl.GL_PROJECTION)
        pm = self.ComputeProjectMatrix()
        self.gl.glLoadMatrixf(pm.data())
        
        # Camera
        self.SetupCameraMatrix()
    
    def SetupCameraMatrix(self):
        self.gl.glMatrixMode(self.gl.GL_MODELVIEW)
        m, invm = self.ComputeCameraMatrix()
        self.camera_matrix_inv = invm
        #m = self.ComputeCameraUseQt()
        self.gl.glLoadMatrixf(m.data())

    def ComputeCameraMatrix(self):
        camera = self.camera
        
        forward = (camera.target-camera.position).normalized()
        
        self.camera_zoom = (camera.target-camera.position).length()

        right = QVector3D.crossProduct(forward, camera.up)
        
        qm = QMatrix4x4()
        z_axis = -forward
        qm.setColumn(0,  right.toVector4D())
        qm.setColumn(1,  camera.up.toVector4D())
        qm.setColumn(2,  z_axis.toVector4D())
        
        pos = camera.position
        qm.setColumn(3,  QVector4D(pos.x(), pos.y(), pos.z(),  1.0))

        (inv, ok) = qm.inverted()
        return inv, qm
    
    def ComputeFOV(self):
        w = self.width()
        h = self.height()
        fov = self.camera.fov
        aspectRatio = w/h
        if w >= h:
            fov_h = fov
            fov_w = fov * aspectRatio
        else:
            fov_w = fov
            fov_h = fov / aspectRatio
        return fov_w, fov_h, aspectRatio
    
    def ComputeProjectMatrix(self):
        fov_w, fov_h, aspectRatio = self.ComputeFOV()
        pm = QMatrix4x4()
        pm.perspective(fov_h,  aspectRatio,  2,  10000)
        return pm

    ############
    # Pick
    # 
    ############
    def beginSelect(self, x, y, pick_width, pick_height):
        self.makeCurrent()
        
        gl = self.gl

        gl.glSelectBuffer(16384)
        
        gl.glInitNames()
        gl.glRenderMode(gl.GL_SELECT)

        # Step 2
        self.SetupPickMatrix(x, y, pick_width, pick_height)
        self.SetupCameraMatrix()
    
    def endSelect(self):
        return self.gl.glRenderMode(self.gl.GL_RENDER)
        
    def SetupPickMatrix(self, pick_x, pick_y, pick_width, pick_height):
        # ViewPort
        h = self.height()
        viewport = self.gl.glGetIntegerv(self.gl.GL_VIEWPORT)
        
        # Projection
        self.gl.glMatrixMode(self.gl.GL_PROJECTION)
        self.gl.glLoadIdentity()
        self.glu.gluPickMatrix(pick_x, h-pick_y, pick_width, pick_height, viewport)
        
        pm = self.ComputeProjectMatrix()
        self.gl.glMultMatrixf(pm.data())

    def ComputeCameraRay(self, x, y):
        view_width = self.width()
        view_height = self.height()
        imageAspectRatio = view_width / view_height
        scale = math.tan(math.radians(35 * 0.5));
        px = (2*((float(x)+0.5)/view_width)-1) * scale * imageAspectRatio
        py = (1.0-2*(float(y)+0.5)/view_height) * scale
        
        ray_origin = QVector3D(0, 0, 0)
        ray_dir = QVector3D(px, py, -1).normalized()
        
        inv_matrix = self.camera_matrix_inv
        world_ray_origin = inv_matrix.map(ray_origin)
        world_ray_dir = inv_matrix.map(ray_dir)
        
        a = (world_ray_dir - world_ray_origin).normalized()
        ray_dir = q2c(a)
        ray_start = q2c(world_ray_origin)
        b = ray_start + ray_dir* 1000
        ray_end = q2c(b)
        return ray_start, ray_dir, ray_end


    ############
    # 调用Tool & 视角控制
    # 1. 旋转: 中键
    # 2. 缩放: 滚轮
    # 3. 平移: Shift+中键
    ############
    def mousePressEvent(self,event):
        self.grabMouse()
        
        self.pressButton = event.button()
        
        mod = event.modifiers()
        
        if self.pressButton == 1:
            
            if False:
            #if self.current_tool == self.select_tool:
                #
                def onSingleShotTimeout():
                    self.first_click = False
                    self.double_click = False
                    self.third_click = False
                
                if self.first_click and self.double_click:
                    self.third_click = True
                elif self.first_click:
                    self.double_click = True
                else:
                    self.current_tool.on_left_button_down(event.pos(), mod)
                    QTimer.singleShot(600, onSingleShotTimeout);
                    self.first_click = True
            else:
                self.current_tool.on_left_button_down(event.pos(), mod)

        elif self.pressButton == 4:
            self.camera_tool.on_left_button_down(event.pos(), mod)
            
        elif self.pressButton == 2:
            pass
            
        self.repaint()

    
    def mouseReleaseEvent(self, event):
        self.pressButton = 1

        if event.button() == 1:
            
            if False:
            #if self.current_tool == self.select_tool:
                if self.third_click:
                    self.current_tool.do_third_click(event.pos())
                elif self.double_click:
                    #print("double click")
                    self.current_tool.do_double_click(event.pos())
                else:
                    self.current_tool.on_left_button_up(event.pos())
            
            else:
                self.current_tool.on_left_button_up(event.pos())

        elif event.button() == 4:
            self.camera_tool.on_left_button_up(event.pos())
            
        elif event.button() == 2:
            pass
        
        self.releaseMouse()

        self.repaint()
        
    def mouseMoveEvent(self, event):
        mod = event.modifiers()
        
        if self.pressButton == 1:
            self.current_tool.on_mouse_move(event.pos(), mod)
            
        elif self.pressButton == 4:
            self.camera_tool.on_mouse_move(event.pos(), mod)
            
        else:
            pass
        
        # Refresh Screen
        self.repaint()

    def wheelEvent(self, event):
        point = event.position().toPoint()
        delta = event.angleDelta().y()
        
        self.camera_tool.doZoom(point,  delta)
        
        # Refresh Screen
        self.repaint()
        
    def ctrlKeyPress(self):
        self.current_tool.on_ctrl_press()
    
    def shiftKeyPress(self):
        print("Shift key press")

    
    ############
    # Draw Grid
    # 绘制坐标轴
    ############
    def drawGird(self, gl):

        inf = 100000
        
        stipple = 0x1111
        gl.glLineStipple(1, stipple)
        
        # x
        gl.glColor3f(1.0, 0.0, 0.0);
        gl.glDisable(gl.GL_LINE_STIPPLE)
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(0, 0, 0)
        gl.glVertex3d(inf, 0, 0)
        gl.glEnd()

        gl.glEnable(gl.GL_LINE_STIPPLE) 
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(0, 0, 0)
        gl.glVertex3d(-inf, 0, 0)
        gl.glEnd()
        
        # y
        gl.glColor3f(0.0, 1.0, 0.0);
        gl.glDisable(gl.GL_LINE_STIPPLE)
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(0, 0, 0)
        gl.glVertex3d(0, inf, 0)
        gl.glEnd()

        gl.glEnable(gl.GL_LINE_STIPPLE) 
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(0, 0, 0)
        gl.glVertex3d(0, -inf, 0)
        gl.glEnd()
        
        # z
        gl.glColor3f(0.0, 0.0, 1.0);
        gl.glDisable(gl.GL_LINE_STIPPLE)
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(0, 0, 0)
        gl.glVertex3d(0, 0, inf)
        gl.glEnd()

        gl.glEnable(gl.GL_LINE_STIPPLE) 
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(0, 0, 0)
        gl.glVertex3d(0, 0, -inf)
        gl.glEnd()
        
        gl.glDisable(gl.GL_LINE_STIPPLE)

    ############
    # Tools
    # 1. selection tool
    # 2. move tools
    ############
    def use_tool(self, tool):
        if self.current_tool:
            self.current_tool.deactivate()
        
        self.current_tool = tool
        
        self.current_tool.activate()
        
        self.repaint()

