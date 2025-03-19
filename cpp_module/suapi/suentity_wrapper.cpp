
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suentity_wrapper.h"

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

void SUEntityWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUEntityWrapper::SUEntityWrapper() : SUEntity()
{
    resetPyMethodCache();
    // ... middle
}

SUEntityWrapper::~SUEntityWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUEntityFunc_GetAttributeDictionaries(PyObject *self)
{
    ::SUEntity *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntity *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITY_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetAttributeDictionaries()
            std::vector<SUAttributeDictionary* > cppResult = cppSelf->GetAttributeDictionaries();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUATTRIBUTEDICTIONARYPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntityFunc_GetID(PyObject *self)
{
    ::SUEntity *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntity *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITY_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetID()
            int cppResult = cppSelf->GetID();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntityFunc_GetNumAttributeDictionaries(PyObject *self)
{
    ::SUEntity *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntity *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITY_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNumAttributeDictionaries()
            int cppResult = cppSelf->GetNumAttributeDictionaries();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntityFunc_GetType(PyObject *self)
{
    ::SUEntity *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntity *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITY_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetType()
            int cppResult = cppSelf->GetType();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static int
Sbk_SUEntity_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUEntity >()))
        return -1;

    ::SUEntityWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUEntity()
            cptr = new ::SUEntityWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUEntity >(), cptr)) {
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

static PyMethodDef Sbk_SUEntity_methods[] = {
    {"GetAttributeDictionaries", reinterpret_cast<PyCFunction>(Sbk_SUEntityFunc_GetAttributeDictionaries), METH_NOARGS},
    {"GetID", reinterpret_cast<PyCFunction>(Sbk_SUEntityFunc_GetID), METH_NOARGS},
    {"GetNumAttributeDictionaries", reinterpret_cast<PyCFunction>(Sbk_SUEntityFunc_GetNumAttributeDictionaries), METH_NOARGS},
    {"GetType", reinterpret_cast<PyCFunction>(Sbk_SUEntityFunc_GetType), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUEntity_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUEntity *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITY_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUEntityWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUEntity_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUEntity_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUEntity_Type = nullptr;
static SbkObjectType *Sbk_SUEntity_TypeF(void)
{
    return _Sbk_SUEntity_Type;
}

static PyType_Slot Sbk_SUEntity_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUEntity_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUEntity_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUEntity_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUEntity_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUEntity_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUEntity_spec = {
    "suapi.SUEntity",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUEntity_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUEntity_PythonToCpp_SUEntity_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUEntity_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUEntity_PythonToCpp_SUEntity_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUEntity_TypeF())))
        return SUEntity_PythonToCpp_SUEntity_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUEntity_PTR_CppToPython_SUEntity(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUEntity *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUEntity_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUEntity_SignatureStrings[] = {
    "suapi.SUEntity.GetAttributeDictionaries()->std.vector[suapi.SUAttributeDictionary]",
    "suapi.SUEntity.GetID()->int",
    "suapi.SUEntity.GetNumAttributeDictionaries()->int",
    "suapi.SUEntity.GetType()->int",
    "suapi.SUEntity()",
    nullptr}; // Sentinel

void init_SUEntity(PyObject *module)
{
    _Sbk_SUEntity_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUEntity",
        "SUEntity*",
        &Sbk_SUEntity_spec,
        SUEntity_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUEntity >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_SUENTITY_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUEntity_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUEntity_TypeF(),
        SUEntity_PythonToCpp_SUEntity_PTR,
        is_SUEntity_PythonToCpp_SUEntity_PTR_Convertible,
        SUEntity_PTR_CppToPython_SUEntity);

    Shiboken::Conversions::registerConverterName(converter, "SUEntity");
    Shiboken::Conversions::registerConverterName(converter, "SUEntity*");
    Shiboken::Conversions::registerConverterName(converter, "SUEntity&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEntity).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEntityWrapper).name());



}
