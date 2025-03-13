##
from PySide2.QtGui import QVector3D

import math

def vec2q(d):
    return QVector3D(*d.toTuple())
def vec2c(d):
    return None

class PressState:
    press_first = 1, 
    press_second = 2

class EnumPickType:
    axis = 1
    vertex = 2
    intersect_point = 3
    guide_line = 4
    edge_center = 5
    edge = 6
    face = 7
    extra_guide_line = 8
    extra_guide_point = 9
    model_entity = 12

class BaseTool:
    def __init__(self):
        self.vertex_list = None
        self.intersect_list = None
        self.edge_center_list = None
        self.axis_list = None
    
    def activate(self):
        pass
    
    def deactivate(self):
        pass

    def draw(self, gl):
        pass
    
    def draw_2d(self, painter):
        pass
    
    def enterValue(self, value):
        pass
    
    def on_left_button_down(self, pos, mod):
        pass
        
    def on_left_button_up(self, pos):
        pass
        
    def do_double_click(self, pos):
        pass

    def on_mouse_move(self, pos, modifiers):
        pass
    
    def on_ctrl_press(self):
        pass

    ############
    # Triangle Intersect
    # 三角形碰撞检测
    ############    
    def doModelRayTrace(self, x, y):
        return False

    def computeCameraToRay(self, x, y):
        view_width = self.view.width()
        view_height = self.view.height()
        imageAspectRatio = view_width / view_height
        scale = math.tan(math.radians(35 * 0.5));
        px = (2*((float(x)+0.5)/view_width)-1) * scale * imageAspectRatio
        py = (1.0-2*(float(y)+0.5)/view_height) * scale
        
        ray_origin = QVector3D(0, 0, 0)
        ray_dir = QVector3D(px, py, -1).normalized()
        
        inv_matrix = self.view.camera_matrix_inv
        world_ray_origin = inv_matrix.map(ray_origin)
        world_ray_dir = inv_matrix.map(ray_dir)
        
        a = (world_ray_dir - world_ray_origin).normalized()
        self.ray_dir = vec2c(a)
        self.ray_start = vec2c(world_ray_origin)
        b = self.ray_start + self.ray_dir* 1000
        self.ray_end = vec2c(b)
    
    def compute_camera_pos_ray(self, x, y):
        view_width = self.view.width()
        view_height = self.view.height()
        imageAspectRatio = view_width / view_height
        scale = math.tan(math.radians(35 * 0.5));
        px = (2*((float(x)+0.5)/view_width)-1) * scale * imageAspectRatio
        py = (1.0-2*(float(y)+0.5)/view_height) * scale
        
        ray_origin = QVector3D(0, 0, 0)
        ray_dir = QVector3D(px, py, -1).normalized()
        
        inv_matrix = self.view.camera_matrix_inv
        world_ray_origin = inv_matrix.map(ray_origin)
        world_ray_dir = inv_matrix.map(ray_dir)
        
        a = (world_ray_dir - world_ray_origin).normalized()
        ray_dir = vec2c(a)
        ray_start = vec2c(world_ray_origin)
        b = ray_start + ray_dir* 1000
        ray_end = vec2c(b)
        return ray_start, ray_end
    
    def draw_ray(self, ray_start, ray_end, gl):
        gl.glColor3f(1.0, 0.0, 0.0);
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(*ray_start.toTuple())
        gl.glVertex3d(*ray_end.toTuple())
        gl.glEnd()

    def draw_target(self, p, gl):
        if p is None:
            return
        self.draw_target_with_size(p, 2, gl)

    def draw_target_with_size(self, p, size, gl):
        if p is None:
            return
        
        S = size
        
        gl.glColor3f(0.0, 0.0, 1.0);
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(p.x-S, p.y, p.z )
        gl.glVertex3d(p.x+S, p.y, p.z )
        gl.glEnd()
        
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(p.x,  p.y-S,  p.z )
        gl.glVertex3d(p.x,  p.y+S,  p.z )
        gl.glEnd()
        
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(p.x,  p.y,  p.z-S  )
        gl.glVertex3d(p.x,  p.y,  p.z+S )
        gl.glEnd()

    def draw_target_with_size_nocolor(self, p, size, gl):
        S = size

        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(p.x-S, p.y, p.z )
        gl.glVertex3d(p.x+S, p.y, p.z )
        gl.glEnd()
        
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(p.x,  p.y-S,  p.z )
        gl.glVertex3d(p.x,  p.y+S,  p.z )
        gl.glEnd()
        
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(p.x,  p.y,  p.z-S  )
        gl.glVertex3d(p.x,  p.y,  p.z+S )
        gl.glEnd()

    def draw_axis(self, pos, gl, colored=True):
        inf = 100000
        
        x = pos.x()
        y = pos.y()
        z = pos.z()
        
        gl.glPushName(0)
        
        # x
        if colored:
            gl.glColor3f(1.0, 0.0, 0.0);
        gl.glLoadName(1)
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(x, y, z)
        gl.glVertex3d(x+inf, 0, 0)
        gl.glEnd()
        
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(x, y, z)
        gl.glVertex3d(x-inf, y, z)
        gl.glEnd()
        
        # y
        if colored:
            gl.glColor3f(0.0, 1.0, 0.0);
        gl.glLoadName(2)
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(x, y, z)
        gl.glVertex3d(x, y+inf, z)
        gl.glEnd()

        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(x, y, z)
        gl.glVertex3d(x, y-inf, z)
        gl.glEnd()
        
        # z
        if colored:
            gl.glColor3f(0.0, 0.0, 1.0);
        gl.glLoadName(3)
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(x, y, z)
        gl.glVertex3d(x, y, z+inf)
        gl.glEnd()

        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(x, y, z)
        gl.glVertex3d(x, y, z-inf)
        gl.glEnd()
        
        gl.glPopName()
    
