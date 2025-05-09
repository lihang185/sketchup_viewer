#ifndef _MODEL_H
#define _MODEL_H

#include <tchar.h>
#include <vector>
#include <string>
#include <map>
#include <memory>

#define SUAPI(ptr) {ptr}
#define cast_SUEntity(ref) ((SUEntity*)ref.ptr)
#define cast_SUAttributeDictionary(ref) ((SUAttributeDictionary*)ref.ptr)
#define cast_SUDrawingElement(ref) ((SUDrawingElement*)ref.ptr)
#define cast_SUVertex(ref) ((SUVertex*)ref.ptr)
#define cast_SUEdge(ref) ((SUEdge*)ref.ptr)
#define cast_SUEdgeUse(ref) ((SUEdgeUse*)ref.ptr)
#define cast_SULoop(ref) ((SULoop*)ref.ptr)
#define cast_SUFace(ref) ((SUFace*)ref.ptr)
#define cast_SUTexture(ref) ((SUTexture*)ref.ptr)
#define cast_SUMaterial(ref) ((SUMaterial*)ref.ptr)
#define cast_SUEntities(ref) ((SUEntities*)ref.ptr)
#define cast_SUComponentInstance(ref) ((SUComponentInstance*)ref.ptr)
#define cast_SUComponentDefinition(ref) ((SUComponentDefinition*)ref.ptr)

struct CVector2D {
	CVector2D() : x(0), y(0) {}
	CVector2D(double ix, double iy) : x(ix), y(iy) {}

	double x;
	double y;
};

struct CVector3D {
	CVector3D() : x(0), y(0), z(0) {}
	CVector3D(double ix, double iy, double iz) : x(ix), y(iy), z(iz) {}

	CVector3D operator+(CVector3D& R);
	CVector3D operator-(CVector3D& R);
	CVector3D operator*(double scale);
	CVector3D operator-();

	double DotProduct(CVector3D& R);
	CVector3D CrossProduct(CVector3D& R);


	double x;
	double y;
	double z;
};

class CPlane {
public:
	CPlane() :x(0), y(0), z(0), w(1) {}
	CPlane(double _x, double _y, double _z, double _w) :x(_x), y(_y), z(_z), w(_w) {}
	CPlane(CVector3D& _p, double _w) :x(_p.x), y(_p.y), z(_p.z), w(_w) {}
	CPlane(CVector3D& normal, CVector3D& orig);
	~CPlane() {}
	CVector3D GetNormal();

	double IntersectWithRay(CVector3D& orig, CVector3D& dir);

	double x;
	double y;
	double z;
	double w;
};

class CMatrix33 {
public:
	CMatrix33();
	double get(int i, int j) { return m[i][j]; }
	std::vector<double> GetData();
private:
	double m[3][3];
};

struct CMatrix43 {
	CMatrix43();
	~CMatrix43() {}

	double m[4][3];
	double scale;
	bool is_identity;
	bool flags;
};

struct CMatrix {
	CMatrix();
	~CMatrix() {}

	CVector3D TransformPoint(CVector3D& point);
	CMatrix Multiply(CMatrix& R);
	CMatrix Multiply2(CMatrix& R);
	void gl_multiply_matrix();

	std::vector<double> GetData();
	static CMatrix NewFromData(std::vector<double>& data);

	static CMatrix NewFromTranslate(CVector3D& translate);
	static CMatrix NewFromRotate(CVector3D& rotate);
	static CMatrix NewFromScale(CVector3D& scale);

	double m[4][4];
};

class SUAttributeDictionary;
class SULoop;
class SUFace;
class SUMaterial;
class SUComponentInstance;

class SUEntity
{
public:
	SUEntity() {}
	virtual ~SUEntity() {}

	int GetType();
	int GetID();

	int GetNumAttributeDictionaries();
	std::vector<SUAttributeDictionary*> GetAttributeDictionaries();
};

class SUAttributeDictionary
{
public:
	SUAttributeDictionary() {}
	~SUAttributeDictionary() {}

	std::wstring GetName();
	int GetNumKeys();
	std::vector<std::wstring> GetKeys();
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

class SUEdgeUse : public SUEntity
{
public:
	SUEdgeUse() {}
	~SUEdgeUse() {}

	SUEdge* GetEdge();
	SUVertex* GetStartVertex();
	CVector3D GetStartVertexNormal();
	SUVertex* GetEndVertex();
	CVector3D GetEndVertexNormal();
	bool IsReversed();

	SUFace* GetFace();
	SULoop* GetLoop();
};

class SULoop : public SUEntity
{
public:
	SULoop() {}
	~SULoop() {}

	int GetNumVertices();
	std::vector<SUVertex*> GetVertices();
	std::vector<SUEdge*> GetEdges();
	std::vector<SUEdgeUse*> GetEdgeUses();
	bool IsOuterLoop();
	bool IsConvex();


	SUFace* GetFace();
};

class SUMeshHelper;
class TriangleMesh;
class SUUVHelper;

class SUFace : public SUDrawingElement
{
public:
	SUFace() {}
	~SUFace() {}

	SULoop* GetOuterLoop();
	std::vector<SULoop*> GetInnerLoops();

	CPlane GetPlane();
	CVector3D GetNormal();
	SUMaterial* GetFrontMaterial();
	SUMaterial* GetBackMaterial();
	void Draw(CMatrix* matrix, SUComponentInstance* pm, TriangleMesh* triMesh);

	SUUVHelper* GetUVHelper();
};

class SUUVHelper
{
public:
	SUUVHelper() {}
	~SUUVHelper() {}

	void Release();

	CMatrix33 GetFrontTextureMatrix();
	CMatrix33 GetBackTextureMatrix();

private:
	CMatrix43 m1;
	CMatrix43 m2;
	CMatrix33 tm1;
	CMatrix33 tm2;
	CPlane unknow1;
	CPlane unknow2;
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

	static SUMaterial* Create();

	std::wstring GetName();
	SUTexture* GetTexture();
	CVector3D GetColor();
	bool GetUseOpacity();
	double GetOpacity();
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

	bool AddEdge(SUEdge* edge);
	bool AddFace(SUFace* face);
	bool AddInstance(SUComponentInstance* inst);
};

class SUComponentDefinition : public SUEntities
{
public:
	SUComponentDefinition() {}
	~SUComponentDefinition() {}

	SUEntities* GetEntities();
	std::wstring GetName();
	std::wstring GetDescription();
	void debug_hook();

	SUComponentInstance* CreateInstance();

	bool IsInternal();
	std::wstring GetPath();

	static SUComponentDefinition* Create();
};

class SUComponentInstance : public SUDrawingElement
{
public:
	SUComponentInstance() {}
	~SUComponentInstance() {}

	SUComponentDefinition* GetDefinition();
	CMatrix GetTransform();
	void SetTransform(CMatrix& m);
	SUMaterial* GetMaterial();

	std::wstring GetName();

};

class SUModel
{
public:
	SUModel() {}
	~SUModel() {}

	bool SaveToFile(std::string& filepath);
	void Release();

	SUEntities* GetEntities();
	std::string GetName();

	std::vector<SUMaterial*> GetMaterialList();
	std::vector<SUComponentDefinition*> GetComponentDefinitionList();
	std::vector<SUComponentDefinition*> GetGroupDefinitionList();

	bool AddComponentDefinitions(SUComponentDefinition* comp);
	bool AddMaterial(SUMaterial* mat);

	static SUModel* LoadFromFile(std::string file_path);
	static SUModel* cLoadFromBuffer(const unsigned char* buffer, size_t buffer_size);
	
};

#endif // _MODEL_H
