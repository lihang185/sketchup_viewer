DEBUG_INFO = False

from PySide2.QtGui import QImage, QOpenGLTexture

import os, sys
workdir = os.path.abspath(os.path.dirname(__file__))
data_path = os.path.abspath(
    os.path.join(os.path.dirname(__file__), "data")
)
def abspath(localpath):
    return os.path.join(data_path, localpath)

import su

from model_cache import VBOCache, DrawListCache


class Material:
    DefaultType = 0
    ColorType = 1
    TextureType = 2
    
    def __init__(self):
        self.m = None
        self.opacity = 1.0
        self.gl_tex_obj = None
        self.type = self.DefaultType
    
    def Bind(self, gl):
        if self.type == self.DefaultType:
            self.bindDefaultType(gl)
        elif self.type == self.ColorType:
            self.bindColorType(gl)
        elif self.type == self.TextureType:
            self.bindTextureType(gl)
        else:
            assert False

    def is_opacity(self):
        if self.opacity < 0.9:
            return True
        
        return False

    def bindDefaultType(self, gl):
        gl.glDisable(gl.GL_TEXTURE_2D)
        gl.glColor3f(1, 1, 1)
        gl.glMaterialfv(gl.GL_FRONT_AND_BACK, gl.GL_DIFFUSE, (1,1,1, 1.0) )
    
    def bindColorType(self,gl):
        gl.glDisable(gl.GL_TEXTURE_2D)
        color = self.m.GetColor()
        (r, g, b) = color.toTuple()
        
        if self.is_opacity():
            gl.glColor4f(r, g, b, self.opacity)
            gl.glMaterialfv(gl.GL_FRONT_AND_BACK, gl.GL_DIFFUSE, (r,g,b, self.opacity) )
        else:
            gl.glColor3f(r, g, b)
            gl.glMaterialfv(gl.GL_FRONT_AND_BACK, gl.GL_DIFFUSE, (r,g,b, 1.0) )
    
    def bindTextureType(self,gl):
        assert self.gl_tex_obj,  "bind texture is None"
        self.gl_tex_obj.bind()
        gl.glEnable(gl.GL_TEXTURE_2D)
        gl.glColor3f(1, 1, 1)
        gl.glMaterialfv(gl.GL_FRONT_AND_BACK, gl.GL_DIFFUSE, (1,1,1, 1.0) )
        # reset texture matrix
        gl.glMatrixMode(gl.GL_TEXTURE)
        gl.glLoadIdentity()
        gl.glMatrixMode(gl.GL_MODELVIEW)

    def LoadMaterial(self, m):
        self.m = m

        if m is None:
            self.type = self.DefaultType
        else:
            self.opacity = self.m.GetOpacity()
            self.type = self.ColorType
            texture = m.GetTexture()
            if texture:
                texname = texture.GetFileName();
                print(f"Load texture: {texname}")
                ok = texture.WriteToFile(texname)
                if ok:
                    imgpath = abspath(texname)
                    ok, self.gl_tex_obj = self.LoadImageFromFile(imgpath)
                    if ok:
                        self.type = self.TextureType
    
    ############
    # Material Binding
    # Lighting
    # 材质 & 灯光
    ############
    def LoadImageFromFile(self, filepath):
        fix_path = os.path.join(data_path, os.path.basename(filepath))
        try:
            with open(fix_path, 'rb') as hf:
                data = hf.read()
        except Exception as e:
            print(f"load texture {fix_path} exception, {e}")
            return False, None
        
        image = QImage()
        valid = image.loadFromData(data)
        if not valid:
            return False, None
            
        gl_tex_obj = QOpenGLTexture(image.mirrored())
        return True, gl_tex_obj
    
    def LoadImageFromDib(self, dib):
        data = dib.GetData()
        
        image = QImage()
        valid = image.loadFromData(data)
        if not valid:
            return False, None
            
        gl_tex_obj = QOpenGLTexture(image.mirrored())
        return True, gl_tex_obj

class Component:
    def __init__(self, comp):
        self.comp = comp
        self.dirty = True
        
        self.num_edges = comp.GetNumEdges()
        self.num_faces = comp.GetNumFaces()
        self.num_groups = comp.GetNumGroups()
        self.num_instances = comp.GetNumInstances()
        self.has_entities = (self.num_edges or self.num_faces)
        #
        self.instances = []
        
        self.clear_geom()
        self.model_cache = DrawListCache()
        self.model_cache_optional = DrawListCache, VBOCache
    
    def is_dirty(self):
        return self.dirty
    
    def mark(self):
        self.dirty = True
    
    def update_entities(self):
        self.edges = self.comp.GetEdges()
        self.faces = self.comp.GetFaces()
        self.entities = self.edges + self.faces
        
        self.entities_id_map = {}
        for e in self.entities:
           self.entities_id_map[e.GetID() ] = e
        
        self.update_children_instance()
    
    def update_children_instance(self):
        all_list = []
        groups = self.comp.GetGroups()
        insts = self.comp.GetInstances()
        all_list.extend(groups)
        all_list.extend(insts)
        self.instances = all_list
        
        for e in self.instances:
           self.entities_id_map[e.GetID() ] = e

    def clear_geom(self):
        self.dict_mats_normal = {}
        self.dict_mats_opacity = {}
        self.edge_group_ls = []
    
    def add_node(self, node, defaultMaterial):
        self.classify_face(node, defaultMaterial)
        self.add_edge_group(node)
    
    def classify_face(self, node, defaultMaterial):
        comp = node.comp
        
        # classify by material
        dict_mats = {}
        for e in comp.d.faces:
            #if e.GetHidden(): continue
            
            # triMesh
            if not hasattr(e, 'triMesh'):
                self.build_trimesh(e, node.pm)
            
            #
            pm2 = node.pm.GetMaterial() if node.pm else None
            mtl = e.GetFrontMaterial() or pm2

            ls = dict_mats.setdefault(mtl, [])
            ls.append(e)
        
        for mtl, list1 in dict_mats.items():
            if mtl:
                self.add_faces(list1, mtl, node)
            else:
                self.add_faces(list1, defaultMaterial, node)
    
    def build_trimesh(self, face, pm):
        face_has_mat = (face.GetFrontMaterial() != None)
        pm_has_texture = False
        if pm:
            mtl = pm.GetMaterial()
            if mtl and mtl.GetTexture():
                pm_has_texture = True
        
        triMesh = su.TriangleMesh()
        
        if face_has_mat or not pm_has_texture:
            ok = triMesh.Build(face, None)
        else:
            ok = triMesh.Build(face, pm)
        assert ok
        
        face.triMesh = triMesh

    def add_edge_group(self, node):
        edge_ls = node.comp.GetEdges()
        self.add_edges(edge_ls, node.m)

    def add_faces(self, face_ls, mtl, node):
        # 分类&过滤
        if mtl and mtl.d.is_opacity():
            target_dict = self.dict_mats_opacity
        else:
            target_dict = self.dict_mats_normal
            
        if mtl not in target_dict:
            target_dict[mtl] = []
        
        item = face_ls, node
        
        target_dict[mtl].append(item)
    
    def add_edges(self, edge_ls, m ):
        item = edge_ls, m
        self.edge_group_ls.append(item)

    def build(self, gl):
        self.model_cache.build(self.dict_mats_normal, self.dict_mats_opacity, self.edge_group_ls, gl)
        self.clear_geom()
        self.dirty = False

class InstancePath:
    def __init__(self, inst_path, comp, m, pm):
        self.is_top = ( not inst_path )
        self.inst_path = inst_path
        self.comp = comp
        self.m = m
        self.pm = pm

    def has_entities(self):
        return self.comp.d.has_entities

class SketchupModel:
    def __init__(self):
        self.model = None
        self.ok = False
        
        self.built = False
        self.built_dirty = False
        
        self.material_list = []
        self.comp_def_list = []
    
    def load(self, filename):
        model = su.SUModel.LoadFromFile(filename)
        if model:
            self.model = model
            self.init_model()
            self.ok = True
            return True
        else:
            return False

    def init_model(self):
        # default material
        self.defaultMaterial = su.SUMaterial.New()
        rm = Material()
        rm.LoadMaterial(None)
        self.defaultMaterial.d = rm
        
        for mtl in self.model.GetMaterialList():
            self.load_material(mtl)
        
        for comp in self.model.GetComponentDefinitionList():
            self.init_comp(comp)
            self.comp_def_list.append(comp)
        for comp in self.model.GetGroupDefinitionList():
            self.init_comp(comp)
            self.comp_def_list.append(comp)
        
        self.top_comp = self.model.GetEntities()
        self.init_comp(self.top_comp)
        
        print("ok")

    def load_material(self, mtl):
        if mtl not in self.material_list:
            name = mtl.GetName()
            print("Load material: ", name)
            rm = Material()
            rm.LoadMaterial(mtl)
            mtl.d = rm
            mtl.loaded = True
            self.material_list.append(mtl)
    
    def get_material_rt(self, mtl):
        if mtl:
            return mtl.d
        else:
            return self.defaultMaterial
    
    def init_comp(self, comp_def):
        data = Component(comp_def)
        data.update_entities()
        #data.defaultMaterial = self.defaultMaterial
        comp_def.d = data

    ########################
    # open comp
    # 
    ########################
    def get_opend_comp(self):
        return self.top_comp 
    
    def get_open_path(self):
        return []
    
    ########################
    # Recursive
    # 
    ########################
    def recursive_enum_inst_tree_no_filter(self, inst_path, comp, m, pm):
        node = InstancePath(inst_path, comp, m, pm)
        yield node
        #
        for inst2 in comp.d.instances:
            # test boundingbox
            matrix = inst2.GetTransform()
            m2 = m.multiply(matrix)
            if inst_path is None:
                inst_path2 = [inst2]
            else:
                inst_path2 = inst_path + [inst2]
            pm2 = inst2 if inst2.GetMaterial() else pm
            comp2 = inst2.GetDefinition()
            yield from self.recursive_enum_inst_tree_no_filter(inst_path2, comp2, m2, pm2)

    ########################
    # Draw
    # 
    ########################
    def draw(self, gl):
        top_comp = self.top_comp
        
        node = InstancePath([], top_comp, su.CMatrix(), None)
        if not self.built or self.built_dirty:
            self.build_activate_comp(node, gl)

        # 绘制面
        gl.glEnable(gl.GL_POLYGON_OFFSET_FILL)
        gl.glPolygonOffset(1, 1)
        gl.glEnableClientState(gl.GL_VERTEX_ARRAY)
        gl.glEnableClientState(gl.GL_TEXTURE_COORD_ARRAY)
        
        self.draw_activate_comp(top_comp, None, 0, gl)
        
        gl.glDisableClientState(gl.GL_VERTEX_ARRAY)
        gl.glDisableClientState(gl.GL_TEXTURE_COORD_ARRAY)

        gl.glDisable(gl.GL_POLYGON_OFFSET_FILL)

        # 绘制线
        gl.glColor3f(0, 0, 0)
        self.draw_activate_comp(top_comp, None, 1, gl)
        
        # 绘制半透明的面
        gl.glDisable(gl.GL_LIGHTING)
        gl.glEnable(gl.GL_BLEND)
        gl.glBlendFunc(gl.GL_SRC_ALPHA,gl.GL_ONE_MINUS_SRC_ALPHA)
        gl.glDepthMask(gl.GL_FALSE)
        
        self.draw_activate_comp(top_comp, None, 2, gl)
        
        gl.glDisable(gl.GL_BLEND)
        gl.glDepthMask(gl.GL_TRUE)
    
    def build_activate_comp(self, node, gl):
        # build this
        comp = node.comp
        comp.d.add_node(node, self.defaultMaterial)
        comp.d.build(gl)
        
        # build children
        for inst in comp.d.instances:
            self.build_sub_instance(inst, gl)
            
        self.built = True
        self.built_dirty = False
    
    def build_sub_instance(self, inst, gl):
        inst_path = [inst]
        comp = inst.GetDefinition()
        pm = inst if inst.GetMaterial() else None
        
        if not comp.d.is_dirty():
            return
        
        for node in self.recursive_enum_inst_tree_no_filter(inst_path, comp, su.CMatrix(), pm):
            comp.d.add_node(node, self.defaultMaterial)
        
        comp.d.build(gl)

    def draw_activate_comp(self, comp, pm, ipass, gl):
        model_cache = comp.d.model_cache

        # draw this
        if ipass == 0:
            model_cache.draw_normal(gl)
        elif ipass == 1:
            model_cache.draw_edge(gl)
        else:
            model_cache.draw_opacity(gl)
        
        #draw childrend
        for inst in comp.d.instances:
            comp2 = inst.GetDefinition()
            m = inst.GetTransform()
            gl.glPushMatrix()
            m.gl_multiply_matrix()
            
            mc2 = comp2.d.model_cache

            if ipass == 0:
                mc2.draw_normal(gl)
            elif ipass == 1:
                mc2.draw_edge(gl)
            else:
                mc2.draw_opacity(gl)
            gl.glPopMatrix()
    
    ########################
    # Pick
    # 
    ########################
    def update_selection(self, sel):
        self.selection_set = sel
    
    def pick(self, gl):
        comp = self.get_opend_comp()
        
        gl.glPushName(0)
        for e in comp.d.entities:
            if type(e) is su.SUEdge:
                self.pick_draw_edge(e, gl)
            elif type(e) is su.SUFace:
                self.pick_draw_face(e, gl)
        
        gl.glPopName()
    
    def pick_draw_edge(self, e, gl):
        if e.GetSoft():
            return
        id = e.GetID()
        gl.glLoadName(id)
        gl.glBegin(gl.GL_LINES)
        p1 = e.GetStartVertex().GetPosition()
        p2 = e.GetEndVertex().GetPosition()
        gl.glVertex3d(p1.x, p1.y, p1.z)
        gl.glVertex3d(p2.x, p2.y, p2.z)
        gl.glEnd()
        
    def pick_draw_face(self, face, gl):
        id = face.GetID()
        gl.glLoadName(id)
        
        triMesh = face.triMesh
            
        gl.glBegin(gl.GL_TRIANGLES)
        
        num_indices = triMesh.GetNumVertexIndices()
        num_triangles = int(num_indices/3)
        for j in range(num_triangles):
            v1 = triMesh.GetVertexIndex(j*3)
            v2 = triMesh.GetVertexIndex(j*3+1)
            v3 = triMesh.GetVertexIndex(j*3+2)
            
            p1 = triMesh.GetPoint(v1)
            p2 = triMesh.GetPoint(v2)
            p3 = triMesh.GetPoint(v3)
            
            gl.glVertex3d(p1.x, p1.y, p1.z)
            gl.glVertex3d(p2.x, p2.y, p2.z)
            gl.glVertex3d(p3.x, p3.y, p3.z)
        
        gl.glEnd()

