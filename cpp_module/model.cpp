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

	SUEntityRef e;
	e.ptr = this;
	rtype = SUEntityGetType(e);
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

SUModel* SUEntity::GetModel()
{
	SUModelRef model = SU_INVALID;
	SUEntityGetModel(SUAPI(this), &model);
	return (SUModel*)model.ptr;
}

SUEntities* SUEntity::GetParentEntities()
{
	SUEntitiesRef comp = SU_INVALID;
	SUEntityGetParentEntities(SUAPI(this), &comp);
	return (SUEntities*)comp.ptr;
}

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
	SUResult result;

	SUPoint3D pos;

	SUVertexRef vertex;
	vertex.ptr = this;
	result = SUVertexGetPosition(vertex, &pos);
	if (result == SU_ERROR_NONE) {
		return CVector3D(pos.x,pos.y,pos.z);
	}
	return CVector3D(0,0,0);
}


//=====================
//  SUEdge
//
//=====================
SUVertex* SUEdge::GetStartVertex()
{
	SUResult result;

	SUVertexRef vertex = SU_INVALID;

	SUEdgeRef edge;
	edge.ptr = this;
	result = SUEdgeGetStartVertex(edge, &vertex);
	if (result == SU_ERROR_NONE) {
		return (SUVertex*)vertex.ptr;
	}
	return 0;
}

SUVertex* SUEdge::GetEndVertex()
{
	SUResult result;

	SUVertexRef vertex = SU_INVALID;

	SUEdgeRef edge;
	edge.ptr = this;
	result = SUEdgeGetEndVertex(edge, &vertex);
	if (result == SU_ERROR_NONE) {
		return (SUVertex*)vertex.ptr;
	}
	return 0;
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
//  SUFace
//
//=====================
CVector3D SUFace::GetNormal()
{
	SUResult result;
	SUVector3D normal;

	SUFaceRef face;
	face.ptr = this;
	result = SUFaceGetNormal(face, &normal);
	if (result == SU_ERROR_NONE) {
		return CVector3D(normal.x, normal.y, normal.z);
	}
	return CVector3D();

}

SUMaterial* SUFace::GetFrontMaterial()
{
	SUResult result;
	SUMaterialRef material=SU_INVALID;

	SUFaceRef face;
	face.ptr = this;
	result = SUFaceGetFrontMaterial(face,&material);
	if (result == SU_ERROR_NONE) {
		return (SUMaterial*)material.ptr;
	}
	return 0;
}

SUMaterial* SUFace::GetBackMaterial()
{
	SUResult result;
	SUMaterialRef material;

	SUFaceRef face;
	face.ptr = this;
	result = SUFaceGetBackMaterial(face, &material);
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
	SUStringCreate(&name);

	std::wstring out_str;

	SUMaterialRef material;
	material.ptr = this;
	result = SUMaterialGetName(material, &name);
	if (result == SU_ERROR_NONE) {
		out_str = SUStringToSTLString(name);
		return out_str;
	}
	return out_str;
}

SUTexture* SUMaterial::GetTexture()
{
	SUResult result;
	SUTextureRef texture;

	SUMaterialRef material;
	material.ptr = this;
	result = SUMaterialGetTexture(material, &texture);
	if (result == SU_ERROR_NONE) {
		return (SUTexture*)texture.ptr;
	}
	return 0;
}

CVector3D SUMaterial::GetColor()
{
	SUResult result;
	SUColor color;

	SUMaterialRef material;
	material.ptr = this;
	result = SUMaterialGetColor(material, &color);
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

	SUTextureRef texture;
	texture.ptr = this;
	result = SUTextureGetFileName(texture, &name);
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

	SUTextureRef texture;
	texture.ptr = this;
	result = SUTextureGetDimensions(texture, &width, &height, &u_scale, &v_scale);
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

	SUTextureRef texture;
	texture.ptr = this;
	result = SUTextureGetDimensions(texture, &width, &height, &u_scale, &v_scale);
	if (result == SU_ERROR_NONE) {
		return v_scale;
	}
	return 1.0;
}

bool SUTexture::WriteToFile(std::string filepath)
{
	SUResult result;

	SUTextureRef texture;
	texture.ptr = this;
	result = SUTextureWriteToFile(texture, filepath.c_str());
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

	SUTextureRef texture;
	texture.ptr = this;
	result = SUTextureGetImageRep(texture, &image);

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

	SUTextureRef texture;
	texture.ptr = this;
	result = SUTextureGetImageRep(texture, &image);
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

	SUEntitiesRef entities;
	entities.ptr = this;
	result = SUEntitiesGetNumEdges(entities, false, &count);
	if (result == SU_ERROR_NONE) {
		return (int)count;
	}
	return 0;
}


int SUEntities::GetNumFaces()
{
	SUResult result;
	size_t count;

	SUEntitiesRef entities;
	entities.ptr = this;
	result = SUEntitiesGetNumFaces(entities, &count);
	if (result == SU_ERROR_NONE) {
		return (int)count;
	}
	return 0;
}

int SUEntities::GetNumGroups()
{
	SUResult result;
	size_t count;

	SUEntitiesRef entities;
	entities.ptr = this;
	result = SUEntitiesGetNumGroups(entities, &count);
	if (result == SU_ERROR_NONE) {
		return (int)count;
	}
	return 0;
}

int SUEntities::GetNumInstances()
{
	SUResult result;
	size_t count;

	SUEntitiesRef entities;
	entities.ptr = this;
	result = SUEntitiesGetNumInstances(entities, &count);
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

	SUEntitiesRef entities;
	entities.ptr = this;
	result = SUEntitiesGetEdges(entities, false, number, (SUEdgeRef*)list1.data(), &copy_number);
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

	SUEntitiesRef entities;
	entities.ptr = this;
	result = SUEntitiesGetFaces(entities, number, (SUFaceRef*)list1.data(), &copy_number);
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

	SUEntitiesRef entities;
	entities.ptr = this;
	result = SUEntitiesGetGroups(entities, number, (SUGroupRef*)list1.data(), &copy_number);
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

	result = SUEntitiesAddInstance(SUAPI(this), SUAPI(inst), 0);
	if (result == SU_ERROR_NONE) {
		return true;
	}
	return false;
}

bool SUEntities::Erase(std::vector<SUEntity*> elements)
{
	SUResult result;
	SUStringRef name = SU_INVALID;

	result = SUEntitiesErase(SUAPI(this), elements.size(), (SUEntityRef*)elements.data());
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

	SUEntitiesRef entities;
	entities.ptr = this;
	result = SUEntitiesGetEdges(entities, false, number, (SUEdgeRef*)iter->seq.data(), &out_count);
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

	SUEntitiesRef entities;
	entities.ptr = this;
	result = SUEntitiesGetFaces(entities, number, (SUFaceRef*)iter->seq.data(), &out_count);
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

	SUComponentDefinitionRef comp_def;
	comp_def.ptr = this;
	result = SUComponentDefinitionGetEntities(comp_def, &entities);
	if (result == SU_ERROR_NONE) {
		return (SUEntities*)entities.ptr;
	}
	return 0;
}

std::wstring SUComponentDefinition::GetName()
{
	SUResult result;

	SUStringRef name;

	SUComponentDefinitionRef comp_def;
	comp_def.ptr = this;
	result = SUComponentDefinitionGetName(comp_def, &name);
	if (result == SU_ERROR_NONE) {
		return SUStringToSTLString(name);
	}
	return std::wstring();
}

std::wstring SUComponentDefinition::GetDescription()
{
	SUResult result;

	SUStringRef desc;

	SUComponentDefinitionRef comp_def;
	comp_def.ptr = this;
	result = SUComponentDefinitionGetDescription(comp_def, &desc);
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

	SUComponentDefinitionRef comp_def;
	comp_def.ptr = this;
	result = SUComponentDefinitionIsInternal(comp_def, &is_internal);
	if (result == SU_ERROR_NONE) {
		return is_internal;
	}
	return false;
}

std::wstring SUComponentDefinition::GetPath()
{
	SUResult result;

	SUStringRef path;

	SUComponentDefinitionRef comp_def;
	comp_def.ptr = this;
	result = SUComponentDefinitionGetPath(comp_def, &path);
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

	SUComponentInstanceRef instance;
	instance.ptr = this;
	result = SUComponentInstanceGetTransform(instance, &transform);
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

	SUComponentInstanceRef instance;
	instance.ptr = this;
	SUDrawingElementRef draw_ele = SUComponentInstanceToDrawingElement(instance);

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

	SUModelRef model;
	model.ptr = this;
	result = SUModelGetEntities(model,&entities);

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

	SUModelRef model;
	model.ptr = this;

	size_t num_materials;
	result = SUModelGetNumMaterials(model, &num_materials);

	std::vector<SUMaterial*> material_list(num_materials);

	size_t copy_count;
	result = SUModelGetMaterials(model, num_materials, (SUMaterialRef*)material_list.data(), &copy_count);

	if (result == SU_ERROR_NONE) {
		return material_list;
	}
	return std::vector<SUMaterial*>();
}

std::vector<SUComponentDefinition*> SUModel::GetComponentDefinitionList()
{
	SUResult result;

	SUModelRef model;
	model.ptr = this;

	size_t number;
	result = SUModelGetNumComponentDefinitions(model, &number);

	std::vector<SUComponentDefinition*> comp_list(number);

	size_t copy_count;
	result = SUModelGetComponentDefinitions(model, number, (SUComponentDefinitionRef*)comp_list.data(), &copy_count);

	if (result == SU_ERROR_NONE) {
		return comp_list;
	}
	return std::vector<SUComponentDefinition*>();
}


std::vector<SUComponentDefinition*> SUModel::GetGroupDefinitionList()
{
	SUResult result;

	SUModelRef model;
	model.ptr = this;

	size_t number;
	result = SUModelGetNumGroupDefinitions(model, &number);

	std::vector<SUComponentDefinition*> comp_list(number);

	size_t copy_count;
	result = SUModelGetGroupDefinitions(model, number, (SUComponentDefinitionRef*)comp_list.data(), &copy_count);

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

