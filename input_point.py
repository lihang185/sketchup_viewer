DEBUG_INFO = False

import su
import math
from pick_helper import PickHelper, EnumPickType

class InputPoint:
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
        self.pick.do_single_pick(x, y, 9)

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
        plane = su.CPlane(normal, orig)
        
        ray_start, ray_dir, ray_end = self.pick.ray
        s = plane.IntersectWithRay(ray_start, ray_dir)
        point = ray_start+ ray_dir * s
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

    def get_axis_by_idx(self, idx):
        if idx == 0:
            return su.CVector3D(1, 0, 0)
        elif idx == 1:
            return su.CVector3D(0, 1, 0)
        elif idx == 2:
            return su.CVector3D(0, 0, 1)
        else:
            assert False
