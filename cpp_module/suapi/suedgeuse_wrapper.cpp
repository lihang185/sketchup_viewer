
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suedgeuse_wrapper.h"

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

void SUEdgeUseWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUEdgeUseWrapper::SUEdgeUseWrapper() : SUEdgeUse()
{
    resetPyMethodCache();
    // ... middle
}

SUEdgeUseWrapper::~SUEdgeUseWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUEdgeUseFunc_GetEdge(PyObject *self)
{
    ::SUEdgeUse *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdgeUse *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGEUSE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetEdge()
            SUEdge * cppResult = cppSelf->GetEdge();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUEDGE_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEdgeUseFunc_GetEndVertex(PyObject *self)
{
    ::SUEdgeUse *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdgeUse *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGEUSE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetEndVertex()
            SUVertex * cppResult = cppSelf->GetEndVertex();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUVERTEX_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEdgeUseFunc_GetEndVertexNormal(PyObject *self)
{
    ::SUEdgeUse *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdgeUse *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGEUSE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetEndVertexNormal()
            CVector3D cppResult = cppSelf->GetEndVertexNormal();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEdgeUseFunc_GetFace(PyObject *self)
{
    ::SUEdgeUse *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdgeUse *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGEUSE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetFace()
            SUFace * cppResult = cppSelf->GetFace();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUFACE_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEdgeUseFunc_GetLoop(PyObject *self)
{
    ::SUEdgeUse *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdgeUse *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGEUSE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetLoop()
            SULoop * cppResult = cppSelf->GetLoop();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SULOOP_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEdgeUseFunc_GetStartVertex(PyObject *self)
{
    ::SUEdgeUse *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdgeUse *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGEUSE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetStartVertex()
            SUVertex * cppResult = cppSelf->GetStartVertex();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUVERTEX_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEdgeUseFunc_GetStartVertexNormal(PyObject *self)
{
    ::SUEdgeUse *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdgeUse *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGEUSE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetStartVertexNormal()
            CVector3D cppResult = cppSelf->GetStartVertexNormal();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEdgeUseFunc_IsReversed(PyObject *self)
{
    ::SUEdgeUse *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdgeUse *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGEUSE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // IsReversed()
            bool cppResult = cppSelf->IsReversed();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static int
Sbk_SUEdgeUse_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUEdgeUse >()))
        return -1;

    ::SUEdgeUseWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUEdgeUse()
            cptr = new ::SUEdgeUseWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUEdgeUse >(), cptr)) {
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

static PyMethodDef Sbk_SUEdgeUse_methods[] = {
    {"GetEdge", reinterpret_cast<PyCFunction>(Sbk_SUEdgeUseFunc_GetEdge), METH_NOARGS},
    {"GetEndVertex", reinterpret_cast<PyCFunction>(Sbk_SUEdgeUseFunc_GetEndVertex), METH_NOARGS},
    {"GetEndVertexNormal", reinterpret_cast<PyCFunction>(Sbk_SUEdgeUseFunc_GetEndVertexNormal), METH_NOARGS},
    {"GetFace", reinterpret_cast<PyCFunction>(Sbk_SUEdgeUseFunc_GetFace), METH_NOARGS},
    {"GetLoop", reinterpret_cast<PyCFunction>(Sbk_SUEdgeUseFunc_GetLoop), METH_NOARGS},
    {"GetStartVertex", reinterpret_cast<PyCFunction>(Sbk_SUEdgeUseFunc_GetStartVertex), METH_NOARGS},
    {"GetStartVertexNormal", reinterpret_cast<PyCFunction>(Sbk_SUEdgeUseFunc_GetStartVertexNormal), METH_NOARGS},
    {"IsReversed", reinterpret_cast<PyCFunction>(Sbk_SUEdgeUseFunc_IsReversed), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUEdgeUse_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUEdgeUse *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGEUSE_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUEdgeUseWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUEdgeUse_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUEdgeUse_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUEdgeUse_Type = nullptr;
static SbkObjectType *Sbk_SUEdgeUse_TypeF(void)
{
    return _Sbk_SUEdgeUse_Type;
}

static PyType_Slot Sbk_SUEdgeUse_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUEdgeUse_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUEdgeUse_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUEdgeUse_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUEdgeUse_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUEdgeUse_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUEdgeUse_spec = {
    "suapi.SUEdgeUse",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUEdgeUse_slots
};

} //extern "C"

static void *Sbk_SUEdgeUse_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUEdgeUse *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUEdgeUse_PythonToCpp_SUEdgeUse_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUEdgeUse_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUEdgeUse_PythonToCpp_SUEdgeUse_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUEdgeUse_TypeF())))
        return SUEdgeUse_PythonToCpp_SUEdgeUse_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUEdgeUse_PTR_CppToPython_SUEdgeUse(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUEdgeUse *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUEdgeUse_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUEdgeUse_SignatureStrings[] = {
    "suapi.SUEdgeUse.GetEdge()->suapi.SUEdge",
    "suapi.SUEdgeUse.GetEndVertex()->suapi.SUVertex",
    "suapi.SUEdgeUse.GetEndVertexNormal()->suapi.CVector3D",
    "suapi.SUEdgeUse.GetFace()->suapi.SUFace",
    "suapi.SUEdgeUse.GetLoop()->suapi.SULoop",
    "suapi.SUEdgeUse.GetStartVertex()->suapi.SUVertex",
    "suapi.SUEdgeUse.GetStartVertexNormal()->suapi.CVector3D",
    "suapi.SUEdgeUse.IsReversed()->bool",
    "suapi.SUEdgeUse()",
    nullptr}; // Sentinel

void init_SUEdgeUse(PyObject *module)
{
    _Sbk_SUEdgeUse_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUEdgeUse",
        "SUEdgeUse*",
        &Sbk_SUEdgeUse_spec,
        SUEdgeUse_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUEdgeUse >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITY_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUEDGEUSE_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUEdgeUse_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUEdgeUse_TypeF(),
        SUEdgeUse_PythonToCpp_SUEdgeUse_PTR,
        is_SUEdgeUse_PythonToCpp_SUEdgeUse_PTR_Convertible,
        SUEdgeUse_PTR_CppToPython_SUEdgeUse);

    Shiboken::Conversions::registerConverterName(converter, "SUEdgeUse");
    Shiboken::Conversions::registerConverterName(converter, "SUEdgeUse*");
    Shiboken::Conversions::registerConverterName(converter, "SUEdgeUse&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEdgeUse).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEdgeUseWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUEdgeUse_TypeF(), &Sbk_SUEdgeUse_typeDiscovery);


}
