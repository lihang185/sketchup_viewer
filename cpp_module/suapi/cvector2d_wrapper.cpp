
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "cvector2d_wrapper.h"

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


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_CVector2D_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::CVector2D >()))
        return -1;

    ::CVector2D *cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "CVector2D", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: CVector2D::CVector2D()
    // 1: CVector2D::CVector2D(CVector2D)
    // 2: CVector2D::CVector2D(double,double)
    if (numArgs == 0) {
        overloadId = 0; // CVector2D()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 2; // CVector2D(double,double)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR2D_IDX]), (pyArgs[0])))) {
        overloadId = 1; // CVector2D(CVector2D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CVector2D_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // CVector2D()
        {

            if (!PyErr_Occurred()) {
                // CVector2D()
                cptr = new ::CVector2D();
            }
            break;
        }
        case 1: // CVector2D(const CVector2D & CVector2D)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::CVector2D cppArg0_local;
            ::CVector2D *cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR2D_IDX]), pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // CVector2D(CVector2D)
                cptr = new ::CVector2D(*cppArg0);
            }
            break;
        }
        case 2: // CVector2D(double ix, double iy)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // CVector2D(double,double)
                cptr = new ::CVector2D(cppArg0, cppArg1);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::CVector2D >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_CVector2D_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_CVector2D_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CVector2D");
        return -1;
}

static PyObject *Sbk_CVector2D___copy__(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    ::CVector2D &cppSelf =  *reinterpret_cast< ::CVector2D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR2D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR2D_IDX]), &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyMethodDef Sbk_CVector2D_methods[] = {

    {"__copy__", reinterpret_cast<PyCFunction>(Sbk_CVector2D___copy__), METH_NOARGS},
    {nullptr, nullptr} // Sentinel
};

static PyObject *Sbk_CVector2D_get_x(PyObject *self, void *)
{
    ::CVector2D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CVector2D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR2D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->x);
    return pyOut;
}
static int Sbk_CVector2D_set_x(PyObject *self, PyObject *pyIn, void *)
{
    ::CVector2D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CVector2D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR2D_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'x' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'x', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->x;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject *Sbk_CVector2D_get_y(PyObject *self, void *)
{
    ::CVector2D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CVector2D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR2D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->y);
    return pyOut;
}
static int Sbk_CVector2D_set_y(PyObject *self, PyObject *pyIn, void *)
{
    ::CVector2D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CVector2D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR2D_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'y' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'y', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->y;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for CVector2D
static PyGetSetDef Sbk_CVector2D_getsetlist[] = {
    {const_cast<char *>("x"), Sbk_CVector2D_get_x, Sbk_CVector2D_set_x},
    {const_cast<char *>("y"), Sbk_CVector2D_get_y, Sbk_CVector2D_set_y},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_CVector2D_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_CVector2D_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_CVector2D_Type = nullptr;
static SbkObjectType *Sbk_CVector2D_TypeF(void)
{
    return _Sbk_CVector2D_Type;
}

static PyType_Slot Sbk_CVector2D_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_CVector2D_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_CVector2D_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_CVector2D_methods)},
    {Py_tp_getset,      reinterpret_cast<void *>(Sbk_CVector2D_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_CVector2D_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_CVector2D_spec = {
    "suapi.CVector2D",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_CVector2D_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void CVector2D_PythonToCpp_CVector2D_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_CVector2D_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_CVector2D_PythonToCpp_CVector2D_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CVector2D_TypeF())))
        return CVector2D_PythonToCpp_CVector2D_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *CVector2D_PTR_CppToPython_CVector2D(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::CVector2D *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_CVector2D_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// C++ to Python copy conversion.
static PyObject *CVector2D_COPY_CppToPython_CVector2D(const void *cppIn) {
    return Shiboken::Object::newObject(Sbk_CVector2D_TypeF(), new ::CVector2D(*reinterpret_cast<const ::CVector2D *>(cppIn)), true, true);
}

// Python to C++ copy conversion.
static void CVector2D_PythonToCpp_CVector2D_COPY(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::CVector2D *>(cppOut) = *reinterpret_cast< ::CVector2D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR2D_IDX], reinterpret_cast<SbkObject *>(pyIn)));
}
static PythonToCppFunc is_CVector2D_PythonToCpp_CVector2D_COPY_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CVector2D_TypeF())))
        return CVector2D_PythonToCpp_CVector2D_COPY;
    return {};
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *CVector2D_SignatureStrings[] = {
    "2:suapi.CVector2D()",
    "1:suapi.CVector2D(CVector2D:suapi.CVector2D)",
    "0:suapi.CVector2D(ix:double,iy:double)",
    "suapi.CVector2D.__copy__()",
    nullptr}; // Sentinel

void init_CVector2D(PyObject *module)
{
    _Sbk_CVector2D_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "CVector2D",
        "CVector2D",
        &Sbk_CVector2D_spec,
        CVector2D_SignatureStrings,
        &Shiboken::callCppDestructor< ::CVector2D >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_CVECTOR2D_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_CVector2D_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_CVector2D_TypeF(),
        CVector2D_PythonToCpp_CVector2D_PTR,
        is_CVector2D_PythonToCpp_CVector2D_PTR_Convertible,
        CVector2D_PTR_CppToPython_CVector2D,
        CVector2D_COPY_CppToPython_CVector2D);

    Shiboken::Conversions::registerConverterName(converter, "CVector2D");
    Shiboken::Conversions::registerConverterName(converter, "CVector2D*");
    Shiboken::Conversions::registerConverterName(converter, "CVector2D&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::CVector2D).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        CVector2D_PythonToCpp_CVector2D_COPY,
        is_CVector2D_PythonToCpp_CVector2D_COPY_Convertible);


}
