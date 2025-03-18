
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "sutexture_wrapper.h"

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

void SUTextureWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUTextureWrapper::SUTextureWrapper() : SUTexture()
{
    resetPyMethodCache();
    // ... middle
}

SUTextureWrapper::~SUTextureWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUTextureFunc_GetData(PyObject *self)
{
    ::SUTexture *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUTexture *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUTEXTURE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetData()
            // Begin code injection

            return PyByteArray_FromStringAndSize(cppSelf->GetImageData().data(), cppSelf->GetImageDataSize());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUTextureFunc_GetFileName(PyObject *self)
{
    ::SUTexture *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUTexture *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUTEXTURE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetFileName()
            std::wstring cppResult = cppSelf->GetFileName();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUTextureFunc_GetImageDataSize(PyObject *self)
{
    ::SUTexture *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUTexture *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUTEXTURE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetImageDataSize()
            int cppResult = cppSelf->GetImageDataSize();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUTextureFunc_GetScaleU(PyObject *self)
{
    ::SUTexture *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUTexture *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUTEXTURE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetScaleU()
            double cppResult = cppSelf->GetScaleU();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUTextureFunc_GetScaleV(PyObject *self)
{
    ::SUTexture *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUTexture *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUTEXTURE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetScaleV()
            double cppResult = cppSelf->GetScaleV();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static int
Sbk_SUTexture_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUTexture >()))
        return -1;

    ::SUTextureWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUTexture()
            cptr = new ::SUTextureWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUTexture >(), cptr)) {
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

static PyObject *Sbk_SUTextureFunc_WriteToFile(PyObject *self, PyObject *pyArg)
{
    ::SUTexture *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUTexture *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUTEXTURE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SUTexture::WriteToFile(std::string)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArg)))) {
        overloadId = 0; // WriteToFile(std::string)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUTextureFunc_WriteToFile_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // WriteToFile(std::string)
            bool cppResult = cppSelf->WriteToFile(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_SUTextureFunc_WriteToFile_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUTexture.WriteToFile");
        return {};
}

static PyMethodDef Sbk_SUTexture_methods[] = {
    {"GetData", reinterpret_cast<PyCFunction>(Sbk_SUTextureFunc_GetData), METH_NOARGS},
    {"GetFileName", reinterpret_cast<PyCFunction>(Sbk_SUTextureFunc_GetFileName), METH_NOARGS},
    {"GetImageDataSize", reinterpret_cast<PyCFunction>(Sbk_SUTextureFunc_GetImageDataSize), METH_NOARGS},
    {"GetScaleU", reinterpret_cast<PyCFunction>(Sbk_SUTextureFunc_GetScaleU), METH_NOARGS},
    {"GetScaleV", reinterpret_cast<PyCFunction>(Sbk_SUTextureFunc_GetScaleV), METH_NOARGS},
    {"WriteToFile", reinterpret_cast<PyCFunction>(Sbk_SUTextureFunc_WriteToFile), METH_O},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUTexture_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUTexture *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUTEXTURE_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUTextureWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUTexture_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUTexture_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUTexture_Type = nullptr;
static SbkObjectType *Sbk_SUTexture_TypeF(void)
{
    return _Sbk_SUTexture_Type;
}

static PyType_Slot Sbk_SUTexture_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUTexture_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUTexture_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUTexture_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUTexture_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUTexture_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUTexture_spec = {
    "suapi.SUTexture",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUTexture_slots
};

} //extern "C"

static void *Sbk_SUTexture_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUTexture *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUTexture_PythonToCpp_SUTexture_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUTexture_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUTexture_PythonToCpp_SUTexture_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUTexture_TypeF())))
        return SUTexture_PythonToCpp_SUTexture_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUTexture_PTR_CppToPython_SUTexture(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUTexture *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUTexture_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUTexture_SignatureStrings[] = {
    "suapi.SUTexture.GetData()->PyObject",
    "suapi.SUTexture.GetFileName()->std.wstring",
    "suapi.SUTexture.GetImageDataSize()->int",
    "suapi.SUTexture.GetScaleU()->double",
    "suapi.SUTexture.GetScaleV()->double",
    "suapi.SUTexture()",
    "suapi.SUTexture.WriteToFile(filepath:std.string)->bool",
    nullptr}; // Sentinel

void init_SUTexture(PyObject *module)
{
    _Sbk_SUTexture_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUTexture",
        "SUTexture*",
        &Sbk_SUTexture_spec,
        SUTexture_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUTexture >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITY_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUTEXTURE_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUTexture_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUTexture_TypeF(),
        SUTexture_PythonToCpp_SUTexture_PTR,
        is_SUTexture_PythonToCpp_SUTexture_PTR_Convertible,
        SUTexture_PTR_CppToPython_SUTexture);

    Shiboken::Conversions::registerConverterName(converter, "SUTexture");
    Shiboken::Conversions::registerConverterName(converter, "SUTexture*");
    Shiboken::Conversions::registerConverterName(converter, "SUTexture&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUTexture).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUTextureWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUTexture_TypeF(), &Sbk_SUTexture_typeDiscovery);


}
