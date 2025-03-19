
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suattributedictionary_wrapper.h"

// inner classes

// Extra includes
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


// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUAttributeDictionaryFunc_GetKeys(PyObject *self)
{
    ::SUAttributeDictionary *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUAttributeDictionary *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUATTRIBUTEDICTIONARY_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetKeys()
            std::vector<std::wstring > cppResult = cppSelf->GetKeys();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_STD_WSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUAttributeDictionaryFunc_GetName(PyObject *self)
{
    ::SUAttributeDictionary *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUAttributeDictionary *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUATTRIBUTEDICTIONARY_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_SUAttributeDictionaryFunc_GetNumKeys(PyObject *self)
{
    ::SUAttributeDictionary *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUAttributeDictionary *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUATTRIBUTEDICTIONARY_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNumKeys()
            int cppResult = cppSelf->GetNumKeys();
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
Sbk_SUAttributeDictionary_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUAttributeDictionary >()))
        return -1;

    ::SUAttributeDictionary *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUAttributeDictionary()
            cptr = new ::SUAttributeDictionary();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUAttributeDictionary >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyMethodDef Sbk_SUAttributeDictionary_methods[] = {
    {"GetKeys", reinterpret_cast<PyCFunction>(Sbk_SUAttributeDictionaryFunc_GetKeys), METH_NOARGS},
    {"GetName", reinterpret_cast<PyCFunction>(Sbk_SUAttributeDictionaryFunc_GetName), METH_NOARGS},
    {"GetNumKeys", reinterpret_cast<PyCFunction>(Sbk_SUAttributeDictionaryFunc_GetNumKeys), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_SUAttributeDictionary_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUAttributeDictionary_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUAttributeDictionary_Type = nullptr;
static SbkObjectType *Sbk_SUAttributeDictionary_TypeF(void)
{
    return _Sbk_SUAttributeDictionary_Type;
}

static PyType_Slot Sbk_SUAttributeDictionary_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUAttributeDictionary_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUAttributeDictionary_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUAttributeDictionary_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUAttributeDictionary_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUAttributeDictionary_spec = {
    "suapi.SUAttributeDictionary",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUAttributeDictionary_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUAttributeDictionary_PythonToCpp_SUAttributeDictionary_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUAttributeDictionary_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUAttributeDictionary_PythonToCpp_SUAttributeDictionary_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUAttributeDictionary_TypeF())))
        return SUAttributeDictionary_PythonToCpp_SUAttributeDictionary_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUAttributeDictionary_PTR_CppToPython_SUAttributeDictionary(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUAttributeDictionary *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUAttributeDictionary_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUAttributeDictionary_SignatureStrings[] = {
    "suapi.SUAttributeDictionary.GetKeys()->std.vector[std.wstring]",
    "suapi.SUAttributeDictionary.GetName()->std.wstring",
    "suapi.SUAttributeDictionary.GetNumKeys()->int",
    "suapi.SUAttributeDictionary()",
    nullptr}; // Sentinel

void init_SUAttributeDictionary(PyObject *module)
{
    _Sbk_SUAttributeDictionary_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUAttributeDictionary",
        "SUAttributeDictionary*",
        &Sbk_SUAttributeDictionary_spec,
        SUAttributeDictionary_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUAttributeDictionary >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_SUATTRIBUTEDICTIONARY_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUAttributeDictionary_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUAttributeDictionary_TypeF(),
        SUAttributeDictionary_PythonToCpp_SUAttributeDictionary_PTR,
        is_SUAttributeDictionary_PythonToCpp_SUAttributeDictionary_PTR_Convertible,
        SUAttributeDictionary_PTR_CppToPython_SUAttributeDictionary);

    Shiboken::Conversions::registerConverterName(converter, "SUAttributeDictionary");
    Shiboken::Conversions::registerConverterName(converter, "SUAttributeDictionary*");
    Shiboken::Conversions::registerConverterName(converter, "SUAttributeDictionary&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUAttributeDictionary).name());



}
