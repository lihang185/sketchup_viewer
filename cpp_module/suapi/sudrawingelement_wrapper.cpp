
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "sudrawingelement_wrapper.h"

// inner classes

// Extra includes


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

void SUDrawingElementWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUDrawingElementWrapper::SUDrawingElementWrapper() : SUDrawingElement()
{
    resetPyMethodCache();
    // ... middle
}

SUDrawingElementWrapper::~SUDrawingElementWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUDrawingElementFunc_GetHidden(PyObject *self)
{
    ::SUDrawingElement *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUDrawingElement *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUDRAWINGELEMENT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetHidden()
            bool cppResult = cppSelf->GetHidden();
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
Sbk_SUDrawingElement_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUDrawingElement >()))
        return -1;

    ::SUDrawingElementWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUDrawingElement()
            cptr = new ::SUDrawingElementWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUDrawingElement >(), cptr)) {
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

static PyMethodDef Sbk_SUDrawingElement_methods[] = {
    {"GetHidden", reinterpret_cast<PyCFunction>(Sbk_SUDrawingElementFunc_GetHidden), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUDrawingElement_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUDrawingElement *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUDRAWINGELEMENT_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUDrawingElementWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUDrawingElement_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUDrawingElement_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUDrawingElement_Type = nullptr;
static SbkObjectType *Sbk_SUDrawingElement_TypeF(void)
{
    return _Sbk_SUDrawingElement_Type;
}

static PyType_Slot Sbk_SUDrawingElement_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUDrawingElement_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUDrawingElement_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUDrawingElement_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUDrawingElement_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUDrawingElement_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUDrawingElement_spec = {
    "suapi.SUDrawingElement",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUDrawingElement_slots
};

} //extern "C"

static void *Sbk_SUDrawingElement_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUDrawingElement *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUDrawingElement_PythonToCpp_SUDrawingElement_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUDrawingElement_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUDrawingElement_PythonToCpp_SUDrawingElement_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUDrawingElement_TypeF())))
        return SUDrawingElement_PythonToCpp_SUDrawingElement_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUDrawingElement_PTR_CppToPython_SUDrawingElement(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUDrawingElement *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUDrawingElement_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUDrawingElement_SignatureStrings[] = {
    "suapi.SUDrawingElement.GetHidden()->bool",
    "suapi.SUDrawingElement()",
    nullptr}; // Sentinel

void init_SUDrawingElement(PyObject *module)
{
    _Sbk_SUDrawingElement_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUDrawingElement",
        "SUDrawingElement*",
        &Sbk_SUDrawingElement_spec,
        SUDrawingElement_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUDrawingElement >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITY_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUDRAWINGELEMENT_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUDrawingElement_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUDrawingElement_TypeF(),
        SUDrawingElement_PythonToCpp_SUDrawingElement_PTR,
        is_SUDrawingElement_PythonToCpp_SUDrawingElement_PTR_Convertible,
        SUDrawingElement_PTR_CppToPython_SUDrawingElement);

    Shiboken::Conversions::registerConverterName(converter, "SUDrawingElement");
    Shiboken::Conversions::registerConverterName(converter, "SUDrawingElement*");
    Shiboken::Conversions::registerConverterName(converter, "SUDrawingElement&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUDrawingElement).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUDrawingElementWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUDrawingElement_TypeF(), &Sbk_SUDrawingElement_typeDiscovery);


}
