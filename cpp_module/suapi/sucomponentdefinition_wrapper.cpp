
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "sucomponentdefinition_wrapper.h"

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

void SUComponentDefinitionWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUComponentDefinitionWrapper::SUComponentDefinitionWrapper() : SUComponentDefinition()
{
    resetPyMethodCache();
    // ... middle
}

SUComponentDefinitionWrapper::~SUComponentDefinitionWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUComponentDefinitionFunc_Create(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // Create()
            SUComponentDefinition * cppResult = ::SUComponentDefinition::Create();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUComponentDefinitionFunc_CreateInstance(PyObject *self)
{
    ::SUComponentDefinition *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentDefinition *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // CreateInstance()
            SUComponentInstance * cppResult = cppSelf->CreateInstance();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUComponentDefinitionFunc_GetDescription(PyObject *self)
{
    ::SUComponentDefinition *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentDefinition *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetDescription()
            std::wstring cppResult = cppSelf->GetDescription();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUComponentDefinitionFunc_GetEntities(PyObject *self)
{
    ::SUComponentDefinition *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentDefinition *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetEntities()
            SUEntities * cppResult = cppSelf->GetEntities();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITIES_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUComponentDefinitionFunc_GetName(PyObject *self)
{
    ::SUComponentDefinition *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentDefinition *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetName()
            std::wstring cppResult = cppSelf->GetName();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUComponentDefinitionFunc_GetPath(PyObject *self)
{
    ::SUComponentDefinition *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentDefinition *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetPath()
            std::wstring cppResult = cppSelf->GetPath();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUComponentDefinitionFunc_IsInternal(PyObject *self)
{
    ::SUComponentDefinition *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentDefinition *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // IsInternal()
            bool cppResult = cppSelf->IsInternal();
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
Sbk_SUComponentDefinition_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUComponentDefinition >()))
        return -1;

    ::SUComponentDefinitionWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUComponentDefinition()
            cptr = new ::SUComponentDefinitionWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUComponentDefinition >(), cptr)) {
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

static PyMethodDef Sbk_SUComponentDefinition_methods[] = {
    {"Create", reinterpret_cast<PyCFunction>(Sbk_SUComponentDefinitionFunc_Create), METH_NOARGS|METH_STATIC},
    {"CreateInstance", reinterpret_cast<PyCFunction>(Sbk_SUComponentDefinitionFunc_CreateInstance), METH_NOARGS},
    {"GetDescription", reinterpret_cast<PyCFunction>(Sbk_SUComponentDefinitionFunc_GetDescription), METH_NOARGS},
    {"GetEntities", reinterpret_cast<PyCFunction>(Sbk_SUComponentDefinitionFunc_GetEntities), METH_NOARGS},
    {"GetName", reinterpret_cast<PyCFunction>(Sbk_SUComponentDefinitionFunc_GetName), METH_NOARGS},
    {"GetPath", reinterpret_cast<PyCFunction>(Sbk_SUComponentDefinitionFunc_GetPath), METH_NOARGS},
    {"IsInternal", reinterpret_cast<PyCFunction>(Sbk_SUComponentDefinitionFunc_IsInternal), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUComponentDefinition_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUComponentDefinition *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUComponentDefinitionWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUComponentDefinition_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUComponentDefinition_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUComponentDefinition_Type = nullptr;
static SbkObjectType *Sbk_SUComponentDefinition_TypeF(void)
{
    return _Sbk_SUComponentDefinition_Type;
}

static PyType_Slot Sbk_SUComponentDefinition_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUComponentDefinition_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUComponentDefinition_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUComponentDefinition_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUComponentDefinition_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUComponentDefinition_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUComponentDefinition_spec = {
    "suapi.SUComponentDefinition",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUComponentDefinition_slots
};

} //extern "C"

static void *Sbk_SUComponentDefinition_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUComponentDefinition *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUComponentDefinition_PythonToCpp_SUComponentDefinition_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUComponentDefinition_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUComponentDefinition_PythonToCpp_SUComponentDefinition_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUComponentDefinition_TypeF())))
        return SUComponentDefinition_PythonToCpp_SUComponentDefinition_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUComponentDefinition_PTR_CppToPython_SUComponentDefinition(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUComponentDefinition *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUComponentDefinition_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUComponentDefinition_SignatureStrings[] = {
    "suapi.SUComponentDefinition.Create()->suapi.SUComponentDefinition",
    "suapi.SUComponentDefinition.CreateInstance()->suapi.SUComponentInstance",
    "suapi.SUComponentDefinition.GetDescription()->std.wstring",
    "suapi.SUComponentDefinition.GetEntities()->suapi.SUEntities",
    "suapi.SUComponentDefinition.GetName()->std.wstring",
    "suapi.SUComponentDefinition.GetPath()->std.wstring",
    "suapi.SUComponentDefinition.IsInternal()->bool",
    "suapi.SUComponentDefinition()",
    nullptr}; // Sentinel

void init_SUComponentDefinition(PyObject *module)
{
    _Sbk_SUComponentDefinition_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUComponentDefinition",
        "SUComponentDefinition*",
        &Sbk_SUComponentDefinition_spec,
        SUComponentDefinition_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUComponentDefinition >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITIES_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUComponentDefinition_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUComponentDefinition_TypeF(),
        SUComponentDefinition_PythonToCpp_SUComponentDefinition_PTR,
        is_SUComponentDefinition_PythonToCpp_SUComponentDefinition_PTR_Convertible,
        SUComponentDefinition_PTR_CppToPython_SUComponentDefinition);

    Shiboken::Conversions::registerConverterName(converter, "SUComponentDefinition");
    Shiboken::Conversions::registerConverterName(converter, "SUComponentDefinition*");
    Shiboken::Conversions::registerConverterName(converter, "SUComponentDefinition&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUComponentDefinition).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUComponentDefinitionWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUComponentDefinition_TypeF(), &Sbk_SUComponentDefinition_typeDiscovery);


}
