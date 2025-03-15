from PySide2.QtGui import QVector3D, QPen
from PySide2.QtCore import Qt
import math

from su import EPS2
from tool_base import BaseTool
from pick_helper import PickHelper, SelectType

MIN_RECT_SIZE = 6

class SelectTool(BaseTool):
    def __init__(self, view):
        super().__init__()
        self.view = view
        self.activate()
    
    def activate(self):
        self.is_rect_select = False
        self.select_type = SelectType.cross
        self.start_pos_x = 0
        self.start_pos_y = 0
        self.pos_x = 0
        self.pos_y = 0

    def draw(self, gl):
        pass
    
    def draw_2d(self, painter):
        if self.is_rect_select:
            pen1 = QPen(Qt.black)
            if self.select_type == SelectType.cross:
                dashes = [4, 6]
                pen1.setDashPattern(dashes)
            painter.setPen(pen1)

            painter.drawLine(self.start_pos_x , self.start_pos_y, self.pos_x, self.start_pos_y)
            painter.drawLine(self.pos_x , self.start_pos_y, self.pos_x, self.pos_y)
            painter.drawLine(self.pos_x , self.pos_y, self.start_pos_x, self.pos_y)
            painter.drawLine(self.start_pos_x , self.pos_y, self.start_pos_x, self.start_pos_y)

    def on_left_button_down(self, pos, mod):
        self.start_pos_x = pos.x()
        self.start_pos_y = pos.y()
        
        self.pos_x = pos.x()
        self.pos_y = pos.y()
        
    def do_single_select(self):
        model = self.view.model
        if not model:
            return
        
        pick = PickHelper(self.view)
        pick.do_single_pick(self.pos_x, self.pos_y, 9)
        
        best = pick.best
        if pick.best_face and pick.best_edge:
            #face_center = (pick.best_face.near + pick.best_face.far) * 0.5
            if pick.best_edge.near <= pick.best_face.far:
                best = pick.best_edge

        
        if best:
            best_len = len(best.inst_path)
            
            if best_len == 0:
                e = best.e
            elif best_len > 0:
                e = best.inst_path[0]
            elif best_len < 0:
                e = None
        
            return e
        else:
            return None
    
    def do_multi_select(self):
        model = self.view.model
        if not model:
            return
            
        width = abs(self.pos_x - self.start_pos_x)
        height = abs(self.pos_y - self.start_pos_y)
        
        if width < 2 or height < 2:
            print("select rect < 2!!!")
            return
        
        #cx = (self.pos_x + self.start_pos_x)/2;
        #cy = (self.pos_y + self.start_pos_y)/2;
        
        pick = PickHelper(self.view)
        #pick.do_pick_rect(cx, cy, width, height, self.select_type)
        
        selection = [item.e for item in pick.picked]
        model.update_selection(selection)

    def on_left_button_up(self, pos):
        self.pos_x = pos.x()
        self.pos_y = pos.y()
        
        if self.is_rect_select:
            self.do_multi_select()
        else:
            e = self.do_single_select()
            if e:
                sel = set()
                sel.add(e)
                self.view.model.update_selection(sel)
            else:
                self.view.model.update_selection(set())
        
        self.is_rect_select = False


    def on_mouse_move(self, pos, modifiers):
        self.pos_x = pos.x()
        self.pos_y = pos.y()
        
        diff_x = self.pos_x - self.start_pos_x;
        diff_y = self.pos_y - self.start_pos_y;
        d = diff_x * diff_x + diff_y * diff_y
        self.is_rect_select = False
        self.select_type = SelectType.cross
        if d > EPS2 and math.sqrt(d) > MIN_RECT_SIZE:
            self.is_rect_select = True
            if diff_x > 0:
                self.select_type = SelectType.inside

class RayTraceTool(BaseTool):
    def __init__(self, view):
        super().__init__()
        self.view = view
        self.is_intersect = False
        self.inter_pos = QVector3D()
        
        self.ray_start = QVector3D()
        self.ray_end = QVector3D()
    
    def draw(self, gl):
        if self.is_intersect:
            self.draw_ray(self.ray_start, self.ray_end, gl)
            self.draw_target_with_size(self.inter_pos, 0.2, gl)

    def on_left_button_down(self, pos, mod):
        self.inter_win_pos = pos
        px = pos.x()
        py = pos.y()
        
        # Ray trace
        self.doModelRayTrace(px, py)
        
    def on_left_button_up(self, pos):
        pass
        
    def on_mouse_move(self, pos, modifiers):
        pass
