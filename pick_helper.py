DEBUG_INFO = False

import time
import su
import math

class EnumPickType:
    none = 100
    axis = 1
    vertex = 2
    intersection = 3
    guide_line = 4
    edge_center = 5
    edge = 6
    face = 7
    other_point = 8
    last_point_axis = 9
    ref_point_intersect = 10
    axis_plane = 11
    model_entity = 12

class SelectType:
    cross = 1
    inside = 2

class PickHelper:
    def __init__(self, view):
        self.view = view
        self.all_picked = []
        self.picked = []
        self.clip_near = 1e8
        self.clip_plane = None
        self.best = None
        self.best_face = None
        self.best_inst = None
        self.best_edge = None
        self.pick_volume = None
        self.ray = None

    class Item:
        def __init__(self, inst_path, e, near, far, is_inst ):
            self.inst_path = inst_path
            self.e = e
            self.near = near
            self.far = far
            self.m = None
            self.is_inst = is_inst
        
        def matrix(self):
            if self.m:
                return self.m

            matrix = su.CMatrix()
            for inst in self.inst_path:
                m = inst.GetTransform()
                matrix = matrix.multiply(m)
            
            self.m = matrix
            return matrix

    #===========================
    #
    #  Single Pick
    #
    #===========================
    def do_single_pick(self, x, y, aperture=9):
        self.select_type = SelectType.cross
        self.aperture = aperture

        self.view.pc.start(5)
        st = time.perf_counter()
        self.do_pick(x, y, aperture, aperture, filter)
        dt = time.perf_counter() - st
        self.view.pc.end(5)
        if DEBUG_INFO: print("do_pick_single: ", dt*1000)
    
    def parse_instance_path(self, names):
        comp = self.view.model.get_opend_comp()
        
        inst_path = []
        
        for e_id in names:
            e = comp.d.entities_id_map[e_id]
            inst_path.append(e)
            
            if type(e) is su.SUComponentInstance:
                comp = e.GetDefinition()
        
        e = inst_path.pop()
        
        return inst_path, e
    
    def do_pick(self, x, y, pick_width, pick_height, filter=None):
        self.view.beginSelect(x, y, pick_width, pick_height)
        #self.pick_volume = self.view.ComputePickVolume(x, y, pick_width, pick_height)
        self.ray = self.view.ComputeCameraRay(x, y)
        
        gl = self.view.gl
        model = self.view.model
        if not model:
            return

        # draw model
        model.pick(gl)

        hits = self.view.endSelect()
        
        if DEBUG_INFO:
            print("==== selection ===")
            for i, r in enumerate(hits):
                print(f"<{i}> {r.names} z:{r.near}->{r.far}")
            print("ok")
        
        #open_path = model.get_open_path()
        #open_depth = len(open_path)
        
        for r in hits:
            inst_path, e = self.parse_instance_path(r.names)
            is_inst = type(e) is su.SUComponentInstance
            
            item = PickHelper.Item(inst_path, e, r.near, r.far, is_inst)
            self.all_picked.append(item)
                
            if type(e) is su.SUFace or type(e) is su.SUComponentInstance:
                if r.far < self.clip_near:
                    self.clip_near = r.far
                    #self.clip_plane = e.GetPlane()

        for item in self.all_picked:
            #if filter and not filter(item.e):
            #    continue
            
            e = item.e
            
            if type(e) is su.SUEdge:
                if item.near < self.clip_near:
                    self.picked.append(item)
            elif type(e) is su.SUFace or type(e) is su.SUComponentInstance:
                if item.near <= self.clip_near:
                    self.add_to_best_face(item)
            #elif type(e) is su.CGuideLine:
            #    if item.near < self.clip_near:
            #        self.picked.append(item)
        
        self.picked.sort(key=lambda item:item.near)
            
        if self.best_face:
            self.picked.append(self.best_face)

        if self.picked:
            self.best = self.picked[0]

        return len(self.picked)

    def add_to_best_face(self, item):
        if not self.best_face:
            self.best_face = item
        if item.is_inst == False and self.best_face.is_inst == True:
            self.best_face = item
    
    def add_to_best_inst(self, item):
        if not self.best_inst:
            self.best_inst = item
        elif item.near < self.best_inst.near:
            self.best_inst = item
    


class InputPointFinder:
    def __init__(self, view):
        self.view = view
        self.snap_type = EnumPickType.none
        self.snap_point = su.CVector3D()
    
    def reset(self):
        self.aperture = 8
        self.snap_type = EnumPickType.none
        self.snap_point = su.CVector3D()
    
    def position(self):
        return self.snap_point
    
    def inference(self, x, y, filter=None):
        
        self.pick = PickHelper(self.view)
        self.pick.do_single_pick(x, y, 9, filter)

        if self.test_on_axis_plane(su.CVector3D()):
            if DEBUG_INFO: print("return on_axis_plane")
            assert self.snap_type != EnumPickType.none
            return True
        
        return False

    def test_on_axis_plane(self, last_point):
        
        if last_point is None:
            last_point = su.CVector3D(0, 0, 0)
        
        axis_idx = self.find_best_axis_plane_by_camera_forward()
        normal = self.get_axis_by_idx(axis_idx)
        orig = last_point
        plane = su.CVector4D(normal, orig)
        
        ray_start, ray_dir, ray_end = self.pick.ray
        s = plane.IntersectWithRay(ray_start, ray_dir)
        point = ray_start.MoveForward(ray_dir, s)
        self.snap_type = EnumPickType.axis_plane
        self.snap_point = point
        
        return True
    
    def find_best_axis_plane_by_camera_forward(self):
        forward = self.view.GetCameraForward()
        
        max = 0.0
        max_axis = 0
        
        for i in range(3):
            axis = self.get_axis_by_idx(i)
            dt = math.fabs(axis.DotProduct(forward))
            if dt > max:
                max = dt
                max_axis = i
        if max < 0.9848:
            return 2
        else:
            return max_axis
