DEBUG_INFO = False

import array
from OpenGL.arrays.vbo import VBO
from utils import DrawListBuilder



class DrawListCache:
    def __init__(self):
        self.model_cache_normal_face = DrawListBuilder()
        self.model_cache_opacity_face = DrawListBuilder()
        self.model_cache_edge = DrawListBuilder()
    
    def build(self, dict_face_normal, dict_face_opacity, edge_goups, gl):
        #-----
        # Faces
        self.model_cache_normal_face.begin(gl)
        self.build_faces(dict_face_normal, gl)
        self.model_cache_normal_face.end()
        #-----
        if dict_face_opacity:
            self.model_cache_opacity_face.begin(gl)
            self.build_faces(dict_face_opacity, gl)
            self.model_cache_opacity_face.end()
        #-----
        # Edges
        self.model_cache_edge.begin(gl)
        self.build_edges(edge_goups, gl)
        self.model_cache_edge.end()
    
    def is_mtl_opacity(self, mtl):
        if not mtl:
            return False
        
        opt = mtl.GetOpacity()
        if opt < 0.9:
            return True
        
        return False

    def build_faces(self, dict_mats, gl):
        for mtl, face_group_ls in dict_mats.items():
            if mtl:
                mtl.d.Bind(gl)
            else:
                self.defaultMaterial.Bind(gl)
            
            for face_ls, node in face_group_ls:
                for f in face_ls:
                    assert f.triMesh
                    self.draw_single_face(f, node.pm, node.m, gl)
                    #f.Draw(node.m, node.pm, f.triMesh)
        
    def build_edges(self, edge_goups, gl):
        for edge_ls, m in edge_goups:
            for edge in edge_ls:
                if not edge.GetSoft():
                    start = edge.GetStartVertex().GetPosition()
                    end = edge.GetEndVertex().GetPosition()
                    p1 = m.ProjectPoint(start)
                    p2 = m.ProjectPoint(end)
                    self.draw_line(p1, p2, gl)

    def draw_line(self, p1, p2, gl):
        gl.glBegin(gl.GL_LINES)
        gl.glVertex3d(p1.x, p1.y, p1.z )
        gl.glVertex3d(p2.x, p2.y, p2.z )
        gl.glEnd()

    def draw_normal(self, gl):
        self.model_cache_normal_face.draw(gl)
    
    def draw_edge(self, gl):
        self.model_cache_edge.draw(gl)
        
    def draw_opacity(self, gl):
        self.model_cache_opacity_face.draw(gl)

    def draw_single_face(self, face, pm, matrix, gl):
        triMesh = face.triMesh
            
        gl.glBegin(gl.GL_TRIANGLES)
        
        num_indices = triMesh.GetNumVertexIndices()
        num_triangles = int(num_indices/3)
        for j in range(num_triangles):
            v1 = triMesh.GetVertexIndex(j*3)
            v2 = triMesh.GetVertexIndex(j*3+1)
            v3 = triMesh.GetVertexIndex(j*3+2)
            
            p1 = triMesh.GetPoint(v1)
            p1 = matrix.ProjectPoint(p1)
            p2 = triMesh.GetPoint(v2)
            p2 = matrix.ProjectPoint(p2)
            p3 = triMesh.GetPoint(v3)
            p3 = matrix.ProjectPoint(p3)
            
            tv1 = triMesh.GetUV(v1)
            tv2 = triMesh.GetUV(v2)
            tv3 = triMesh.GetUV(v3)
            
            gl.glTexCoord2d(tv1.x, tv1.y)
            gl.glVertex3d(p1.x, p1.y, p1.z)
            gl.glTexCoord2d(tv2.x, tv2.y)
            gl.glVertex3d(p2.x, p2.y, p2.z)
            gl.glTexCoord2d(tv3.x, tv3.y)
            gl.glVertex3d(p3.x, p3.y, p3.z)
        
        gl.glEnd()


class VBOCache:
    def __init__(self):
        pass
    
    def build(self, dict_face_normal, dict_face_opacity, edge_goups, gl):
        self.build_faces(dict_face_normal, gl)
        self.build_edges(edge_goups, gl)

    def ar_as_bytes(self, ar):
        return ar.tobytes() if hasattr(ar, "tobytes") else ar.tostring()

    def build_faces(self, dict_face, gl):
        face_group = []
        
        for mtl, face_group_ls in dict_face.items():
            verts_count = 0
            indices_count = 0
            verts = array.array('f')
            indices = array.array('H')
            for face_ls, node in face_group_ls:
                for f in face_ls:
                    vs, ids, nv, ni = self.draw_single_face(f, node.pm, node.m, verts, verts_count, indices)
                    verts_count += nv
                    indices_count += ni
            
            if indices_count:
                vbo = VBO(self.ar_as_bytes(verts), target=gl.GL_ARRAY_BUFFER, usage=gl.GL_STATIC_DRAW )
                ebo = VBO(self.ar_as_bytes(indices), target=gl.GL_ELEMENT_ARRAY_BUFFER, usage=gl.GL_STATIC_DRAW )
                group = mtl, vbo, ebo, indices, indices_count
                face_group.append(group)
        
        self.face_group = face_group
    
    def build_edges(self, edge_goups, gl):
        data = array.array('f')
        num_edges = 0
        for edge_ls, m in edge_goups:
            for e in edge_ls:
                if not e.GetSoft():
                    p1 = e.GetStartVertex().GetPosition()
                    p1 = m.ProjectPoint(p1)
                    data.append(p1.x)
                    data.append(p1.y)
                    data.append(p1.z)
                    
                    p2 = e.GetEndVertex().GetPosition()
                    p2 = m.ProjectPoint(p2)
                    data.append(p2.x)
                    data.append(p2.y)
                    data.append(p2.z)
                    num_edges+=1

        self.edge_vbo = VBO(self.ar_as_bytes(data), target=gl.GL_ARRAY_BUFFER, usage=gl.GL_STATIC_DRAW )
        self.num_edges = num_edges

    def draw_normal(self, gl):
        #
        for mtl, vbo, ebo, indices, total in self.face_group:
            mtl.d.Bind(gl)
            
            vbo.bind()
            gl.glVertexPointer(3, gl.GL_FLOAT, 20, vbo)
            gl.glTexCoordPointer(2, gl.GL_FLOAT, 20, vbo+12)
            #gl.glDrawArrays(gl.GL_TRIANGLES, 0, 3)
            vbo.unbind()
            ebo.bind()
            gl.glDrawElements(gl.GL_TRIANGLES, total, gl.GL_UNSIGNED_SHORT, ebo)
            ebo.unbind()
            #gl.glDisableClientState(gl.GL_VERTEX_ARRAY)
            #gl.glDisableClientState(gl.GL_TEXTURE_COORD_ARRAY)
    
    def draw_edge(self, gl):
        if self.num_edges == 0:
            return
        vbo = self.edge_vbo
        gl.glEnableClientState(gl.GL_VERTEX_ARRAY)
        vbo.bind()
        gl.glVertexPointer(3, gl.GL_FLOAT, 0, vbo)
        gl.glDrawArrays(gl.GL_LINES, 0, self.num_edges*2)
        #gl.glDrawElements(gl.GL_LINES, 24,gl. GL_UNSIGNED_BYTE, ar_as_bytes(cIndices))
        vbo.unbind()
        gl.glDisableClientState(gl.GL_VERTEX_ARRAY)
        
    def draw_opacity(self, gl):
        pass


    def draw_single_face(self, face, pm, matrix, verts, start_index, indices):
        
        triMesh = face.triMesh
        
        def add_point(p):
            verts.append(p.x)
            verts.append(p.y)
            verts.append(p.z)
        def add_uv(v):
            verts.append(v.x)
            verts.append(v.y)
        def add_indices(v):
            indices.append(v+start_index)

        num_verts = triMesh.GetNumVertices()
        num_indices = triMesh.GetNumVertexIndices()
        
        for i in range(num_verts):
            p = triMesh.GetPoint(i)
            p = matrix.ProjectPoint(p)
            add_point(p)
            tc = triMesh.GetUV(i)
            add_uv(tc)
            
        for i in range(num_indices):
            id = triMesh.GetVertexIndex(i)
            add_indices(id)
        
        return verts, indices, num_verts, num_indices

