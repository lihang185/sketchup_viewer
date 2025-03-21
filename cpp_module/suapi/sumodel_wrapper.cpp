
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "sumodel_wrapper.h"

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


// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_SUModelFunc_AddComponentDefinitions(PyObject *self, PyObject *pyArg)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SUModel::AddComponentDefinitions(SUComponentDefinition*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX]), (pyArg)))) {
        overloadId = 0; // AddComponentDefinitions(SUComponentDefinition*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUModelFunc_AddComponentDefinitions_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::SUComponentDefinition *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // AddComponentDefinitions(SUComponentDefinition*)
            bool cppResult = cppSelf->AddComponentDefinitions(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_SUModelFunc_AddComponentDefinitions_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUModel.AddComponentDefinitions");
        return {};
}

static PyObject *Sbk_SUModelFunc_AddMaterial(PyObject *self, PyObject *pyArg)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SUModel::AddMaterial(SUMaterial*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUMATERIAL_IDX]), (pyArg)))) {
        overloadId = 0; // AddMaterial(SUMaterial*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUModelFunc_AddMaterial_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::SUMaterial *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // AddMaterial(SUMaterial*)
            bool cppResult = cppSelf->AddMaterial(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_SUModelFunc_AddMaterial_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUModel.AddMaterial");
        return {};
}

static PyObject *Sbk_SUModelFunc_GetComponentDefinitionList(PyObject *self)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetComponentDefinitionList()
            std::vector<SUComponentDefinition* > cppResult = cppSelf->GetComponentDefinitionList();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTDEFINITIONPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUModelFunc_GetEntities(PyObject *self)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_SUModelFunc_GetGroupDefinitionList(PyObject *self)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetGroupDefinitionList()
            std::vector<SUComponentDefinition* > cppResult = cppSelf->GetGroupDefinitionList();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTDEFINITIONPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUModelFunc_GetMaterialList(PyObject *self)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetMaterialList()
            std::vector<SUMaterial* > cppResult = cppSelf->GetMaterialList();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUMATERIALPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUModelFunc_GetName(PyObject *self)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetName()
            std::string cppResult = cppSelf->GetName();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUModelFunc_LoadFromBuffer(PyObject *self, PyObject *pyArg)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SUModel::LoadFromBuffer(PyObject*)
    if (PyObject_Check(pyArg)) {
        overloadId = 0; // LoadFromBuffer(PyObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUModelFunc_LoadFromBuffer_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // LoadFromBuffer(PyObject*)
            // Begin code injection

            size_t buffer_size = PyByteArray_Size(pyArg);
            unsigned char* pbuf = (unsigned char*)malloc(buffer_size);
            void* data = PyByteArray_AsString(pyArg);
            memcpy(pbuf, data, buffer_size);
            SUModel* model = SUModel::cLoadFromBuffer(pbuf,buffer_size);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUMODEL_IDX]), model);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_SUModelFunc_LoadFromBuffer_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUModel.LoadFromBuffer");
        return {};
}

static PyObject *Sbk_SUModelFunc_LoadFromFile(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static SUModel::LoadFromFile(std::string)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArg)))) {
        overloadId = 0; // LoadFromFile(std::string)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUModelFunc_LoadFromFile_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // LoadFromFile(std::string)
            SUModel * cppResult = ::SUModel::LoadFromFile(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUMODEL_IDX]), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_SUModelFunc_LoadFromFile_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUModel.LoadFromFile");
        return {};
}

static PyObject *Sbk_SUModelFunc_Release(PyObject *self)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));

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
Sbk_SUModel_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUModel >()))
        return -1;

    ::SUModel *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUModel()
            cptr = new ::SUModel();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUModel >(), cptr)) {
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

static PyObject *Sbk_SUModelFunc_SaveToFile(PyObject *self, PyObject *pyArg)
{
    ::SUModel *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUModel *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUMODEL_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: SUModel::SaveToFile(std::string&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArg)))) {
        overloadId = 0; // SaveToFile(std::string&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_SUModelFunc_SaveToFile_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // SaveToFile(std::string&)
            bool cppResult = cppSelf->SaveToFile(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_SUModelFunc_SaveToFile_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.SUModel.SaveToFile");
        return {};
}

static PyMethodDef Sbk_SUModel_methods[] = {
    {"AddComponentDefinitions", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_AddComponentDefinitions), METH_O},
    {"AddMaterial", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_AddMaterial), METH_O},
    {"GetComponentDefinitionList", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_GetComponentDefinitionList), METH_NOARGS},
    {"GetEntities", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_GetEntities), METH_NOARGS},
    {"GetGroupDefinitionList", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_GetGroupDefinitionList), METH_NOARGS},
    {"GetMaterialList", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_GetMaterialList), METH_NOARGS},
    {"GetName", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_GetName), METH_NOARGS},
    {"LoadFromBuffer", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_LoadFromBuffer), METH_O},
    {"LoadFromFile", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_LoadFromFile), METH_O|METH_STATIC},
    {"Release", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_Release), METH_NOARGS},
    {"SaveToFile", reinterpret_cast<PyCFunction>(Sbk_SUModelFunc_SaveToFile), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_SUModel_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUModel_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUModel_Type = nullptr;
static SbkObjectType *Sbk_SUModel_TypeF(void)
{
    return _Sbk_SUModel_Type;
}

static PyType_Slot Sbk_SUModel_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUModel_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUModel_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUModel_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUModel_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUModel_spec = {
    "suapi.SUModel",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUModel_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUModel_PythonToCpp_SUModel_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUModel_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUModel_PythonToCpp_SUModel_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUModel_TypeF())))
        return SUModel_PythonToCpp_SUModel_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUModel_PTR_CppToPython_SUModel(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUModel *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUModel_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUModel_SignatureStrings[] = {
    "suapi.SUModel.AddComponentDefinitions(comp:suapi.SUComponentDefinition)->bool",
    "suapi.SUModel.AddMaterial(mat:suapi.SUMaterial)->bool",
    "suapi.SUModel.GetComponentDefinitionList()->std.vector[suapi.SUComponentDefinition]",
    "suapi.SUModel.GetEntities()->suapi.SUEntities",
    "suapi.SUModel.GetGroupDefinitionList()->std.vector[suapi.SUComponentDefinition]",
    "suapi.SUModel.GetMaterialList()->std.vector[suapi.SUMaterial]",
    "suapi.SUModel.GetName()->std.string",
    "suapi.SUModel.LoadFromBuffer(arg__1:PyObject)->suapi.SUModel",
    "suapi.SUModel.LoadFromFile(file_path:std.string)->suapi.SUModel",
    "suapi.SUModel.Release()",
    "suapi.SUModel()",
    "suapi.SUModel.SaveToFile(filepath:std.string)->bool",
    nullptr}; // Sentinel

void init_SUModel(PyObject *module)
{
    _Sbk_SUModel_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUModel",
        "SUModel*",
        &Sbk_SUModel_spec,
        SUModel_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUModel >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_SUMODEL_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUModel_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUModel_TypeF(),
        SUModel_PythonToCpp_SUModel_PTR,
        is_SUModel_PythonToCpp_SUModel_PTR_Convertible,
        SUModel_PTR_CppToPython_SUModel);

    Shiboken::Conversions::registerConverterName(converter, "SUModel");
    Shiboken::Conversions::registerConverterName(converter, "SUModel*");
    Shiboken::Conversions::registerConverterName(converter, "SUModel&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUModel).name());



}
