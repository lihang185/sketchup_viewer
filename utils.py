DEBUG_INFO = False

class AutoBuilder:
    def __init__(self):
        self.gl_list = None
        self.dirty = True
      
    def __del__(self):
        self.clear()
    
    def clear(self):
        if self.gl_list:
            gl = self.gl
            if DEBUG_INFO:
                print("set_empty gl_list:", self.gl_list)
            gl.glDeleteLists(self.gl_list, 1)
            self.gl_list = None
            self.dirty = False
    
    def mark(self):
        self.dirty = True
    
    def draw(self, gl):
        if self.dirty:
            self.gl = gl
            return True
        else:
            if self.gl_list:
                gl.glCallList(self.gl_list)
            return False
    
    def __enter__(self):
        self.clear()
        gl = self.gl
        #-----
        self.gl_list = gl.glGenLists(1)        
        gl.glNewList(self.gl_list, gl.GL_COMPILE)
    
    def __exit__(self, exc_type, exc_value, traceback):
        gl = self.gl
        #-----
        gl.glEndList()
        self.dirty = False
        if DEBUG_INFO:
            print("build gl_list:", self.gl_list)
        #-----
        gl.glCallList(self.gl_list)


class DrawListBuilder:
    def __init__(self):
        self.gl_list = None
        self.dirty = True
      
    def __del__(self):
        self.clear()
    
    def is_dirty(self):
        return self.dirty

    def mark(self):
        self.dirty = True
    
    def clear(self):
        if self.gl_list:
            if DEBUG_INFO:
                print("clear gl_list:", self.gl_list)
            self.gl.glDeleteLists(self.gl_list, 1)
            self.gl_list = None
            self.dirty = False
    
    def begin(self, gl):
        self.gl = gl
        self.clear()
        #-----
        gl_list = gl.glGenLists(1)        
        gl.glNewList(gl_list, gl.GL_COMPILE)
        self.gl_list = gl_list
    
    def end(self):
        self.gl.glEndList()
        #-----
        self.dirty = False
        if DEBUG_INFO:
            print("build gl_list:", self.gl_list)

    def draw(self, gl):
        if self.gl_list:
            gl.glCallList(self.gl_list)

def draw_line( p1, p2, gl):
    gl.glBegin(gl.GL_LINES)
    gl.glVertex3d(p1.x, p1.y, p1.z )
    gl.glVertex3d(p2.x, p2.y, p2.z )
    gl.glEnd()

def draw_target_with_size(p, size, gl):
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

