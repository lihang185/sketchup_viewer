#include <tchar.h>
#include <assert.h>
#include <vector>
#include <set>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <map>
#include "model.h"
#include <windows.h>
#include <GL/GL.h>

#include <SketchUpAPI/sketchup.h>

//=====================
//  wstring
//
//=====================

std::wstring SUStringToSTLString(SUStringRef string)
{
	SUResult result;
	size_t string_len;
	size_t copy_len;
	std::wstring outstr;
	result = SUStringGetUTF16Length(string, &string_len);
	if (result == SU_ERROR_NONE) {
		outstr.resize(string_len);
		result = SUStringGetUTF16(string, string_len, (unichar*)outstr.data(), &copy_len);
		if (result == SU_ERROR_NONE) {
			return outstr;
		}
	}
	return outstr;
}

//=====================
//  CVector3D
//
//=====================
CVector3D CVector3D::operator*(double scale)
{
	CVector3D out;
	out.x = x * scale;
	out.y = y * scale;
	out.z = z * scale;
	return out;
}

CVector3D CVector3D::operator+(CVector3D& R)
{
	CVector3D out;
	out.x = x + R.x;
	out.y = y + R.y;
	out.z = z + R.z;
	return out;
}

CVector3D CVector3D::operator-(CVector3D& R)
{
	CVector3D out;
	out.x = x - R.x;
	out.y = y - R.y;
	out.z = z - R.z;
	return out;
}

CVector3D CVector3D::operator-()
{
	CVector3D out;
	out.x = -x;
	out.y = -y;
	out.z = -z;
	return out;
}

double CVector3D::DotProduct(CVector3D& R)
{
	return x * R.x + y * R.y + z * R.z;
}

CVector3D CVector3D::CrossProduct(CVector3D& R)
{
	CVector3D out;
	out.x = y * R.z - z * R.y;
	out.y = z * R.x - x * R.z;
	out.z = x * R.y - y * R.x;
	return out;
}

//=====================
//  CVector4D
//
//=====================
CPlane::CPlane(CVector3D& normal, CVector3D& orig)
{
	x = normal.x;
	y = normal.y;
	z = normal.z;
	w = -orig.DotProduct(normal);
}

CVector3D CPlane::GetNormal()
{
	return CVector3D(x, y, z);
}

double CPlane::IntersectWithRay(CVector3D& orig, CVector3D& dir)
{
	double dot_dir, dot_orig, s;

	dot_dir = x * dir.x + y * dir.y + z * dir.z;
	dot_orig = x * orig.x + y * orig.y + z * orig.z;

	s = (dot_orig + w) / -dot_dir;

	return s;
}

//=====================
//  CMatrix
//
//=====================
CMatrix::CMatrix()
{
	m[0][0] = 1.0;
	m[0][1] = 0.0;
	m[0][2] = 0.0;

	m[1][0] = 0.0;
	m[1][1] = 1.0;
	m[1][2] = 0.0;

	m[2][0] = 0.0;
	m[2][1] = 0.0;
	m[2][2] = 1.0;

	m[3][0] = 0.0;
	m[3][1] = 0.0;
	m[3][2] = 0.0;

	scale = 1.0;
	isIdentity = true;
	flags = true;
}


CVector3D CMatrix::GetAxis(int axis)
{
	CVector3D out;
	out.x = m[0][axis];
	out.y = m[1][axis];
	out.z = m[2][axis];
	return out;
}

void CMatrix::SetAxis(int axis, CVector3D v)
{
	m[0][axis] = v.x;
	m[1][axis] = v.y;
	m[2][axis] = v.z;
}

CVector3D CMatrix::GetRow(int row)
{
	CVector3D out;
	out.x = m[row][0];
	out.y = m[row][1];
	out.z = m[row][2];
	return out;
}


void CMatrix::SetRow(int row, CVector3D v)
{
	m[row][0] = v.x;
	m[row][1] = v.y;
	m[row][2] = v.z;
}

void CMatrix::SetScale(double _scale)
{
	scale = _scale;
}

CVector3D CMatrix::ProjectPoint(CVector3D& v)
{
	CVector3D out;
	out.x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[3][0];
	out.y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[3][1];
	out.z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[3][2];
	return out;
}


CMatrix CMatrix::multiply(CMatrix& R)
{
	CMatrix out;
	out.m[0][0] = m[0][0] * R.m[0][0] + m[0][1] * R.m[1][0] + m[0][2] * R.m[2][0];
	out.m[0][1] = m[0][0] * R.m[0][1] + m[0][1] * R.m[1][1] + m[0][2] * R.m[2][1];
	out.m[0][2] = m[0][0] * R.m[0][2] + m[0][1] * R.m[1][2] + m[0][2] * R.m[2][2];

	out.m[1][0] = m[1][0] * R.m[0][0] + m[1][1] * R.m[1][0] + m[1][2] * R.m[2][0];
	out.m[1][1] = m[1][0] * R.m[0][1] + m[1][1] * R.m[1][1] + m[1][2] * R.m[2][1];
	out.m[1][2] = m[1][0] * R.m[0][2] + m[1][1] * R.m[1][2] + m[1][2] * R.m[2][2];

	out.m[2][0] = m[2][0] * R.m[0][0] + m[2][1] * R.m[1][0] + m[2][2] * R.m[2][0];
	out.m[2][1] = m[2][0] * R.m[0][1] + m[2][1] * R.m[1][1] + m[2][2] * R.m[2][1];
	out.m[2][2] = m[2][0] * R.m[0][2] + m[2][1] * R.m[1][2] + m[2][2] * R.m[2][2];

	out.m[3][0] = R.m[3][0] * m[0][0] + R.m[3][1] * m[0][1] + R.m[3][2] * m[0][2] + m[3][0] / R.scale;
	out.m[3][1] = R.m[3][0] * m[1][0] + R.m[3][1] * m[1][1] + R.m[3][2] * m[1][2] + m[3][1] / R.scale;
	out.m[3][2] = R.m[3][0] * m[2][0] + R.m[3][1] * m[2][1] + R.m[3][2] * m[2][2] + m[3][2] / R.scale;
	out.scale = scale * R.scale;
	out.isIdentity = false;
	return out;
}

void CMatrix::gl_multiply_matrix()
{
	double data[16];

	data[0] = m[0][0]; data[1] = m[1][0]; data[2] = m[2][0]; data[3] = 0;
	data[4] = m[0][1]; data[5] = m[1][1]; data[6] = m[2][1]; data[7] = 0;
	data[8] = m[0][2]; data[9] = m[1][2]; data[10] = m[2][2]; data[11] = 0;
	data[12] = m[3][0]; data[13] = m[3][1]; data[14] = m[3][2]; data[15] = scale;

	glMultMatrixd(data);
}

//=====================
//  SUEntity
//
//=====================
int SUEntity::GetType()
{
	SURefType rtype;

	rtype = SUEntityGetType(SUAPI(this));
	if (rtype == SURefType_Edge) {
		return 16;
	}
	else if (rtype == SURefType_Face) {
		return 18;
	}
	return 0;

}

int SUEntity::GetID()
{
	int id=0;
	SUEntityGetID(SUAPI(this), &id);
	return id;
}


int SUEntity::GetNumAttributeDictionaries()
{
	size_t count = 0;
	SUEntityGetNumAttributeDictionaries(SUAPI(this), &count);
	return count;
}

std::vector<SUAttributeDictionary*> SUEntity::GetAttributeDictionaries()
{
	size_t count = 0;
	SUEntityGetNumAttributeDictionaries(SUAPI(this), &count);

	std::vector<SUAttributeDictionary*> dicts;

	if (count > 0) {
		dicts.resize(count);
		size_t copy_number;
		SUEntityGetAttributeDictionaries(SUAPI(this), count, (SUAttributeDictionaryRef*)dicts.data(), &copy_number);
	}
	return dicts;
}


//=====================
//  SUAttributeDictionary
//
//=====================
std::wstring SUAttributeDictionary::GetName()
{
	SUResult result;
	SUStringRef name = SU_INVALID;

	std::wstring out_str;

	result = SUAttributeDictionaryGetName(SUAPI(this), &name);
	if (result == SU_ERROR_NONE) {
		out_str = SUStringToSTLString(name);
	}
	return out_str;
}

int SUAttributeDictionary::GetNumKeys()
{
	size_t count = 0;
	SUAttributeDictionaryGetNumKeys(SUAPI(this), &count);
	return count;
}

std::vector<std::wstring> SUAttributeDictionary::GetKeys()
{
	size_t count = 0;
	SUAttributeDictionaryGetNumKeys(SUAPI(this), &count);
	std::vector<std::wstring> keys;

	if (count > 0) {
		keys.resize(count);
		size_t copy_number;
		SUAttributeDictionaryGetKeys(SUAPI(this), count, (SUStringRef*)keys.data(), &copy_number);
	}
	return keys;
}

//=====================
//  SUDrawingElement
//
//=====================
bool SUDrawingElement::GetHidden()
{
	bool value;
	SUDrawingElementGetHidden(SUAPI(this), &value);
	return value;
}

//=====================
//  SUVertex
//
//=====================
CVector3D SUVertex::GetPosition()
{
	SUPoint3D pos;
	SUVertexGetPosition(SUAPI(this), &pos);
	return CVector3D(pos.x, pos.y, pos.z);
}

//=====================
//  SUEdge
//
//=====================
SUVertex* SUEdge::GetStartVertex()
{
	SUVertexRef vertex = SU_INVALID;
	SUEdgeGetStartVertex(SUAPI(this), &vertex);
	return cast_SUVertex(vertex);
}

SUVertex* SUEdge::GetEndVertex()
{
	SUVertexRef vertex = SU_INVALID;
	SUEdgeGetEndVertex(SUAPI(this), &vertex);
	return cast_SUVertex(vertex);
}

bool SUEdge::GetSoft()
{
	bool value;
	SUEdgeGetSoft(SUAPI(this), &value);
	return value;
}

bool SUEdge::GetSmooth()
{
	bool value;
	SUEdgeGetSmooth(SUAPI(this), &value);
	return value;
}

//=====================
//  SUEdgeUse
//
//=====================
SUEdge* SUEdgeUse::GetEdge()
{
	SUEdgeRef edge = SU_INVALID;
	SUEdgeUseGetEdge(SUAPI(this),&edge);
	return cast_SUEdge(edge);
}

SUVertex* SUEdgeUse::GetStartVertex()
{
	SUVertexRef vertex = SU_INVALID;
	SUEdgeUseGetStartVertex(SUAPI(this), &vertex);
	return cast_SUVertex(vertex);
}

CVector3D SUEdgeUse::GetStartVertexNormal()
{
	SUVector3D n;
	SUEdgeUseGetStartVertexNormal(SUAPI(this), &n);
	return CVector3D(n.x, n.y, n.z);
}


SUVertex* SUEdgeUse::GetEndVertex()
{
	SUVertexRef vertex = SU_INVALID;
	SUEdgeUseGetEndVertex(SUAPI(this), &vertex);
	return cast_SUVertex(vertex);
}


CVector3D SUEdgeUse::GetEndVertexNormal()
{
	SUVector3D n;
	SUEdgeUseGetEndVertexNormal(SUAPI(this), &n);
	return CVector3D(n.x, n.y, n.z);
}

bool SUEdgeUse::IsReversed()
{
	bool value = false;
	SUEdgeUseIsReversed(SUAPI(this), &value);
	return value;
}


SUFace* SUEdgeUse::GetFace()
{
	SUFaceRef face = SU_INVALID;
	SUEdgeUseGetFace(SUAPI(this), &face);
	return cast_SUFace(face);
}

SULoop* SUEdgeUse::GetLoop()
{
	SULoopRef loop = SU_INVALID;
	SUEdgeUseGetLoop(SUAPI(this), &loop);
	return cast_SULoop(loop);
}

//=====================
//  SULoop
//
//=====================
int SULoop::GetNumVertices()
{
	size_t count = 0;
	SULoopGetNumVertices(SUAPI(this), &count);
	return (int)count;
}

std::vector<SUVertex*> SULoop::GetVertices()
{
	SUResult result;

	size_t count = 0;
	SULoopGetNumVertices(SUAPI(this), &count);

	std::vector<SUVertex*> vert_ls;
	if (count > 0) {
		vert_ls.resize(count);
		size_t copy_number = 0;
		result = SULoopGetVertices(SUAPI(this), count, (SUVertexRef*)vert_ls.data(), &copy_number);
		if (result == SU_ERROR_NONE) {
			return vert_ls;
		}
	}
	return vert_ls;
}

std::vector<SUEdge*> SULoop::GetEdges()
{
	SUResult result;

	size_t count = 0;
	SULoopGetNumVertices(SUAPI(this), &count);

	std::vector<SUEdge*> edge_ls;
	if (count > 0) {
		edge_ls.resize(count);
		size_t copy_number = 0;
		result = SULoopGetEdges(SUAPI(this), count, (SUEdgeRef*)edge_ls.data(), &copy_number);
		if (result == SU_ERROR_NONE) {
			return edge_ls;
		}
	}
	return edge_ls;
}

std::vector<SUEdgeUse*> SULoop::GetEdgeUses()
{
	SUResult result;

	size_t count = 0;
	SULoopGetNumVertices(SUAPI(this), &count);

	std::vector<SUEdgeUse*> edgeuse_ls;
	if (count > 0) {
		edgeuse_ls.resize(count);
		size_t copy_number=0;
		result = SULoopGetEdgeUses(SUAPI(this), count, (SUEdgeUseRef*)edgeuse_ls.data(),&copy_number);
		if (result == SU_ERROR_NONE) {
			return edgeuse_ls;
		}
	}
	return edgeuse_ls;
}

bool SULoop::IsOuterLoop()
{
	bool value = false;
	SULoopIsOuterLoop(SUAPI(this), &value);
	return value;
}

bool SULoop::IsConvex()
{
	bool value = false;
	SULoopIsConvex(SUAPI(this), &value);
	return value;
}

SUFace* SULoop::GetFace()
{
	SUResult result;

	SUFaceRef face = SU_INVALID;
	result = SULoopGetFace(SUAPI(this), &face);
	if (result == SU_ERROR_NONE) {
		return cast_SUFace(face);
	}
	return 0;
}


//=====================
//  SUFace
//
//=====================
SULoop* SUFace::GetOuterLoop()
{
	SULoopRef loop = SU_INVALID;
	SUFaceGetOuterLoop(SUAPI(this), &loop);
	return cast_SULoop(loop);
}

std::vector<SULoop*> SUFace::GetInnerLoops()
{
	size_t count = 0;
	SUFaceGetNumInnerLoops(SUAPI(this), &count);

	std::vector<SULoop*> loops;
	if (count > 0) {
		loops.resize(count);
		size_t copy_number;
		SUFaceGetInnerLoops(SUAPI(this), count, (SULoopRef*)loops.data(), &copy_number);
		assert(copy_number == count);
	}
	return loops;
}

CPlane SUFace::GetPlane()
{
	SUPlane3D plane;
	SUFaceGetPlane(SUAPI(this), &plane);
	return CPlane(plane.a, plane.b, plane.c, plane.d);
}

CVector3D SUFace::GetNormal()
{
	SUVector3D normal;
	SUFaceGetNormal(SUAPI(this), &normal);
	return CVector3D(normal.x, normal.y, normal.z);
}

SUMaterial* SUFace::GetFrontMaterial()
{
	SUResult result;
	SUMaterialRef material=SU_INVALID;

	result = SUFaceGetFrontMaterial(SUAPI(this),&material);
	if (result == SU_ERROR_NONE) {
		return (SUMaterial*)material.ptr;
	}
	return 0;
}

SUMaterial* SUFace::GetBackMaterial()
{
	SUResult result;
	SUMaterialRef material;

	result = SUFaceGetBackMaterial(SUAPI(this), &material);
	if (result == SU_ERROR_NONE) {
		return (SUMaterial*)material.ptr;
	}
	return 0;
}


void SUFace::Draw(CMatrix* matrix, SUComponentInstance* pm, TriangleMesh* triMesh)
{
	int num_tris;
	int id1, id2, id3;
	CVector3D p1, p2, p3;
	CVector3D tv1, tv2, tv3;

	glBegin(GL_TRIANGLES);
	num_tris = (int)triMesh->GetNumVertexIndices() / 3;
	for (int i = 0; i < num_tris; i++) {
		id1 = triMesh->GetVertexIndex(i*3);
		id2 = triMesh->GetVertexIndex(i*3 + 1);
		id3 = triMesh->GetVertexIndex(i*3 + 2);

		p1 = triMesh->GetPoint(id1);
		p1 = matrix->ProjectPoint(p1);
		p2 = triMesh->GetPoint(id2);
		p2 = matrix->ProjectPoint(p2);
		p3 = triMesh->GetPoint(id3);
		p3 = matrix->ProjectPoint(p3);

		tv1 = triMesh->GetUV(id1);
		tv2 = triMesh->GetUV(id2);
		tv3 = triMesh->GetUV(id3);

		glTexCoord2d(tv1.x, tv1.y);
		glVertex3d(p1.x, p1.y, p1.z);
		glTexCoord2d(tv2.x, tv2.y);
		glVertex3d(p2.x, p2.y, p2.z);
		glTexCoord2d(tv3.x, tv3.y);
		glVertex3d(p3.x, p3.y, p3.z);
	}

	glEnd();
}

bool TriangleMesh::Build(SUFace* face, SUComponentInstance* inst)
{
	SUResult result;
	SUUVHelperRef uv_helper = SU_INVALID;
	SUMeshHelperRef meshHelper = SU_INVALID;
	SUTextureWriterRef textureWriter = SU_INVALID;
	SUMaterialRef mtl = SU_INVALID;
	long texture_id = 0;

	SUFaceRef face_p = SUAPI(face);

	result = SUFaceGetFrontMaterial(face_p, &mtl);
	if (result == SU_ERROR_NONE || inst == 0) {
		result = SUFaceGetUVHelper(face_p, true, false, SU_INVALID, &uv_helper);
		if (result != SU_ERROR_NONE) {
			return false;
		}

		result = SUMeshHelperCreateWithUVHelper(&meshHelper, face_p, uv_helper);
		if (result != SU_ERROR_NONE) {
			return false;
		}
	}
	else {
		result = SUTextureWriterCreate(&textureWriter);
		if (result != SU_ERROR_NONE) {
			return false;
		}

		result = SUTextureWriterLoadEntity(textureWriter, SUAPI(inst), &texture_id);
		if (result != SU_ERROR_NONE) {
			return false;
		}

		result = SUFaceGetUVHelperWithTextureHandle(face_p, true, false, textureWriter, 1, &uv_helper);
		if (result != SU_ERROR_NONE) {
			return false;
		}

		result = SUMeshHelperCreateWithUVHelper(&meshHelper, face_p, uv_helper);
		if (result != SU_ERROR_NONE) {
			return false;
		}
	}

	
	size_t num_triangles;
	size_t num_vertices;
	
	result = SUMeshHelperGetNumTriangles(meshHelper, &num_triangles);
	if (result != SU_ERROR_NONE) {
		return false;
	}

	result = SUMeshHelperGetNumVertices(meshHelper, &num_vertices);
	if (result != SU_ERROR_NONE) {
		return false;
	}

	//=================
	// 初始化数组
	indices.resize(num_triangles * 3);
	points.resize(num_vertices);
	normals.resize(num_vertices);
	uvs.resize(num_vertices);

	size_t out_count;

	result = SUMeshHelperGetVertexIndices(meshHelper, num_triangles * 3, (size_t*)indices.data(), &out_count);
	if (result != SU_ERROR_NONE) {
		return false;
	}

	result = SUMeshHelperGetVertices(meshHelper, num_vertices, (SUPoint3D*)points.data(), &out_count);
	if (result != SU_ERROR_NONE) {
		return false;
	}

	result = SUMeshHelperGetNormals(meshHelper, num_vertices, (SUVector3D*)normals.data(), &out_count);
	if (result != SU_ERROR_NONE) {
		return false;
	}

	result = SUMeshHelperGetFrontSTQCoords(meshHelper, num_vertices, (SUPoint3D*)uvs.data(), &out_count);
	if (result != SU_ERROR_NONE) {
		return false;
	}

	ok = true;

	return true;
}

int TriangleMesh::GetNumVertices()
{
	return (int)points.size();
}

int TriangleMesh::GetNumVertexIndices()
{
	return (int)indices.size();
}

int TriangleMesh::GetVertexIndex(int idx)
{
	return (int)indices[idx];
}

CVector3D TriangleMesh::GetPoint(int idx)
{
	return points[idx];
}

CVector3D TriangleMesh::GetNormal(int idx)
{
	return normals[idx];
}

CVector3D TriangleMesh::GetUV(int idx)
{
	return uvs[idx];
}


//=====================
//  SUMaterial
//
//=====================

SUMaterial* SUMaterial::Create()
{
	SUResult result;
	SUMaterialRef material = SU_INVALID;

	result = SUMaterialCreate(&material);
	if (result == SU_ERROR_NONE) {

		return (SUMaterial*)material.ptr;
	}
	return 0;
}

std::wstring SUMaterial::GetName()
{
	SUResult result;
	SUStringRef name = SU_INVALID;

	std::wstring out_str;

	result = SUMaterialGetName(SUAPI(this), &name);
	if (result == SU_ERROR_NONE) {
		out_str = SUStringToSTLString(name);
	}
	return out_str;
}

SUTexture* SUMaterial::GetTexture()
{
	SUResult result;
	SUTextureRef texture;

	result = SUMaterialGetTexture(SUAPI(this), &texture);
	if (result == SU_ERROR_NONE) {
		return (SUTexture*)texture.ptr;
	}
	return 0;
}

CVector3D SUMaterial::GetColor()
{
	SUResult result;
	SUColor color;

	result = SUMaterialGetColor(SUAPI(this), &color);
	if (result == SU_ERROR_NONE) {
		CVector3D out;
		out.x = (double)color.red / 255;
		out.y = (double)color.green / 255;
		out.z = (double)color.blue / 255;
		return out;
	}
	return CVector3D();
}


bool SUMaterial::GetUseOpacity()
{
	bool value;
	SUMaterialGetUseOpacity(SUAPI(this), &value);
	return value;

	
}

double SUMaterial::GetOpacity()
{
	double value;
	SUMaterialGetOpacity(SUAPI(this), &value);
	return value;
}

//=====================
//  SUTexture
//
//=====================
std::wstring SUTexture::GetFileName()
{
	SUResult result;
	SUStringRef name = SU_INVALID;
	SUStringCreate(&name);

	std::wstring out_str;

	result = SUTextureGetFileName(SUAPI(this), &name);
	if (result == SU_ERROR_NONE) {
		out_str = SUStringToSTLString(name);
		return out_str;
	}
	return out_str;
}

double SUTexture::GetScaleU()
{
	SUResult result;
	double u_scale, v_scale;
	size_t width, height;

	result = SUTextureGetDimensions(SUAPI(this), &width, &height, &u_scale, &v_scale);
	if (result == SU_ERROR_NONE) {
		return u_scale;
	}
	return 1.0;
}

double SUTexture::GetScaleV()
{
	SUResult result;
	double u_scale, v_scale;
	size_t width, height;

	result = SUTextureGetDimensions(SUAPI(this), &width, &height, &u_scale, &v_scale);
	if (result == SU_ERROR_NONE) {
		return v_scale;
	}
	return 1.0;
}

bool SUTexture::WriteToFile(std::string filepath)
{
	SUResult result;

	result = SUTextureWriteToFile(SUAPI(this), filepath.c_str());
	if (result == SU_ERROR_NONE) {
		return true;
	}
	return false;
}

int SUTexture::GetImageDataSize()
{
	SUResult result;
	size_t data_size = 0;
	size_t bits_per_pixel = 0;


	SUImageRepRef image = SU_INVALID;
	SUImageRepCreate(&image);

	result = SUTextureGetImageRep(SUAPI(this), &image);

	if (result == SU_ERROR_NONE) {
		SUImageRepGetDataSize(image, &data_size, &bits_per_pixel);
	}

	SUImageRepRelease(&image);
	return (int)data_size;
}

std::vector<char> SUTexture::GetImageData()
{
	SUResult result;
	size_t data_size = 0;
	size_t bits_per_pixel = 0;
	std::vector<char> data;

	SUImageRepRef image = SU_INVALID;

	SUImageRepCreate(&image);

	result = SUTextureGetImageRep(SUAPI(this), &image);
	if (result == SU_ERROR_NONE) {
		SUImageRepGetDataSize(image, &data_size, &bits_per_pixel);
		data.resize(data_size);
		SUImageRepGetData(image, data_size, (SUByte*)data.data());
	}

	SUImageRepRelease(&image);

	return data;
}

//=====================
// SUEntities
//
//=====================
SUEntityArrayIterator::~SUEntityArrayIterator()
{
}

bool SUEntityArrayIterator::next(SUEntity** out)
{
	int count = (int)seq.size();
	if (index < count) {
		*out = seq[index];
		++index;
		return true;
	}
	else {
		return false;
	}
}

int SUEntities::GetNumEdges()
{
	SUResult result;
	size_t count;

	result = SUEntitiesGetNumEdges(SUAPI(this), false, &count);
	if (result == SU_ERROR_NONE) {
		return (int)count;
	}
	return 0;
}


int SUEntities::GetNumFaces()
{
	SUResult result;
	size_t count;

	result = SUEntitiesGetNumFaces(SUAPI(this), &count);
	if (result == SU_ERROR_NONE) {
		return (int)count;
	}
	return 0;
}

int SUEntities::GetNumGroups()
{
	SUResult result;
	size_t count;

	result = SUEntitiesGetNumGroups(SUAPI(this), &count);
	if (result == SU_ERROR_NONE) {
		return (int)count;
	}
	return 0;
}

int SUEntities::GetNumInstances()
{
	SUResult result;
	size_t count;

	result = SUEntitiesGetNumInstances(SUAPI(this), &count);
	if (result == SU_ERROR_NONE) {
		return (int)count;
	}
	return 0;
}

std::vector<SUEdge*> SUEntities::GetEdges()
{
	SUResult result;
	size_t copy_number;

	int number = GetNumEdges();
	if (!number) {
		return std::vector<SUEdge*>();
	}

	std::vector<SUEdge*> list1;
	list1.resize(number);

	result = SUEntitiesGetEdges(SUAPI(this), false, number, (SUEdgeRef*)list1.data(), &copy_number);
	if (result == SU_ERROR_NONE) {
		return list1;
	}
	return std::vector<SUEdge*>();
}

std::vector<SUFace*> SUEntities::GetFaces()
{
	SUResult result;
	size_t copy_number;

	int number = GetNumFaces();
	if (!number) {
		return std::vector<SUFace*>();
	}

	std::vector<SUFace*> list1;
	list1.resize(number);

	result = SUEntitiesGetFaces(SUAPI(this), number, (SUFaceRef*)list1.data(), &copy_number);
	if (result == SU_ERROR_NONE) {
		return list1;
	}
	return std::vector<SUFace*>();
}

std::vector<SUComponentInstance*> SUEntities::GetGroups()
{
	SUResult result;
	size_t copy_number;

	int number = GetNumGroups();
	if (!number) {
		return std::vector<SUComponentInstance*>();
	}

	std::vector<SUComponentInstance*> list1;
	list1.resize(number);

	result = SUEntitiesGetGroups(SUAPI(this), number, (SUGroupRef*)list1.data(), &copy_number);
	if (result == SU_ERROR_NONE) {
		return list1;
	}
	return std::vector<SUComponentInstance*>();
}

std::vector<SUComponentInstance*> SUEntities::GetInstances()
{
	SUResult result;
	size_t copy_number;

	int number = GetNumInstances();
	if (!number) {
		return std::vector<SUComponentInstance*>();
	}

	std::vector<SUComponentInstance*> list1;
	list1.resize(number);

	result = SUEntitiesGetInstances(SUAPI(this), number, (SUComponentInstanceRef*)list1.data(), &copy_number);
	if (result == SU_ERROR_NONE) {
		return list1;
	}
	return std::vector<SUComponentInstance*>();
}

bool SUEntities::AddEdge(SUEdge* edge)
{
	SUResult result;

	SUEdgeRef edges[] = { SUAPI(edge) };

	result = SUEntitiesAddEdges(SUAPI(this), 1, edges);
	if (result == SU_ERROR_NONE) {
		return true;
	}
	return false;
}

bool SUEntities::AddFace(SUFace* face)
{
	SUResult result;

	SUFaceRef faces[] = { SUAPI(face) };

	result = SUEntitiesAddFaces(SUAPI(this), 1, faces);
	if (result == SU_ERROR_NONE) {
		return true;
	}
	return false;
}

bool SUEntities::AddInstance(SUComponentInstance* inst)
{
	SUResult result;
	SUStringRef name = SU_INVALID;

	SUStringCreate(&name);
	result = SUEntitiesAddInstance(SUAPI(this), SUAPI(inst), 0);
	if (result == SU_ERROR_NONE) {
		return true;
	}
	return false;
}

SUEntityIterator* SUEntities::EnumEdges()
{
	SUResult result;
	size_t out_count;

	int number = GetNumEdges();
	if( !number )
		return new SUEntityArrayIterator();

	SUEntityArrayIterator* iter = new SUEntityArrayIterator();
	iter->seq.resize(number);

	result = SUEntitiesGetEdges(SUAPI(this), false, number, (SUEdgeRef*)iter->seq.data(), &out_count);
	if (result == SU_ERROR_NONE) {
		return (SUEntityIterator*)iter;
	}
	return 0;
}

SUEntityIterator* SUEntities::EnumFaces()
{
	SUResult result;
	size_t out_count;

	int number = GetNumFaces();
	if (!number)
		return new SUEntityArrayIterator();

	SUEntityArrayIterator* iter = new SUEntityArrayIterator();
	iter->seq.resize(number);

	result = SUEntitiesGetFaces(SUAPI(this), number, (SUFaceRef*)iter->seq.data(), &out_count);
	if (result == SU_ERROR_NONE) {
		return (SUEntityIterator*)iter;
	}
	return 0;
}

//=====================
// SUComponentDefinition
//
//=====================
SUComponentDefinition* SUComponentDefinition::Create()
{
	SUComponentDefinitionRef comp = SU_INVALID;
	SUResult result = SUComponentDefinitionCreate(&comp);
	if (result == SU_ERROR_NONE) {
		return (SUComponentDefinition*)comp.ptr;
	}
	return 0;
}

SUEntities* SUComponentDefinition::GetEntities()
{
	SUResult result;

	SUEntitiesRef entities = SU_INVALID;

	result = SUComponentDefinitionGetEntities(SUAPI(this), &entities);
	if (result == SU_ERROR_NONE) {
		return (SUEntities*)entities.ptr;
	}
	return 0;
}

std::wstring SUComponentDefinition::GetName()
{
	SUResult result;

	SUStringRef name = SU_INVALID;

	result = SUComponentDefinitionGetName(SUAPI(this), &name);
	if (result == SU_ERROR_NONE) {
		return SUStringToSTLString(name);
	}
	return std::wstring();
}

std::wstring SUComponentDefinition::GetDescription()
{
	SUResult result;

	SUStringRef desc = SU_INVALID;

	result = SUComponentDefinitionGetDescription(SUAPI(this), &desc);
	if (result == SU_ERROR_NONE) {
		return SUStringToSTLString(desc);
	}
	return std::wstring();
}

SUComponentInstance* SUComponentDefinition::CreateInstance()
{
	SUResult result;
	SUComponentInstanceRef inst = SU_INVALID;

	result = SUComponentDefinitionCreateInstance(SUAPI(this), &inst);
	if (result == SU_ERROR_NONE) {
		return (SUComponentInstance*)inst.ptr;
	}
	return 0;
}


bool SUComponentDefinition::IsInternal()
{
	SUResult result;

	bool is_internal;

	result = SUComponentDefinitionIsInternal(SUAPI(this), &is_internal);
	if (result == SU_ERROR_NONE) {
		return is_internal;
	}
	return false;
}

std::wstring SUComponentDefinition::GetPath()
{
	SUResult result;

	SUStringRef path = SU_INVALID;

	result = SUComponentDefinitionGetPath(SUAPI(this), &path);
	if (result == SU_ERROR_NONE) {
		return SUStringToSTLString(path);
	}
	return std::wstring();
}


//=====================
// SUComponentInstance
//
//=====================
SUComponentDefinition* SUComponentInstance::GetDefinition()
{
	SUResult result;

	SUComponentDefinitionRef comp_def;

	result = SUComponentInstanceGetDefinition(SUAPI(this), &comp_def);
	if (result == SU_ERROR_NONE) {
		return (SUComponentDefinition*)comp_def.ptr;
	}
	return 0;
}

CMatrix SUComponentInstance::GetTransform()
{
	SUResult result;

	SUTransformation transform;

	result = SUComponentInstanceGetTransform(SUAPI(this), &transform);
	if (result == SU_ERROR_NONE) {
		bool is_identity;
		SUTransformationIsIdentity(&transform, &is_identity);
		if(is_identity)
			return CMatrix();
		CMatrix m;
		m.SetAxis(0, CVector3D(transform.values[0], transform.values[1], transform.values[2]));
		m.SetAxis(1, CVector3D(transform.values[4], transform.values[5], transform.values[6]));
		m.SetAxis(2, CVector3D(transform.values[8], transform.values[9], transform.values[10]));
		m.SetRow(3, CVector3D(transform.values[12], transform.values[13], transform.values[14]));
		m.SetScale(transform.values[15]);
		return m;
	}
	return CMatrix();
}

void SUComponentInstance::SetTransform(CMatrix& m)
{
	SUResult result;

	SUTransformation transform;

	CVector3D xaxis, yaxis, zaxis, orig;
	xaxis = m.GetAxis(0);
	yaxis = m.GetAxis(1);
	zaxis = m.GetAxis(2);
	orig = m.GetRow(3);

	transform.values[0] = xaxis.x;
	transform.values[1] = xaxis.y;
	transform.values[2] = xaxis.z;
	transform.values[3] = 0;
	transform.values[4] = yaxis.x;
	transform.values[5] = yaxis.y;
	transform.values[6] = yaxis.z;
	transform.values[7] = 0;
	transform.values[8] = zaxis.x;
	transform.values[9] = zaxis.y;
	transform.values[10] = zaxis.z;
	transform.values[11] = 0;
	transform.values[12] = orig.x;
	transform.values[13] = orig.y;
	transform.values[14] = orig.z;
	transform.values[15] = m.scale;

	result = SUComponentInstanceSetTransform(SUAPI(this), &transform);
}

SUMaterial* SUComponentInstance::GetMaterial()
{
	SUResult result;

	SUMaterialRef material;

	SUDrawingElementRef draw_ele = SUComponentInstanceToDrawingElement(SUAPI(this));

	result = SUDrawingElementGetMaterial(draw_ele, &material);
	if (result == SU_ERROR_NONE) {
		return (SUMaterial*)material.ptr;
	}
	return 0;
}


//=====================
// SUModel
//
//=====================
SUModel* SUModel::LoadFromFile(std::string file_path)
{
	SUResult result;

	SUModelRef model = SU_INVALID;

	result = SUModelCreateFromFile(&model, file_path.c_str());
	
	if (result == SU_ERROR_NONE) {
		return (SUModel*)model.ptr;
	}
	return 0;
}


bool SUModel::SaveToFile(std::string& filepath)
{
	SUResult result;
	result = SUModelSaveToFile(SUAPI(this), filepath.c_str());
	if (result == SU_ERROR_NONE) {
		return true;
	}
	return false;
}

void SUModel::Release()
{
	SUModelRef model = SUAPI(this);
	SUModelRelease(&model);

	
}

SUEntities* SUModel::GetEntities()
{
	SUResult result;

	SUEntitiesRef entities = SU_INVALID;

	result = SUModelGetEntities(SUAPI(this),&entities);

	if (result == SU_ERROR_NONE) {
		return (SUEntities*)entities.ptr;
	}
	return 0;
}

std::string SUModel::GetName()
{
	return std::string("haha");
}

std::vector<SUMaterial*> SUModel::GetMaterialList()
{
	SUResult result;

	size_t num_materials;
	result = SUModelGetNumMaterials(SUAPI(this), &num_materials);

	std::vector<SUMaterial*> material_list(num_materials);

	size_t copy_count;
	result = SUModelGetMaterials(SUAPI(this), num_materials, (SUMaterialRef*)material_list.data(), &copy_count);

	if (result == SU_ERROR_NONE) {
		return material_list;
	}
	return std::vector<SUMaterial*>();
}

std::vector<SUComponentDefinition*> SUModel::GetComponentDefinitionList()
{
	SUResult result;

	size_t number;
	result = SUModelGetNumComponentDefinitions(SUAPI(this), &number);

	std::vector<SUComponentDefinition*> comp_list(number);

	size_t copy_count;
	result = SUModelGetComponentDefinitions(SUAPI(this), number, (SUComponentDefinitionRef*)comp_list.data(), &copy_count);

	if (result == SU_ERROR_NONE) {
		return comp_list;
	}
	return std::vector<SUComponentDefinition*>();
}


std::vector<SUComponentDefinition*> SUModel::GetGroupDefinitionList()
{
	SUResult result;

	size_t number;
	result = SUModelGetNumGroupDefinitions(SUAPI(this), &number);

	std::vector<SUComponentDefinition*> comp_list(number);

	size_t copy_count;
	result = SUModelGetGroupDefinitions(SUAPI(this), number, (SUComponentDefinitionRef*)comp_list.data(), &copy_count);

	if (result == SU_ERROR_NONE) {
		return comp_list;
	}
	return std::vector<SUComponentDefinition*>();
}

bool SUModel::AddComponentDefinitions(SUComponentDefinition*comp_def)
{
	SUResult result;

	SUComponentDefinitionRef comps[] = { SUAPI(comp_def) };

	result = SUModelAddComponentDefinitions(SUAPI(this), 1, comps);
	if (result == SU_ERROR_NONE) {
		return true;
	}
	return false;
}

bool SUModel::AddMaterial(SUMaterial* mat)
{
	SUResult result;
	SUMaterialRef mats[] = { SUAPI(mat) };
	result = SUModelAddMaterials(SUAPI(this), 1, mats);
	if (result == SU_ERROR_NONE) {
		return true;
	}
	return false;
}

