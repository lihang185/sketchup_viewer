

#ifndef SBK_SUAPI_PYTHON_H
#define SBK_SUAPI_PYTHON_H

#include <sbkpython.h>
#include <sbkconverter.h>
// Bound library includes
#include <model.h>
// Conversion Includes - Primitive Types

// Conversion Includes - Container Types
#include <vector>

// Type indices
enum : int {
    SBK_CMATRIX_IDX                                          = 0,
    SBK_CMATRIX33_IDX                                        = 1,
    SBK_CPLANE_IDX                                           = 2,
    SBK_CVECTOR2D_IDX                                        = 3,
    SBK_CVECTOR3D_IDX                                        = 4,
    SBK_SUATTRIBUTEDICTIONARY_IDX                            = 5,
    SBK_SUCOMPONENTDEFINITION_IDX                            = 6,
    SBK_SUCOMPONENTINSTANCE_IDX                              = 7,
    SBK_SUDRAWINGELEMENT_IDX                                 = 8,
    SBK_SUEDGE_IDX                                           = 9,
    SBK_SUEDGEUSE_IDX                                        = 10,
    SBK_SUENTITIES_IDX                                       = 11,
    SBK_SUENTITY_IDX                                         = 12,
    SBK_SUENTITYITERATOR_IDX                                 = 13,
    SBK_SUFACE_IDX                                           = 14,
    SBK_SULOOP_IDX                                           = 15,
    SBK_SUMATERIAL_IDX                                       = 16,
    SBK_SUMODEL_IDX                                          = 17,
    SBK_SUTEXTURE_IDX                                        = 18,
    SBK_SUUVHELPER_IDX                                       = 19,
    SBK_SUVERTEX_IDX                                         = 20,
    SBK_TRIANGLEMESH_IDX                                     = 21,
    SBK_suapi_IDX_COUNT                                      = 22
};
// This variable stores all Python types exported by this module.
extern PyTypeObject **SbksuapiTypes;

// This variable stores the Python module object exported by this module.
extern PyObject *SbksuapiModuleObject;

// This variable stores all type converters exported by this module.
extern SbkConverter **SbksuapiTypeConverters;

// Converter indices
enum : int {
    SBK_STD_WSTRING_IDX                                      = 0,
    SBK_SUAPI_STD_VECTOR_DOUBLE_IDX                          = 1, // std::vector<double >
    SBK_SUAPI_STD_VECTOR_STD_WSTRING_IDX                     = 2, // std::vector<std::wstring >
    SBK_SUAPI_STD_VECTOR_SUATTRIBUTEDICTIONARYPTR_IDX        = 3, // std::vector<SUAttributeDictionary* >
    SBK_SUAPI_STD_VECTOR_SUEDGEPTR_IDX                       = 4, // std::vector<SUEdge* >
    SBK_SUAPI_STD_VECTOR_SUFACEPTR_IDX                       = 5, // std::vector<SUFace* >
    SBK_SUAPI_STD_VECTOR_SUCOMPONENTINSTANCEPTR_IDX          = 6, // std::vector<SUComponentInstance* >
    SBK_SUAPI_STD_VECTOR_SULOOPPTR_IDX                       = 7, // std::vector<SULoop* >
    SBK_SUAPI_STD_VECTOR_SUEDGEUSEPTR_IDX                    = 8, // std::vector<SUEdgeUse* >
    SBK_SUAPI_STD_VECTOR_SUVERTEXPTR_IDX                     = 9, // std::vector<SUVertex* >
    SBK_SUAPI_STD_VECTOR_SUCOMPONENTDEFINITIONPTR_IDX        = 10, // std::vector<SUComponentDefinition* >
    SBK_SUAPI_STD_VECTOR_SUMATERIALPTR_IDX                   = 11, // std::vector<SUMaterial* >
    SBK_suapi_CONVERTERS_IDX_COUNT                           = 12
};
// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject *SbkType< ::CMatrix >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_CMATRIX_IDX]); }
template<> inline PyTypeObject *SbkType< ::CMatrix33 >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_CMATRIX33_IDX]); }
template<> inline PyTypeObject *SbkType< ::CPlane >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_CPLANE_IDX]); }
template<> inline PyTypeObject *SbkType< ::CVector2D >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_CVECTOR2D_IDX]); }
template<> inline PyTypeObject *SbkType< ::CVector3D >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUAttributeDictionary >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUATTRIBUTEDICTIONARY_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUComponentDefinition >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUComponentInstance >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUDrawingElement >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUDRAWINGELEMENT_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUEdge >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUEDGE_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUEdgeUse >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUEDGEUSE_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUEntities >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUENTITIES_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUEntity >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUENTITY_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUEntityIterator >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUENTITYITERATOR_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUFace >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUFACE_IDX]); }
template<> inline PyTypeObject *SbkType< ::SULoop >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SULOOP_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUMaterial >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUMATERIAL_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUModel >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUMODEL_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUTexture >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUTEXTURE_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUUVHelper >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUUVHELPER_IDX]); }
template<> inline PyTypeObject *SbkType< ::SUVertex >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_SUVERTEX_IDX]); }
template<> inline PyTypeObject *SbkType< ::TriangleMesh >() { return reinterpret_cast<PyTypeObject *>(SbksuapiTypes[SBK_TRIANGLEMESH_IDX]); }

} // namespace Shiboken

#endif // SBK_SUAPI_PYTHON_H

