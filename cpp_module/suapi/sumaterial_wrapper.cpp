
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "sumaterial_wrapper.h"

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

void SUMaterialWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUMaterialWrapper::SUMaterialWrapper() : SUMaterial()
{
    resetPyMethodCache();
    // ... middle
}

SUMaterialWrapper::~SUMaterialWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUMaterialFunc_Create(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // Create()
            SUMaterial * cppResult = ::SUMaterial::Create();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUMATERIAL_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUMaterialFunc_GetColor(PyObject *self)
{
    ::SUMaterial *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUMaterial *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMATERIAL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetColor()
            CVector3D cppResult = cppSelf->GetColor();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUMaterialFunc_GetName(PyObject *self)
{
    ::SUMaterial *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUMaterial *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMATERIAL_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_SUMaterialFunc_GetOpacity(PyObject *self)
{
    ::SUMaterial *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUMaterial *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMATERIAL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetOpacity()
            double cppResult = cppSelf->GetOpacity();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUMaterialFunc_GetTexture(PyObject *self)
{
    ::SUMaterial *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUMaterial *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMATERIAL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetTexture()
            SUTexture * cppResult = cppSelf->GetTexture();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUTEXTURE_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUMaterialFunc_GetUseOpacity(PyObject *self)
{
    ::SUMaterial *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUMaterial *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMATERIAL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetUseOpacity()
            bool cppResult = cppSelf->GetUseOpacity();
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
Sbk_SUMaterial_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUMaterial >()))
        return -1;

    ::SUMaterialWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUMaterial()
            cptr = new ::SUMaterialWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUMaterial >(), cptr)) {
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

static PyMethodDef Sbk_SUMaterial_methods[] = {
    {"Create", reinterpret_cast<PyCFunction>(Sbk_SUMaterialFunc_Create), METH_NOARGS|METH_STATIC},
    {"GetColor", reinterpret_cast<PyCFunction>(Sbk_SUMaterialFunc_GetColor), METH_NOARGS},
    {"GetName", reinterpret_cast<PyCFunction>(Sbk_SUMaterialFunc_GetName), METH_NOARGS},
    {"GetOpacity", reinterpret_cast<PyCFunction>(Sbk_SUMaterialFunc_GetOpacity), METH_NOARGS},
    {"GetTexture", reinterpret_cast<PyCFunction>(Sbk_SUMaterialFunc_GetTexture), METH_NOARGS},
    {"GetUseOpacity", reinterpret_cast<PyCFunction>(Sbk_SUMaterialFunc_GetUseOpacity), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUMaterial_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUMaterial *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMATERIAL_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUMaterialWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUMaterial_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUMaterial_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUMaterial_Type = nullptr;
static SbkObjectType *Sbk_SUMaterial_TypeF(void)
{
    return _Sbk_SUMaterial_Type;
}

static PyType_Slot Sbk_SUMaterial_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUMaterial_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUMaterial_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUMaterial_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUMaterial_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUMaterial_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUMaterial_spec = {
    "suapi.SUMaterial",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUMaterial_slots
};

} //extern "C"

static void *Sbk_SUMaterial_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUMaterial *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUMaterial_PythonToCpp_SUMaterial_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUMaterial_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUMaterial_PythonToCpp_SUMaterial_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUMaterial_TypeF())))
        return SUMaterial_PythonToCpp_SUMaterial_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUMaterial_PTR_CppToPython_SUMaterial(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUMaterial *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUMaterial_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUMaterial_SignatureStrings[] = {
    "suapi.SUMaterial.Create()->suapi.SUMaterial",
    "suapi.SUMaterial.GetColor()->suapi.CVector3D",
    "suapi.SUMaterial.GetName()->std.wstring",
    "suapi.SUMaterial.GetOpacity()->double",
    "suapi.SUMaterial.GetTexture()->suapi.SUTexture",
    "suapi.SUMaterial.GetUseOpacity()->bool",
    "suapi.SUMaterial()",
    nullptr}; // Sentinel

void init_SUMaterial(PyObject *module)
{
    _Sbk_SUMaterial_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUMaterial",
        "SUMaterial*",
        &Sbk_SUMaterial_spec,
        SUMaterial_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUMaterial >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITY_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUMATERIAL_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUMaterial_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUMaterial_TypeF(),
        SUMaterial_PythonToCpp_SUMaterial_PTR,
        is_SUMaterial_PythonToCpp_SUMaterial_PTR_Convertible,
        SUMaterial_PTR_CppToPython_SUMaterial);

    Shiboken::Conversions::registerConverterName(converter, "SUMaterial");
    Shiboken::Conversions::registerConverterName(converter, "SUMaterial*");
    Shiboken::Conversions::registerConverterName(converter, "SUMaterial&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUMaterial).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUMaterialWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUMaterial_TypeF(), &Sbk_SUMaterial_typeDiscovery);


}
