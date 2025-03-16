
from tool_base import BaseTool, PressState
import su
from input_point import InputPoint

class MoveTool(BaseTool):
    def __init__(self, view):
        super().__init__()
        self.view = view

    def activate(self):
        self.first_point = None
        self.prev_point = None
        self.end_point = su.CVector3D()
        
        self.state = PressState.press_first
        
        self.copy_mode = False
        self.move_list = None

        self.input = InputPoint(self.view)
        
        self.view.setMouseTracking(True)

    def deactivate(self):
        self.view.setMouseTracking(False)
        self.view.disableMeasureInput()

    def draw(self, gl):
        self.input.draw(gl)
        
        if self.state == PressState.press_second:
            size = self.view.camera_zoom * 0.01
            
            self.draw_target_with_size(self.start_point, size, gl)
            self.draw_target_with_size(self.end_point, size, gl)
            
            gl.glColor3f(1.0, 0.0, 0.0);
            self.draw_line(self.start_point, self.end_point, gl)

    def draw_line(self, p1, p2, gl):
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(p1.x, p1.y, p1.z )
        gl.glVertex3d(p2.x, p2.y, p2.z )
        gl.glEnd()

    def do_input_inference(self, px, py):
        input = self.input
        input.reset()
        
        self.snap_axis = 8
        
        #=======================
        # Pick
        ok = input.inference(px, py)
        assert ok
        new_point = input.position()
        
        return new_point
    
    def do_move_list(self):
        move_list = []
        model = self.view.model
        for e in model.selection:
            if type(e) is su.SUComponentInstance:
                move_list.append(e)
        
        self.move_list = move_list
    
    def do_copy(self):
        list = []
        model = self.view.model
        for e in model.selection:
            if type(e) is su.SUComponentInstance:
                new_inst = self.copy_instance(e)
                list.append(new_inst)
        self.move_list = list

    def copy_instance(self, inst):
        comp_def = inst.GetDefinition()
        new_inst = su.CComponentInstance().DeleteLater()
        tm = inst.GetTransform()
        new_inst.SetTransform(tm)
        new_inst.SetMaterial(None)
        new_inst.SetDefinition(comp_def)
        
        comp = self.view.model.get_opend_comp()
        comp.AddEntity(new_inst)
        return new_inst
    
    def on_left_button_down(self, pos, mod):
        #=======================
        # input_point
        new_point = self.do_input_inference(pos.x(), pos.y())

        if self.state == PressState.press_first:
            self.state = PressState.press_second
            self.start_point = new_point
            self.end_point = self.start_point
            self.prev_diff = su.CVector3D()
            
            if self.copy_mode:
                self.do_copy()
            else:
                self.do_move_list()
            
            #self.view.setMouseTracking(True)
        elif self.state == PressState.press_second:
            self.state = PressState.press_first
            self.end_point = new_point
            self.copy_mode = False
            #self.view.model.mark_dirty()

    def on_left_button_up(self, pos):
        pass
    
    def compute_translate(self):
        diff = self.end_point - self.start_point
        trans = diff - self.prev_diff
        self.prev_diff = diff
        matrix = su.CMatrix()
        matrix.SetRow(3, trans);
        
        for e in self.move_list:
            if type(e) is su.SUComponentInstance:
                m1 = e.GetTransform()
                m2 = matrix.multiply(m1)
                e.SetTransform(m2)
            elif type(e) is su.CVertex:
                e.p = matrix.map(e.p)

    def on_mouse_move(self, pos, modifiers):
        #=======================
        # input_point
        new_point = self.do_input_inference(pos.x(), pos.y())

        if self.state == PressState.press_second:
            self.state = PressState.press_second
            self.end_point = new_point
            self.compute_translate()

            #print("end pos:", self.end_point)
    
    def on_ctrl_press(self):
        if self.copy_mode:
            self.copy_mode = False
            print("disable copy mode")
        else:
            self.copy_mode = True
            print("enable copy mode")

def print_matrix(m):
    for i in range(4):
        row = [m.get(i, j) for j in range(3)]
        print(row)
