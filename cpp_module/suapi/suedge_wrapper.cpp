
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suedge_wrapper.h"

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

void SUEdgeWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUEdgeWrapper::SUEdgeWrapper() : SUEdge()
{
    resetPyMethodCache();
    // ... middle
}

SUEdgeWrapper::~SUEdgeWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUEdgeFunc_GetEndVertex(PyObject *self)
{
    ::SUEdge *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdge *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGE_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_SUEdgeFunc_GetSmooth(PyObject *self)
{
    ::SUEdge *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdge *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetSmooth()
            bool cppResult = cppSelf->GetSmooth();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEdgeFunc_GetSoft(PyObject *self)
{
    ::SUEdge *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdge *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetSoft()
            bool cppResult = cppSelf->GetSoft();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEdgeFunc_GetStartVertex(PyObject *self)
{
    ::SUEdge *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEdge *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGE_IDX], reinterpret_cast<SbkObject *>(self)));
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

static int
Sbk_SUEdge_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUEdge >()))
        return -1;

    ::SUEdgeWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUEdge()
            cptr = new ::SUEdgeWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUEdge >(), cptr)) {
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

static PyMethodDef Sbk_SUEdge_methods[] = {
    {"GetEndVertex", reinterpret_cast<PyCFunction>(Sbk_SUEdgeFunc_GetEndVertex), METH_NOARGS},
    {"GetSmooth", reinterpret_cast<PyCFunction>(Sbk_SUEdgeFunc_GetSmooth), METH_NOARGS},
    {"GetSoft", reinterpret_cast<PyCFunction>(Sbk_SUEdgeFunc_GetSoft), METH_NOARGS},
    {"GetStartVertex", reinterpret_cast<PyCFunction>(Sbk_SUEdgeFunc_GetStartVertex), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUEdge_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUEdge *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUEDGE_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUEdgeWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUEdge_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUEdge_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUEdge_Type = nullptr;
static SbkObjectType *Sbk_SUEdge_TypeF(void)
{
    return _Sbk_SUEdge_Type;
}

static PyType_Slot Sbk_SUEdge_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUEdge_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUEdge_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUEdge_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUEdge_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUEdge_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUEdge_spec = {
    "suapi.SUEdge",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUEdge_slots
};

} //extern "C"

static void *Sbk_SUEdge_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUEdge *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUEdge_PythonToCpp_SUEdge_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUEdge_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUEdge_PythonToCpp_SUEdge_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUEdge_TypeF())))
        return SUEdge_PythonToCpp_SUEdge_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUEdge_PTR_CppToPython_SUEdge(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUEdge *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUEdge_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUEdge_SignatureStrings[] = {
    "suapi.SUEdge.GetEndVertex()->suapi.SUVertex",
    "suapi.SUEdge.GetSmooth()->bool",
    "suapi.SUEdge.GetSoft()->bool",
    "suapi.SUEdge.GetStartVertex()->suapi.SUVertex",
    "suapi.SUEdge()",
    nullptr}; // Sentinel

void init_SUEdge(PyObject *module)
{
    _Sbk_SUEdge_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUEdge",
        "SUEdge*",
        &Sbk_SUEdge_spec,
        SUEdge_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUEdge >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUDRAWINGELEMENT_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUEDGE_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUEdge_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUEdge_TypeF(),
        SUEdge_PythonToCpp_SUEdge_PTR,
        is_SUEdge_PythonToCpp_SUEdge_PTR_Convertible,
        SUEdge_PTR_CppToPython_SUEdge);

    Shiboken::Conversions::registerConverterName(converter, "SUEdge");
    Shiboken::Conversions::registerConverterName(converter, "SUEdge*");
    Shiboken::Conversions::registerConverterName(converter, "SUEdge&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEdge).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEdgeWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUEdge_TypeF(), &Sbk_SUEdge_typeDiscovery);


}
