
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suvertex_wrapper.h"

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

void SUVertexWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUVertexWrapper::SUVertexWrapper() : SUVertex()
{
    resetPyMethodCache();
    // ... middle
}

SUVertexWrapper::~SUVertexWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUVertexFunc_GetPosition(PyObject *self)
{
    ::SUVertex *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUVertex *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUVERTEX_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetPosition()
            CVector3D cppResult = cppSelf->GetPosition();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static int
Sbk_SUVertex_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUVertex >()))
        return -1;

    ::SUVertexWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUVertex()
            cptr = new ::SUVertexWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUVertex >(), cptr)) {
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

static PyMethodDef Sbk_SUVertex_methods[] = {
    {"GetPosition", reinterpret_cast<PyCFunction>(Sbk_SUVertexFunc_GetPosition), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUVertex_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUVertex *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUVERTEX_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUVertexWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUVertex_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUVertex_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUVertex_Type = nullptr;
static SbkObjectType *Sbk_SUVertex_TypeF(void)
{
    return _Sbk_SUVertex_Type;
}

static PyType_Slot Sbk_SUVertex_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUVertex_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUVertex_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUVertex_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUVertex_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUVertex_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUVertex_spec = {
    "suapi.SUVertex",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUVertex_slots
};

} //extern "C"

static void *Sbk_SUVertex_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUVertex *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUVertex_PythonToCpp_SUVertex_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUVertex_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUVertex_PythonToCpp_SUVertex_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUVertex_TypeF())))
        return SUVertex_PythonToCpp_SUVertex_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUVertex_PTR_CppToPython_SUVertex(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUVertex *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUVertex_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUVertex_SignatureStrings[] = {
    "suapi.SUVertex.GetPosition()->suapi.CVector3D",
    "suapi.SUVertex()",
    nullptr}; // Sentinel

void init_SUVertex(PyObject *module)
{
    _Sbk_SUVertex_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUVertex",
        "SUVertex*",
        &Sbk_SUVertex_spec,
        SUVertex_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUVertex >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITY_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUVERTEX_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUVertex_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUVertex_TypeF(),
        SUVertex_PythonToCpp_SUVertex_PTR,
        is_SUVertex_PythonToCpp_SUVertex_PTR_Convertible,
        SUVertex_PTR_CppToPython_SUVertex);

    Shiboken::Conversions::registerConverterName(converter, "SUVertex");
    Shiboken::Conversions::registerConverterName(converter, "SUVertex*");
    Shiboken::Conversions::registerConverterName(converter, "SUVertex&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUVertex).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUVertexWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUVertex_TypeF(), &Sbk_SUVertex_typeDiscovery);


}
