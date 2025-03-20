
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "cmatrix33_wrapper.h"

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
static int
Sbk_CMatrix33_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::CMatrix33 >()))
        return -1;

    ::CMatrix33 *cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "CMatrix33", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: CMatrix33::CMatrix33()
    // 1: CMatrix33::CMatrix33(CMatrix33)
    if (numArgs == 0) {
        overloadId = 0; // CMatrix33()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), (pyArgs[0])))) {
        overloadId = 1; // CMatrix33(CMatrix33)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrix33_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // CMatrix33()
        {

            if (!PyErr_Occurred()) {
                // CMatrix33()
                cptr = new ::CMatrix33();
            }
            break;
        }
        case 1: // CMatrix33(const CMatrix33 & CMatrix33)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::CMatrix33 cppArg0_local;
            ::CMatrix33 *cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // CMatrix33(CMatrix33)
                cptr = new ::CMatrix33(*cppArg0);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::CMatrix33 >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_CMatrix33_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_CMatrix33_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CMatrix33");
        return -1;
}

static PyObject *Sbk_CMatrix33Func_fromScale(PyObject *self, PyObject *args)
{
    ::CMatrix33 *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix33 *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX33_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "fromScale", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: CMatrix33::fromScale(double,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // fromScale(double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrix33Func_fromScale_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromScale(double,double)
            CMatrix33 & cppResult = cppSelf->fromScale(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrix33Func_fromScale_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CMatrix33.fromScale");
        return {};
}

static PyObject *Sbk_CMatrix33Func_get(PyObject *self, PyObject *args)
{
    ::CMatrix33 *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix33 *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX33_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "get", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: CMatrix33::get(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // get(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrix33Func_get_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // get(int,int)
            double cppResult = cppSelf->get(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrix33Func_get_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CMatrix33.get");
        return {};
}

static PyObject *Sbk_CMatrix33Func_get_data(PyObject *self)
{
    ::CMatrix33 *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix33 *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX33_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // get_data()
            std::vector<double > cppResult = cppSelf->get_data();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_DOUBLE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_CMatrix33Func_multiply(PyObject *self, PyObject *pyArg)
{
    ::CMatrix33 *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix33 *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX33_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: CMatrix33::multiply(CMatrix33&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), (pyArg)))) {
        overloadId = 0; // multiply(CMatrix33&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrix33Func_multiply_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::CMatrix33 cppArg0_local;
        ::CMatrix33 *cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // multiply(CMatrix33&)
            CMatrix33 cppResult = cppSelf->multiply(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrix33Func_multiply_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix33.multiply");
        return {};
}

static PyObject *Sbk_CMatrix33Func_normalize(PyObject *self)
{
    ::CMatrix33 *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix33 *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX33_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // normalize()
            bool cppResult = cppSelf->normalize();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_CMatrix33Func_reversed(PyObject *self)
{
    ::CMatrix33 *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix33 *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX33_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reversed()
            CMatrix33 cppResult = cppSelf->reversed();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_CMatrix33___copy__(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    ::CMatrix33 &cppSelf =  *reinterpret_cast< ::CMatrix33 *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX33_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX33_IDX]), &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyMethodDef Sbk_CMatrix33_methods[] = {
    {"fromScale", reinterpret_cast<PyCFunction>(Sbk_CMatrix33Func_fromScale), METH_VARARGS},
    {"get", reinterpret_cast<PyCFunction>(Sbk_CMatrix33Func_get), METH_VARARGS},
    {"get_data", reinterpret_cast<PyCFunction>(Sbk_CMatrix33Func_get_data), METH_NOARGS},
    {"multiply", reinterpret_cast<PyCFunction>(Sbk_CMatrix33Func_multiply), METH_O},
    {"normalize", reinterpret_cast<PyCFunction>(Sbk_CMatrix33Func_normalize), METH_NOARGS},
    {"reversed", reinterpret_cast<PyCFunction>(Sbk_CMatrix33Func_reversed), METH_NOARGS},

    {"__copy__", reinterpret_cast<PyCFunction>(Sbk_CMatrix33___copy__), METH_NOARGS},
    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_CMatrix33_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_CMatrix33_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_CMatrix33_Type = nullptr;
static SbkObjectType *Sbk_CMatrix33_TypeF(void)
{
    return _Sbk_CMatrix33_Type;
}

static PyType_Slot Sbk_CMatrix33_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_CMatrix33_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_CMatrix33_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_CMatrix33_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_CMatrix33_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_CMatrix33_spec = {
    "suapi.CMatrix33",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_CMatrix33_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void CMatrix33_PythonToCpp_CMatrix33_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_CMatrix33_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_CMatrix33_PythonToCpp_CMatrix33_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CMatrix33_TypeF())))
        return CMatrix33_PythonToCpp_CMatrix33_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *CMatrix33_PTR_CppToPython_CMatrix33(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::CMatrix33 *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_CMatrix33_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// C++ to Python copy conversion.
static PyObject *CMatrix33_COPY_CppToPython_CMatrix33(const void *cppIn) {
    return Shiboken::Object::newObject(Sbk_CMatrix33_TypeF(), new ::CMatrix33(*reinterpret_cast<const ::CMatrix33 *>(cppIn)), true, true);
}

// Python to C++ copy conversion.
static void CMatrix33_PythonToCpp_CMatrix33_COPY(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::CMatrix33 *>(cppOut) = *reinterpret_cast< ::CMatrix33 *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX33_IDX], reinterpret_cast<SbkObject *>(pyIn)));
}
static PythonToCppFunc is_CMatrix33_PythonToCpp_CMatrix33_COPY_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CMatrix33_TypeF())))
        return CMatrix33_PythonToCpp_CMatrix33_COPY;
    return {};
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *CMatrix33_SignatureStrings[] = {
    "1:suapi.CMatrix33()",
    "0:suapi.CMatrix33(CMatrix33:suapi.CMatrix33)",
    "suapi.CMatrix33.fromScale(u_scale:double,v_scale:double)->suapi.CMatrix33",
    "suapi.CMatrix33.get(i:int,j:int)->double",
    "suapi.CMatrix33.get_data()->std.vector[double]",
    "suapi.CMatrix33.multiply(R:suapi.CMatrix33)->suapi.CMatrix33",
    "suapi.CMatrix33.normalize()->bool",
    "suapi.CMatrix33.reversed()->suapi.CMatrix33",
    "suapi.CMatrix33.__copy__()",
    nullptr}; // Sentinel

void init_CMatrix33(PyObject *module)
{
    _Sbk_CMatrix33_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "CMatrix33",
        "CMatrix33",
        &Sbk_CMatrix33_spec,
        CMatrix33_SignatureStrings,
        &Shiboken::callCppDestructor< ::CMatrix33 >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_CMATRIX33_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_CMatrix33_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_CMatrix33_TypeF(),
        CMatrix33_PythonToCpp_CMatrix33_PTR,
        is_CMatrix33_PythonToCpp_CMatrix33_PTR_Convertible,
        CMatrix33_PTR_CppToPython_CMatrix33,
        CMatrix33_COPY_CppToPython_CMatrix33);

    Shiboken::Conversions::registerConverterName(converter, "CMatrix33");
    Shiboken::Conversions::registerConverterName(converter, "CMatrix33*");
    Shiboken::Conversions::registerConverterName(converter, "CMatrix33&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::CMatrix33).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        CMatrix33_PythonToCpp_CMatrix33_COPY,
        is_CMatrix33_PythonToCpp_CMatrix33_COPY_Convertible);


}
