
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suloop_wrapper.h"

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

void SULoopWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SULoopWrapper::SULoopWrapper() : SULoop()
{
    resetPyMethodCache();
    // ... middle
}

SULoopWrapper::~SULoopWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SULoopFunc_GetEdgeUses(PyObject *self)
{
    ::SULoop *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SULoop *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SULOOP_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetEdgeUses()
            std::vector<SUEdgeUse* > cppResult = cppSelf->GetEdgeUses();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUEDGEUSEPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SULoopFunc_GetEdges(PyObject *self)
{
    ::SULoop *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SULoop *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SULOOP_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetEdges()
            std::vector<SUEdge* > cppResult = cppSelf->GetEdges();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUEDGEPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SULoopFunc_GetFace(PyObject *self)
{
    ::SULoop *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SULoop *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SULOOP_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_SULoopFunc_GetNumVertices(PyObject *self)
{
    ::SULoop *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SULoop *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SULOOP_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_SULoopFunc_GetVertices(PyObject *self)
{
    ::SULoop *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SULoop *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SULOOP_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetVertices()
            std::vector<SUVertex* > cppResult = cppSelf->GetVertices();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUVERTEXPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SULoopFunc_IsConvex(PyObject *self)
{
    ::SULoop *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SULoop *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SULOOP_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // IsConvex()
            bool cppResult = cppSelf->IsConvex();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SULoopFunc_IsOuterLoop(PyObject *self)
{
    ::SULoop *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SULoop *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SULOOP_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // IsOuterLoop()
            bool cppResult = cppSelf->IsOuterLoop();
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
Sbk_SULoop_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SULoop >()))
        return -1;

    ::SULoopWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SULoop()
            cptr = new ::SULoopWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SULoop >(), cptr)) {
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

static PyMethodDef Sbk_SULoop_methods[] = {
    {"GetEdgeUses", reinterpret_cast<PyCFunction>(Sbk_SULoopFunc_GetEdgeUses), METH_NOARGS},
    {"GetEdges", reinterpret_cast<PyCFunction>(Sbk_SULoopFunc_GetEdges), METH_NOARGS},
    {"GetFace", reinterpret_cast<PyCFunction>(Sbk_SULoopFunc_GetFace), METH_NOARGS},
    {"GetNumVertices", reinterpret_cast<PyCFunction>(Sbk_SULoopFunc_GetNumVertices), METH_NOARGS},
    {"GetVertices", reinterpret_cast<PyCFunction>(Sbk_SULoopFunc_GetVertices), METH_NOARGS},
    {"IsConvex", reinterpret_cast<PyCFunction>(Sbk_SULoopFunc_IsConvex), METH_NOARGS},
    {"IsOuterLoop", reinterpret_cast<PyCFunction>(Sbk_SULoopFunc_IsOuterLoop), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SULoop_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SULoop *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SULOOP_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SULoopWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SULoop_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SULoop_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SULoop_Type = nullptr;
static SbkObjectType *Sbk_SULoop_TypeF(void)
{
    return _Sbk_SULoop_Type;
}

static PyType_Slot Sbk_SULoop_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SULoop_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SULoop_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SULoop_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SULoop_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SULoop_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SULoop_spec = {
    "suapi.SULoop",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SULoop_slots
};

} //extern "C"

static void *Sbk_SULoop_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SULoop *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SULoop_PythonToCpp_SULoop_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SULoop_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SULoop_PythonToCpp_SULoop_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SULoop_TypeF())))
        return SULoop_PythonToCpp_SULoop_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SULoop_PTR_CppToPython_SULoop(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SULoop *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SULoop_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SULoop_SignatureStrings[] = {
    "suapi.SULoop.GetEdgeUses()->std.vector[suapi.SUEdgeUse]",
    "suapi.SULoop.GetEdges()->std.vector[suapi.SUEdge]",
    "suapi.SULoop.GetFace()->suapi.SUFace",
    "suapi.SULoop.GetNumVertices()->int",
    "suapi.SULoop.GetVertices()->std.vector[suapi.SUVertex]",
    "suapi.SULoop.IsConvex()->bool",
    "suapi.SULoop.IsOuterLoop()->bool",
    "suapi.SULoop()",
    nullptr}; // Sentinel

void init_SULoop(PyObject *module)
{
    _Sbk_SULoop_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SULoop",
        "SULoop*",
        &Sbk_SULoop_spec,
        SULoop_SignatureStrings,
        &Shiboken::callCppDestructor< ::SULoop >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITY_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SULOOP_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SULoop_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SULoop_TypeF(),
        SULoop_PythonToCpp_SULoop_PTR,
        is_SULoop_PythonToCpp_SULoop_PTR_Convertible,
        SULoop_PTR_CppToPython_SULoop);

    Shiboken::Conversions::registerConverterName(converter, "SULoop");
    Shiboken::Conversions::registerConverterName(converter, "SULoop*");
    Shiboken::Conversions::registerConverterName(converter, "SULoop&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SULoop).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SULoopWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SULoop_TypeF(), &Sbk_SULoop_typeDiscovery);


}
