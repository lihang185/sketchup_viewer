
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suentities_wrapper.h"

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

void SUEntitiesWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUEntitiesWrapper::SUEntitiesWrapper() : SUEntities()
{
    resetPyMethodCache();
    // ... middle
}

SUEntitiesWrapper::~SUEntitiesWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUEntitiesFunc_AddEdge(PyObject *self, PyObject *pyArg)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SUEntities::AddEdge(SUEdge*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUEDGE_IDX]), (pyArg)))) {
        overloadId = 0; // AddEdge(SUEdge*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUEntitiesFunc_AddEdge_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::SUEdge *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // AddEdge(SUEdge*)
            bool cppResult = cppSelf->AddEdge(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_SUEntitiesFunc_AddEdge_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUEntities.AddEdge");
        return {};
}

static PyObject *Sbk_SUEntitiesFunc_AddFace(PyObject *self, PyObject *pyArg)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SUEntities::AddFace(SUFace*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUFACE_IDX]), (pyArg)))) {
        overloadId = 0; // AddFace(SUFace*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUEntitiesFunc_AddFace_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::SUFace *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // AddFace(SUFace*)
            bool cppResult = cppSelf->AddFace(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_SUEntitiesFunc_AddFace_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUEntities.AddFace");
        return {};
}

static PyObject *Sbk_SUEntitiesFunc_AddInstance(PyObject *self, PyObject *pyArg)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SUEntities::AddInstance(SUComponentInstance*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX]), (pyArg)))) {
        overloadId = 0; // AddInstance(SUComponentInstance*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUEntitiesFunc_AddInstance_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::SUComponentInstance *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // AddInstance(SUComponentInstance*)
            bool cppResult = cppSelf->AddInstance(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_SUEntitiesFunc_AddInstance_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUEntities.AddInstance");
        return {};
}

static PyObject *Sbk_SUEntitiesFunc_EnumEdges(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // EnumEdges()
            SUEntityIterator * cppResult = cppSelf->EnumEdges();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITYITERATOR_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntitiesFunc_EnumFaces(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // EnumFaces()
            SUEntityIterator * cppResult = cppSelf->EnumFaces();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUENTITYITERATOR_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntitiesFunc_GetEdges(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetEdges()
            std::vector<SUEdge* > cppResult = cppSelf->GetEdges();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUEDGEPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntitiesFunc_GetFaces(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetFaces()
            std::vector<SUFace* > cppResult = cppSelf->GetFaces();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUFACEPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntitiesFunc_GetGroups(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetGroups()
            std::vector<SUComponentInstance* > cppResult = cppSelf->GetGroups();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTINSTANCEPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntitiesFunc_GetInstances(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetInstances()
            std::vector<SUComponentInstance* > cppResult = cppSelf->GetInstances();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTINSTANCEPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntitiesFunc_GetNumEdges(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNumEdges()
            int cppResult = cppSelf->GetNumEdges();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntitiesFunc_GetNumFaces(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNumFaces()
            int cppResult = cppSelf->GetNumFaces();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntitiesFunc_GetNumGroups(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNumGroups()
            int cppResult = cppSelf->GetNumGroups();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntitiesFunc_GetNumInstances(PyObject *self)
{
    ::SUEntities *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNumInstances()
            int cppResult = cppSelf->GetNumInstances();
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
Sbk_SUEntities_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUEntities >()))
        return -1;

    ::SUEntitiesWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUEntities()
            cptr = new ::SUEntitiesWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUEntities >(), cptr)) {
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

static PyMethodDef Sbk_SUEntities_methods[] = {
    {"AddEdge", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_AddEdge), METH_O},
    {"AddFace", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_AddFace), METH_O},
    {"AddInstance", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_AddInstance), METH_O},
    {"EnumEdges", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_EnumEdges), METH_NOARGS},
    {"EnumFaces", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_EnumFaces), METH_NOARGS},
    {"GetEdges", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_GetEdges), METH_NOARGS},
    {"GetFaces", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_GetFaces), METH_NOARGS},
    {"GetGroups", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_GetGroups), METH_NOARGS},
    {"GetInstances", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_GetInstances), METH_NOARGS},
    {"GetNumEdges", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_GetNumEdges), METH_NOARGS},
    {"GetNumFaces", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_GetNumFaces), METH_NOARGS},
    {"GetNumGroups", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_GetNumGroups), METH_NOARGS},
    {"GetNumInstances", reinterpret_cast<PyCFunction>(Sbk_SUEntitiesFunc_GetNumInstances), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUEntities_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUEntities *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITIES_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUEntitiesWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUEntities_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUEntities_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUEntities_Type = nullptr;
static SbkObjectType *Sbk_SUEntities_TypeF(void)
{
    return _Sbk_SUEntities_Type;
}

static PyType_Slot Sbk_SUEntities_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUEntities_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUEntities_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUEntities_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUEntities_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUEntities_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUEntities_spec = {
    "suapi.SUEntities",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUEntities_slots
};

} //extern "C"

static void *Sbk_SUEntities_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::SUEntity >()))
        return dynamic_cast< ::SUEntities *>(reinterpret_cast< ::SUEntity *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUEntities_PythonToCpp_SUEntities_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUEntities_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUEntities_PythonToCpp_SUEntities_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUEntities_TypeF())))
        return SUEntities_PythonToCpp_SUEntities_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUEntities_PTR_CppToPython_SUEntities(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUEntities *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUEntities_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUEntities_SignatureStrings[] = {
    "suapi.SUEntities.AddEdge(edge:suapi.SUEdge)->bool",
    "suapi.SUEntities.AddFace(face:suapi.SUFace)->bool",
    "suapi.SUEntities.AddInstance(inst:suapi.SUComponentInstance)->bool",
    "suapi.SUEntities.EnumEdges()->suapi.SUEntityIterator",
    "suapi.SUEntities.EnumFaces()->suapi.SUEntityIterator",
    "suapi.SUEntities.GetEdges()->std.vector[suapi.SUEdge]",
    "suapi.SUEntities.GetFaces()->std.vector[suapi.SUFace]",
    "suapi.SUEntities.GetGroups()->std.vector[suapi.SUComponentInstance]",
    "suapi.SUEntities.GetInstances()->std.vector[suapi.SUComponentInstance]",
    "suapi.SUEntities.GetNumEdges()->int",
    "suapi.SUEntities.GetNumFaces()->int",
    "suapi.SUEntities.GetNumGroups()->int",
    "suapi.SUEntities.GetNumInstances()->int",
    "suapi.SUEntities()",
    nullptr}; // Sentinel

void init_SUEntities(PyObject *module)
{
    _Sbk_SUEntities_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUEntities",
        "SUEntities*",
        &Sbk_SUEntities_spec,
        SUEntities_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUEntities >,
        reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUDRAWINGELEMENT_IDX]),
        0,
        0    );
    
    SbksuapiTypes[SBK_SUENTITIES_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUEntities_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUEntities_TypeF(),
        SUEntities_PythonToCpp_SUEntities_PTR,
        is_SUEntities_PythonToCpp_SUEntities_PTR_Convertible,
        SUEntities_PTR_CppToPython_SUEntities);

    Shiboken::Conversions::registerConverterName(converter, "SUEntities");
    Shiboken::Conversions::registerConverterName(converter, "SUEntities*");
    Shiboken::Conversions::registerConverterName(converter, "SUEntities&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEntities).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEntitiesWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_SUEntities_TypeF(), &Sbk_SUEntities_typeDiscovery);


}
