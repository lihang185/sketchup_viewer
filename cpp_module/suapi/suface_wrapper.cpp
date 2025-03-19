
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suface_wrapper.h"

// inner classes

// Extra includes
#include <model.h>
#include <vector>


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

void SUFaceWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUFaceWrapper::SUFaceWrapper() : SUFace()
{
    resetPyMethodCache();
    // ... middle
}

SUFaceWrapper::~SUFaceWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUFaceFunc_Draw(PyObject *self, PyObject *args)
{
    ::SUFace *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUFace *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUFACE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "Draw", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: SUFace::Draw(CMatrix*,SUComponentInstance*,TriangleMesh*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_TRIANGLEMESH_IDX]), (pyArgs[2])))) {
        overloadId = 0; // Draw(CMatrix*,SUComponentInstance*,TriangleMesh*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUFaceFunc_Draw_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::CMatrix *cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::SUComponentInstance *cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return {};
        ::TriangleMesh *cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // Draw(CMatrix*,SUComponentInstance*,TriangleMesh*)
            cppSelf->Draw(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_SUFaceFunc_Draw_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.SUFace.Draw");
        return {};
}

static PyObject *Sbk_SUFaceFunc_GetBackMaterial(PyObject *self)
{
    ::SUFace *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUFace *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUFACE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetBackMaterial()
            SUMaterial * cppResult = cppSelf->GetBackMaterial();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUMATERIAL_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUFaceFunc_GetFrontMaterial(PyObject *self)
{
    ::SUFace *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUFace *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUFACE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetFrontMaterial()
            SUMaterial * cppResult = cppSelf->GetFrontMaterial();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUMATERIAL_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUFaceFunc_GetInnerLoops(PyObject *self)
{
    ::SUFace *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUFace *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUFACE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetInnerLoops()
            std::vector<SULoop* > cppResult = cppSelf->GetInnerLoops();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SULOOPPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUFaceFunc_GetNormal(PyObject *self)
{
    ::SUFace *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUFace *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUFACE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNormal()
            CVector3D cppResult = cppSelf->GetNormal();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUFaceFunc_GetOuterLoop(PyObject *self)
{
    ::SUFace *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUFace *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUFACE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetOuterLoop()
            SULoop * cppResult = cppSelf->GetOuterLoop();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SULOOP_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUFaceFunc_GetPlane(PyObject *self)
{
    ::SUFace *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUFace *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUFACE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetPlane()
            CPlane cppResult = cppSelf->GetPlane();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CPLANE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static int
Sbk_SUFace_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUFace >()))
        return -1;

    ::SUFaceWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUFace()
            cptr = new ::SUFaceWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUFace >(), cptr)) {
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

static PyMethodDef Sbk_SUFace_methods[] = {
    {"Draw", reinterpret_cast<PyCFunction>(Sbk_SUFaceFunc_Draw), METH_VARARGS},
    {"GetBackMaterial", reinterpret_cast<PyCFunction>(Sbk_SUFaceFunc_GetBackMaterial), METH_NOARGS},
    {"GetFrontMaterial", reinterpret_cast<PyCFunction>(Sbk_SUFaceFunc_GetFrontMaterial), METH_NOARGS},
    {"GetInnerLoops", reinterpret_cast<PyCFunction>(Sbk_SUFaceFunc_GetInnerLoops), METH_NOARGS},
    {"GetNormal", reinterpret_cast<PyCFunction>(Sbk_SUFaceFunc_GetNormal), METH_NOARGS},
    {"GetOuterLoop", reinterpret_cast<PyCFunction>(Sbk_SUFaceFunc_GetOuterLoop), METH_NOARGS},
    {"GetPlane", reinterpret_cast<PyCFunction>(Sbk_SUFaceFunc_GetPlane), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUFace_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUFace *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUFACE_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUFaceWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUFace_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUFace_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUFace_Type = nullptr;
static SbkObjectType *Sbk_SUFace_TypeF(void)
{
    return _Sbk_SUFace_Type;
}

static PyType_Slot Sbk_SUFace_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUFace_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUFace_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUFace_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUFace_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUFace_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUFace_spec = {
    "suapi.SUFace",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUFace_slots
};

} //extern "C"

static void *Sbk_SUFace_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUFace *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUFace_PythonToCpp_SUFace_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUFace_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUFace_PythonToCpp_SUFace_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUFace_TypeF())))
        return SUFace_PythonToCpp_SUFace_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUFace_PTR_CppToPython_SUFace(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUFace *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUFace_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUFace_SignatureStrings[] = {
    "suapi.SUFace.Draw(matrix:suapi.CMatrix,pm:suapi.SUComponentInstance,triMesh:suapi.TriangleMesh)",
    "suapi.SUFace.GetBackMaterial()->suapi.SUMaterial",
    "suapi.SUFace.GetFrontMaterial()->suapi.SUMaterial",
    "suapi.SUFace.GetInnerLoops()->std.vector[suapi.SULoop]",
    "suapi.SUFace.GetNormal()->suapi.CVector3D",
    "suapi.SUFace.GetOuterLoop()->suapi.SULoop",
    "suapi.SUFace.GetPlane()->suapi.CPlane",
    "suapi.SUFace()",
    nullptr}; // Sentinel

void init_SUFace(PyObject *module)
{
    _Sbk_SUFace_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUFace",
        "SUFace*",
        &Sbk_SUFace_spec,
        SUFace_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUFace >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUDRAWINGELEMENT_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUFACE_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUFace_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUFace_TypeF(),
        SUFace_PythonToCpp_SUFace_PTR,
        is_SUFace_PythonToCpp_SUFace_PTR_Convertible,
        SUFace_PTR_CppToPython_SUFace);

    Shiboken::Conversions::registerConverterName(converter, "SUFace");
    Shiboken::Conversions::registerConverterName(converter, "SUFace*");
    Shiboken::Conversions::registerConverterName(converter, "SUFace&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUFace).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUFaceWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUFace_TypeF(), &Sbk_SUFace_typeDiscovery);


}
