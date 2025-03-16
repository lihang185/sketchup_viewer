
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "sucomponentinstance_wrapper.h"

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

void SUComponentInstanceWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUComponentInstanceWrapper::SUComponentInstanceWrapper() : SUComponentInstance()
{
    resetPyMethodCache();
    // ... middle
}

SUComponentInstanceWrapper::~SUComponentInstanceWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUComponentInstanceFunc_GetDefinition(PyObject *self)
{
    ::SUComponentInstance *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentInstance *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetDefinition()
            SUComponentDefinition * cppResult = cppSelf->GetDefinition();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUComponentInstanceFunc_GetMaterial(PyObject *self)
{
    ::SUComponentInstance *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentInstance *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetMaterial()
            SUMaterial * cppResult = cppSelf->GetMaterial();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUMATERIAL_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUComponentInstanceFunc_GetTransform(PyObject *self)
{
    ::SUComponentInstance *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentInstance *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetTransform()
            CMatrix cppResult = cppSelf->GetTransform();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static int
Sbk_SUComponentInstance_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUComponentInstance >()))
        return -1;

    ::SUComponentInstanceWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUComponentInstance()
            cptr = new ::SUComponentInstanceWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUComponentInstance >(), cptr)) {
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

static PyObject *Sbk_SUComponentInstanceFunc_SetTransform(PyObject *self, PyObject *pyArg)
{
    ::SUComponentInstance *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUComponentInstance *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SUComponentInstance::SetTransform(CMatrix&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), (pyArg)))) {
        overloadId = 0; // SetTransform(CMatrix&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUComponentInstanceFunc_SetTransform_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::CMatrix cppArg0_local;
        ::CMatrix *cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // SetTransform(CMatrix&)
            cppSelf->SetTransform(*cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_SUComponentInstanceFunc_SetTransform_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUComponentInstance.SetTransform");
        return {};
}

static PyMethodDef Sbk_SUComponentInstance_methods[] = {
    {"GetDefinition", reinterpret_cast<PyCFunction>(Sbk_SUComponentInstanceFunc_GetDefinition), METH_NOARGS},
    {"GetMaterial", reinterpret_cast<PyCFunction>(Sbk_SUComponentInstanceFunc_GetMaterial), METH_NOARGS},
    {"GetTransform", reinterpret_cast<PyCFunction>(Sbk_SUComponentInstanceFunc_GetTransform), METH_NOARGS},
    {"SetTransform", reinterpret_cast<PyCFunction>(Sbk_SUComponentInstanceFunc_SetTransform), METH_O},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUComponentInstance_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUComponentInstance *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUComponentInstanceWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUComponentInstance_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUComponentInstance_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUComponentInstance_Type = nullptr;
static SbkObjectType *Sbk_SUComponentInstance_TypeF(void)
{
    return _Sbk_SUComponentInstance_Type;
}

static PyType_Slot Sbk_SUComponentInstance_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUComponentInstance_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUComponentInstance_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUComponentInstance_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUComponentInstance_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUComponentInstance_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUComponentInstance_spec = {
    "suapi.SUComponentInstance",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUComponentInstance_slots
};

} //extern "C"

static void *Sbk_SUComponentInstance_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUComponentInstance *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUComponentInstance_PythonToCpp_SUComponentInstance_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUComponentInstance_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUComponentInstance_PythonToCpp_SUComponentInstance_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUComponentInstance_TypeF())))
        return SUComponentInstance_PythonToCpp_SUComponentInstance_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUComponentInstance_PTR_CppToPython_SUComponentInstance(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUComponentInstance *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUComponentInstance_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUComponentInstance_SignatureStrings[] = {
    "suapi.SUComponentInstance.GetDefinition()->suapi.SUComponentDefinition",
    "suapi.SUComponentInstance.GetMaterial()->suapi.SUMaterial",
    "suapi.SUComponentInstance.GetTransform()->suapi.CMatrix",
    "suapi.SUComponentInstance()",
    "suapi.SUComponentInstance.SetTransform(m:suapi.CMatrix)",
    nullptr}; // Sentinel

void init_SUComponentInstance(PyObject *module)
{
    _Sbk_SUComponentInstance_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUComponentInstance",
        "SUComponentInstance*",
        &Sbk_SUComponentInstance_spec,
        SUComponentInstance_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUComponentInstance >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUDRAWINGELEMENT_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUComponentInstance_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUComponentInstance_TypeF(),
        SUComponentInstance_PythonToCpp_SUComponentInstance_PTR,
        is_SUComponentInstance_PythonToCpp_SUComponentInstance_PTR_Convertible,
        SUComponentInstance_PTR_CppToPython_SUComponentInstance);

    Shiboken::Conversions::registerConverterName(converter, "SUComponentInstance");
    Shiboken::Conversions::registerConverterName(converter, "SUComponentInstance*");
    Shiboken::Conversions::registerConverterName(converter, "SUComponentInstance&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUComponentInstance).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUComponentInstanceWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUComponentInstance_TypeF(), &Sbk_SUComponentInstance_typeDiscovery);


}
