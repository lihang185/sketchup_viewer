
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suuvhelper_wrapper.h"

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


// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUUVHelperFunc_GetBackTextureMatrix(PyObject *self)
{
    ::SUUVHelper *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUUVHelper *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUUVHELPER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetBackTextureMatrix()
            CMatrix33 cppResult = cppSelf->GetBackTextureMatrix();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUUVHelperFunc_GetFrontTextureMatrix(PyObject *self)
{
    ::SUUVHelper *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUUVHelper *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUUVHELPER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetFrontTextureMatrix()
            CMatrix33 cppResult = cppSelf->GetFrontTextureMatrix();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUUVHelperFunc_Release(PyObject *self)
{
    ::SUUVHelper *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUUVHelper *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUUVHELPER_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // Release()
            cppSelf->Release();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static int
Sbk_SUUVHelper_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUUVHelper >()))
        return -1;

    ::SUUVHelper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUUVHelper()
            cptr = new ::SUUVHelper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUUVHelper >(), cptr)) {
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

static PyMethodDef Sbk_SUUVHelper_methods[] = {
    {"GetBackTextureMatrix", reinterpret_cast<PyCFunction>(Sbk_SUUVHelperFunc_GetBackTextureMatrix), METH_NOARGS},
    {"GetFrontTextureMatrix", reinterpret_cast<PyCFunction>(Sbk_SUUVHelperFunc_GetFrontTextureMatrix), METH_NOARGS},
    {"Release", reinterpret_cast<PyCFunction>(Sbk_SUUVHelperFunc_Release), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_SUUVHelper_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUUVHelper_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUUVHelper_Type = nullptr;
static SbkObjectType *Sbk_SUUVHelper_TypeF(void)
{
    return _Sbk_SUUVHelper_Type;
}

static PyType_Slot Sbk_SUUVHelper_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUUVHelper_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUUVHelper_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUUVHelper_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUUVHelper_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUUVHelper_spec = {
    "suapi.SUUVHelper",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUUVHelper_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUUVHelper_PythonToCpp_SUUVHelper_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUUVHelper_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUUVHelper_PythonToCpp_SUUVHelper_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUUVHelper_TypeF())))
        return SUUVHelper_PythonToCpp_SUUVHelper_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUUVHelper_PTR_CppToPython_SUUVHelper(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUUVHelper *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUUVHelper_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUUVHelper_SignatureStrings[] = {
    "suapi.SUUVHelper.GetBackTextureMatrix()->suapi.CMatrix33",
    "suapi.SUUVHelper.GetFrontTextureMatrix()->suapi.CMatrix33",
    "suapi.SUUVHelper.Release()",
    "suapi.SUUVHelper()",
    nullptr}; // Sentinel

void init_SUUVHelper(PyObject *module)
{
    _Sbk_SUUVHelper_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUUVHelper",
        "SUUVHelper*",
        &Sbk_SUUVHelper_spec,
        SUUVHelper_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUUVHelper >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_SUUVHELPER_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUUVHelper_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUUVHelper_TypeF(),
        SUUVHelper_PythonToCpp_SUUVHelper_PTR,
        is_SUUVHelper_PythonToCpp_SUUVHelper_PTR_Convertible,
        SUUVHelper_PTR_CppToPython_SUUVHelper);

    Shiboken::Conversions::registerConverterName(converter, "SUUVHelper");
    Shiboken::Conversions::registerConverterName(converter, "SUUVHelper*");
    Shiboken::Conversions::registerConverterName(converter, "SUUVHelper&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUUVHelper).name());



}
