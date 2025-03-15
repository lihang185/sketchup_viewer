
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "trianglemesh_wrapper.h"

// inner classes

// Extra includes
#include <model.h>


#include <cctype>
#include <cstring>



template <class T>
static const char *typeNameOf(const T &t)
{
    const char *typeName =  typeid(t).name();
    auto size = std::strlen(typeName);
#if defined(Q_CC_MSVC) // MSVC: "class QPaintDevice * __ptr64"
    if (auto lastStar = strchr(typeName, '*')) {
        // MSVC: "class QPaintDevice * __ptr64"
        while (*--lastStar == ' ') {
        }
        size = lastStar - typeName + 1;
    }
#else // g++, Clang: "QPaintDevice *" -> "P12QPaintDevice"
    if (size > 2 && typeName[0] == 'P' && std::isdigit(typeName[1])) {
        ++typeName;
        --size;
    }
#endif
    char *result = new char[size + 1];
    result[size] = '\0';
    memcpy(result, typeName, size);
    return result;
}

// Native ---------------------------------------------------------

void TriangleMeshWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

TriangleMeshWrapper::TriangleMeshWrapper() : TriangleMesh()
{
    resetPyMethodCache();
    // ... middle
}

TriangleMeshWrapper::~TriangleMeshWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_TriangleMeshFunc_Build(PyObject *self, PyObject *args)
{
    ::TriangleMesh *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "Build", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: TriangleMesh::Build(SUFace*,SUComponentInstance*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUFACE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // Build(SUFace*,SUComponentInstance*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_TriangleMeshFunc_Build_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::SUFace *cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::SUComponentInstance *cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // Build(SUFace*,SUComponentInstance*)
            bool cppResult = cppSelf->Build(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_TriangleMeshFunc_Build_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.TriangleMesh.Build");
        return {};
}

static PyObject *Sbk_TriangleMeshFunc_GetNormal(PyObject *self, PyObject *pyArg)
{
    ::TriangleMesh *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: TriangleMesh::GetNormal(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // GetNormal(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_TriangleMeshFunc_GetNormal_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // GetNormal(int)
            CVector3D cppResult = cppSelf->GetNormal(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_TriangleMeshFunc_GetNormal_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.TriangleMesh.GetNormal");
        return {};
}

static PyObject *Sbk_TriangleMeshFunc_GetNumVertexIndices(PyObject *self)
{
    ::TriangleMesh *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNumVertexIndices()
            int cppResult = cppSelf->GetNumVertexIndices();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_TriangleMeshFunc_GetNumVertices(PyObject *self)
{
    ::TriangleMesh *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNumVertices()
            int cppResult = cppSelf->GetNumVertices();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_TriangleMeshFunc_GetPoint(PyObject *self, PyObject *pyArg)
{
    ::TriangleMesh *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: TriangleMesh::GetPoint(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // GetPoint(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_TriangleMeshFunc_GetPoint_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // GetPoint(int)
            CVector3D cppResult = cppSelf->GetPoint(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_TriangleMeshFunc_GetPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.TriangleMesh.GetPoint");
        return {};
}

static PyObject *Sbk_TriangleMeshFunc_GetUV(PyObject *self, PyObject *pyArg)
{
    ::TriangleMesh *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: TriangleMesh::GetUV(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // GetUV(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_TriangleMeshFunc_GetUV_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // GetUV(int)
            CVector3D cppResult = cppSelf->GetUV(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_TriangleMeshFunc_GetUV_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.TriangleMesh.GetUV");
        return {};
}

static PyObject *Sbk_TriangleMeshFunc_GetVertexIndex(PyObject *self, PyObject *pyArg)
{
    ::TriangleMesh *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: TriangleMesh::GetVertexIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // GetVertexIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_TriangleMeshFunc_GetVertexIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // GetVertexIndex(int)
            int cppResult = cppSelf->GetVertexIndex(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_TriangleMeshFunc_GetVertexIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.TriangleMesh.GetVertexIndex");
        return {};
}

static int
Sbk_TriangleMesh_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::TriangleMesh >()))
        return -1;

    ::TriangleMeshWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // TriangleMesh()
            cptr = new ::TriangleMeshWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::TriangleMesh >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyMethodDef Sbk_TriangleMesh_methods[] = {
    {"Build", reinterpret_cast<PyCFunction>(Sbk_TriangleMeshFunc_Build), METH_VARARGS},
    {"GetNormal", reinterpret_cast<PyCFunction>(Sbk_TriangleMeshFunc_GetNormal), METH_O},
    {"GetNumVertexIndices", reinterpret_cast<PyCFunction>(Sbk_TriangleMeshFunc_GetNumVertexIndices), METH_NOARGS},
    {"GetNumVertices", reinterpret_cast<PyCFunction>(Sbk_TriangleMeshFunc_GetNumVertices), METH_NOARGS},
    {"GetPoint", reinterpret_cast<PyCFunction>(Sbk_TriangleMeshFunc_GetPoint), METH_O},
    {"GetUV", reinterpret_cast<PyCFunction>(Sbk_TriangleMeshFunc_GetUV), METH_O},
    {"GetVertexIndex", reinterpret_cast<PyCFunction>(Sbk_TriangleMeshFunc_GetVertexIndex), METH_O},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_TriangleMesh_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<TriangleMeshWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

static PyObject *Sbk_TriangleMesh_get_ok(PyObject *self, void *)
{
    ::TriangleMesh *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
    bool cppOut_local = cppSelf->ok;
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_TriangleMesh_set_ok(PyObject *self, PyObject *pyIn, void *)
{
    ::TriangleMesh *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::TriangleMesh *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_TRIANGLEMESH_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'ok' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'ok', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->ok;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->ok = cppOut_local;

    return 0;
}

// Getters and Setters for TriangleMesh
static PyGetSetDef Sbk_TriangleMesh_getsetlist[] = {
    {const_cast<char *>("ok"), Sbk_TriangleMesh_get_ok, Sbk_TriangleMesh_set_ok},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_TriangleMesh_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_TriangleMesh_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_TriangleMesh_Type = nullptr;
static SbkObjectType *Sbk_TriangleMesh_TypeF(void)
{
    return _Sbk_TriangleMesh_Type;
}

static PyType_Slot Sbk_TriangleMesh_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_TriangleMesh_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_TriangleMesh_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_TriangleMesh_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_TriangleMesh_methods)},
    {Py_tp_getset,      reinterpret_cast<void *>(Sbk_TriangleMesh_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_TriangleMesh_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_TriangleMesh_spec = {
    "suapi.TriangleMesh",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_TriangleMesh_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void TriangleMesh_PythonToCpp_TriangleMesh_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_TriangleMesh_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_TriangleMesh_PythonToCpp_TriangleMesh_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_TriangleMesh_TypeF())))
        return TriangleMesh_PythonToCpp_TriangleMesh_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *TriangleMesh_PTR_CppToPython_TriangleMesh(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::TriangleMesh *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_TriangleMesh_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *TriangleMesh_SignatureStrings[] = {
    "suapi.TriangleMesh.Build(face:suapi.SUFace,inst:suapi.SUComponentInstance)->bool",
    "suapi.TriangleMesh.GetNormal(idx:int)->suapi.CVector3D",
    "suapi.TriangleMesh.GetNumVertexIndices()->int",
    "suapi.TriangleMesh.GetNumVertices()->int",
    "suapi.TriangleMesh.GetPoint(idx:int)->suapi.CVector3D",
    "suapi.TriangleMesh.GetUV(idx:int)->suapi.CVector3D",
    "suapi.TriangleMesh.GetVertexIndex(idx:int)->int",
    "suapi.TriangleMesh()",
    nullptr}; // Sentinel

void init_TriangleMesh(PyObject *module)
{
    _Sbk_TriangleMesh_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "TriangleMesh",
        "TriangleMesh*",
        &Sbk_TriangleMesh_spec,
        TriangleMesh_SignatureStrings,
        &Shiboken::callCppDestructor< ::TriangleMesh >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_TRIANGLEMESH_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_TriangleMesh_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_TriangleMesh_TypeF(),
        TriangleMesh_PythonToCpp_TriangleMesh_PTR,
        is_TriangleMesh_PythonToCpp_TriangleMesh_PTR_Convertible,
        TriangleMesh_PTR_CppToPython_TriangleMesh);

    Shiboken::Conversions::registerConverterName(converter, "TriangleMesh");
    Shiboken::Conversions::registerConverterName(converter, "TriangleMesh*");
    Shiboken::Conversions::registerConverterName(converter, "TriangleMesh&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::TriangleMesh).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::TriangleMeshWrapper).name());



}
