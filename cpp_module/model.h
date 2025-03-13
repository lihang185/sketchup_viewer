#ifndef _MODEL_H
#define _MODEL_H

#include <tchar.h>
#include <vector>
#include <string>
#include <map>
#include <memory>

#define SUAPI(ptr) {ptr}

struct CVector2D {
	CVector2D() : x(0), y(0) {}
	CVector2D(double ix, double iy) : x(ix), y(iy) {}

	double x;
	double y;
};

struct CVector3D {
	CVector3D() : x(0), y(0), z(0) {}
	CVector3D(double ix, double iy, double iz) : x(ix), y(iy), z(iz) {}

	double x;
	double y;
	double z;
};

struct CMatrix {
	CMatrix();
	~CMatrix() {}

	void SetAxis(int axis, CVector3D v);
	void SetRow(int row, CVector3D v);
	void SetScale(double scale);
	CVector3D ProjectPoint(CVector3D& point);
	CMatrix multiply(CMatrix& R);
	void gl_multiply_matrix();

	double scale;
	bool isIdentity;
	bool flags;
	double m[4][3];
};

class SUMaterial;
class SUComponentInstance;

class SUEntity
{
public:
	SUEntity() {}
	virtual ~SUEntity() {}

	int GetType();
};

class SUDrawingElement : public SUEntity
{
public:
	SUDrawingElement() {}
	~SUDrawingElement() {}

	bool GetHidden();
};

class SUVertex : public SUEntity
{
public:
	SUVertex() {}
	~SUVertex() {}

	CVector3D GetPosition();

};


class SUEdge : public SUDrawingElement
{
public:
	SUEdge() {}
	~SUEdge() {}

	SUVertex* GetStartVertex();
	SUVertex* GetEndVertex();
	bool GetSoft();
	bool GetSmooth();
};

class SUMeshHelper;
class TriangleMesh;

class SUFace : public SUDrawingElement
{
public:
	SUFace() {}
	~SUFace() {}

	CVector3D GetNormal();
	SUMaterial* GetFrontMaterial();
	SUMaterial* GetBackMaterial();
	void Draw(CMatrix* matrix, SUComponentInstance* pm, TriangleMesh* triMesh);
};

class TriangleMesh
{
public:
	TriangleMesh() :ok(false){}
	virtual ~TriangleMesh() {}

	bool Build(SUFace* face, SUComponentInstance* inst);
	
	// func for Triangle
	int GetNumVertices();
	int GetNumVertexIndices();
	int GetVertexIndex(int idx);

	// func for Vertices
	CVector3D GetPoint(int idx);
	CVector3D GetNormal(int idx);
	CVector3D GetUV(int idx);

	bool ok;
private:
	std::vector< CVector3D > points;
	std::vector< CVector3D > normals;
	std::vector< CVector3D > uvs;
	std::vector< size_t > indices;
};

class SUTexture : public SUEntity
{
public:
	SUTexture() {}
	~SUTexture() {}

	std::wstring GetFileName();
	double GetScaleU();
	double GetScaleV();

	bool WriteToFile(std::string filepath);
	int GetImageDataSize();
	std::vector<char> GetImageData();
};

class SUMaterial : public SUEntity
{
public:
	SUMaterial() {}
	~SUMaterial() {}

	std::wstring GetName();
	SUTexture* GetTexture();
	CVector3D GetColor();
	bool GetUseOpacity();
	double GetOpacity();

	static SUMaterial* New();
};


class SUEntityIterator
{
public:
	virtual ~SUEntityIterator() {}
	virtual bool next(SUEntity** out) { return false; }

	bool next(SUEdge** out) { return next((SUEntity**)out); }
};

class SUEntityArrayIterator : public SUEntityIterator
{
public:
	SUEntityArrayIterator() : index(0) {}
	~SUEntityArrayIterator();
	bool next(SUEntity** out);

	std::vector<SUEntity*> seq;
private:
	int index;
};
typedef std::unique_ptr< SUEntityIterator > EntityIteratorPtr;

class SUEntities : public SUDrawingElement
{
public:
	SUEntities() {}
	~SUEntities() {}

	int GetNumEdges();
	int GetNumFaces();
	int GetNumGroups();
	int GetNumInstances();
	std::vector<SUEdge*> GetEdges();
	std::vector<SUFace*> GetFaces();
	std::vector<SUComponentInstance*> GetGroups();
	std::vector<SUComponentInstance*> GetInstances();
	SUEntityIterator* EnumEdges();
	SUEntityIterator* EnumFaces();
};

class SUComponentDefinition : public SUEntities
{
public:
	SUComponentDefinition() {}
	~SUComponentDefinition() {}

	SUEntities* GetEntities();
	std::wstring GetName();
	std::wstring GetDescription();

	bool IsInternal();
	std::wstring GetPath();
};

class SUComponentInstance : public SUDrawingElement
{
public:
	SUComponentInstance() {}
	~SUComponentInstance() {}

	SUComponentDefinition* GetDefinition();
	CMatrix GetTransform();
	SUMaterial* GetMaterial();
};

class SUModel
{
public:
	SUModel() {}
	~SUModel() {}

	SUEntities* GetEntities();
	std::string GetName();

	std::vector<SUMaterial*> GetMaterialList();
	std::vector<SUComponentDefinition*> GetComponentDefinitionList();
	std::vector<SUComponentDefinition*> GetGroupDefinitionList();

	static SUModel* LoadFromFile(std::string file_path);
};

#endif // _MODEL_H
