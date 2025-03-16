
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "cplane_wrapper.h"

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
static int
Sbk_CPlane_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::CPlane >()))
        return -1;

    ::CPlane *cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_CPlane_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "CPlane", 0, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: CPlane::CPlane()
    // 1: CPlane::CPlane(CVector3D&,double)
    // 2: CPlane::CPlane(CVector3D&,CVector3D&)
    // 3: CPlane::CPlane(CPlane)
    // 4: CPlane::CPlane(double,double,double,double)
    if (numArgs == 0) {
        overloadId = 0; // CPlane()
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        overloadId = 4; // CPlane(double,double,double,double)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CPLANE_IDX]), (pyArgs[0])))) {
        overloadId = 3; // CPlane(CPlane)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArgs[1])))) {
            overloadId = 2; // CPlane(CVector3D&,CVector3D&)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            overloadId = 1; // CPlane(CVector3D&,double)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CPlane_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // CPlane()
        {

            if (!PyErr_Occurred()) {
                // CPlane()
                cptr = new ::CPlane();
            }
            break;
        }
        case 1: // CPlane(CVector3D & _p, double _w)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::CVector3D cppArg0_local;
            ::CVector3D *cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // CPlane(CVector3D&,double)
                cptr = new ::CPlane(*cppArg0, cppArg1);
            }
            break;
        }
        case 2: // CPlane(CVector3D & normal, CVector3D & orig)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::CVector3D cppArg0_local;
            ::CVector3D *cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::CVector3D cppArg1_local;
            ::CVector3D *cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // CPlane(CVector3D&,CVector3D&)
                cptr = new ::CPlane(*cppArg0, *cppArg1);
            }
            break;
        }
        case 3: // CPlane(const CPlane & CPlane)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::CPlane cppArg0_local;
            ::CPlane *cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CPLANE_IDX]), pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // CPlane(CPlane)
                cptr = new ::CPlane(*cppArg0);
            }
            break;
        }
        case 4: // CPlane(double _x, double _y, double _z, double _w)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // CPlane(double,double,double,double)
                cptr = new ::CPlane(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::CPlane >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_CPlane_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_CPlane_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CPlane");
        return -1;
}

static PyObject *Sbk_CPlaneFunc_GetNormal(PyObject *self)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetNormal()
            CVector3D cppResult = cppSelf->GetNormal();
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_CPlaneFunc_IntersectWithRay(PyObject *self, PyObject *args)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "IntersectWithRay", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: CPlane::IntersectWithRay(CVector3D&,CVector3D&)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArgs[1])))) {
        overloadId = 0; // IntersectWithRay(CVector3D&,CVector3D&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CPlaneFunc_IntersectWithRay_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::CVector3D cppArg0_local;
        ::CVector3D *cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::CVector3D cppArg1_local;
        ::CVector3D *cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // IntersectWithRay(CVector3D&,CVector3D&)
            double cppResult = cppSelf->IntersectWithRay(*cppArg0, *cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CPlaneFunc_IntersectWithRay_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CPlane.IntersectWithRay");
        return {};
}

static PyObject *Sbk_CPlane___copy__(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    ::CPlane &cppSelf =  *reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CPLANE_IDX]), &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyMethodDef Sbk_CPlane_methods[] = {
    {"GetNormal", reinterpret_cast<PyCFunction>(Sbk_CPlaneFunc_GetNormal), METH_NOARGS},
    {"IntersectWithRay", reinterpret_cast<PyCFunction>(Sbk_CPlaneFunc_IntersectWithRay), METH_VARARGS},

    {"__copy__", reinterpret_cast<PyCFunction>(Sbk_CPlane___copy__), METH_NOARGS},
    {nullptr, nullptr} // Sentinel
};

static PyObject *Sbk_CPlane_get_x(PyObject *self, void *)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->x);
    return pyOut;
}
static int Sbk_CPlane_set_x(PyObject *self, PyObject *pyIn, void *)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_CPlane_get_y(PyObject *self, void *)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->y);
    return pyOut;
}
static int Sbk_CPlane_set_y(PyObject *self, PyObject *pyIn, void *)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_CPlane_get_z(PyObject *self, void *)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->z);
    return pyOut;
}
static int Sbk_CPlane_set_z(PyObject *self, PyObject *pyIn, void *)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'z' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'z', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->z;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject *Sbk_CPlane_get_w(PyObject *self, void *)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->w);
    return pyOut;
}
static int Sbk_CPlane_set_w(PyObject *self, PyObject *pyIn, void *)
{
    ::CPlane *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'w' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'w', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->w;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for CPlane
static PyGetSetDef Sbk_CPlane_getsetlist[] = {
    {const_cast<char *>("x"), Sbk_CPlane_get_x, Sbk_CPlane_set_x},
    {const_cast<char *>("y"), Sbk_CPlane_get_y, Sbk_CPlane_set_y},
    {const_cast<char *>("z"), Sbk_CPlane_get_z, Sbk_CPlane_set_z},
    {const_cast<char *>("w"), Sbk_CPlane_get_w, Sbk_CPlane_set_w},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_CPlane_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_CPlane_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_CPlane_Type = nullptr;
static SbkObjectType *Sbk_CPlane_TypeF(void)
{
    return _Sbk_CPlane_Type;
}

static PyType_Slot Sbk_CPlane_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_CPlane_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_CPlane_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_CPlane_methods)},
    {Py_tp_getset,      reinterpret_cast<void *>(Sbk_CPlane_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_CPlane_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_CPlane_spec = {
    "suapi.CPlane",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_CPlane_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void CPlane_PythonToCpp_CPlane_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_CPlane_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_CPlane_PythonToCpp_CPlane_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CPlane_TypeF())))
        return CPlane_PythonToCpp_CPlane_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *CPlane_PTR_CppToPython_CPlane(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::CPlane *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_CPlane_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// C++ to Python copy conversion.
static PyObject *CPlane_COPY_CppToPython_CPlane(const void *cppIn) {
    return Shiboken::Object::newObject(Sbk_CPlane_TypeF(), new ::CPlane(*reinterpret_cast<const ::CPlane *>(cppIn)), true, true);
}

// Python to C++ copy conversion.
static void CPlane_PythonToCpp_CPlane_COPY(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::CPlane *>(cppOut) = *reinterpret_cast< ::CPlane *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CPLANE_IDX], reinterpret_cast<SbkObject *>(pyIn)));
}
static PythonToCppFunc is_CPlane_PythonToCpp_CPlane_COPY_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CPlane_TypeF())))
        return CPlane_PythonToCpp_CPlane_COPY;
    return {};
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *CPlane_SignatureStrings[] = {
    "4:suapi.CPlane()",
    "3:suapi.CPlane(_p:suapi.CVector3D,_w:double)",
    "2:suapi.CPlane(normal:suapi.CVector3D,orig:suapi.CVector3D)",
    "1:suapi.CPlane(CPlane:suapi.CPlane)",
    "0:suapi.CPlane(_x:double,_y:double,_z:double,_w:double)",
    "suapi.CPlane.GetNormal()->suapi.CVector3D",
    "suapi.CPlane.IntersectWithRay(orig:suapi.CVector3D,dir:suapi.CVector3D)->double",
    "suapi.CPlane.__copy__()",
    nullptr}; // Sentinel

void init_CPlane(PyObject *module)
{
    _Sbk_CPlane_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "CPlane",
        "CPlane",
        &Sbk_CPlane_spec,
        CPlane_SignatureStrings,
        &Shiboken::callCppDestructor< ::CPlane >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_CPLANE_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_CPlane_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_CPlane_TypeF(),
        CPlane_PythonToCpp_CPlane_PTR,
        is_CPlane_PythonToCpp_CPlane_PTR_Convertible,
        CPlane_PTR_CppToPython_CPlane,
        CPlane_COPY_CppToPython_CPlane);

    Shiboken::Conversions::registerConverterName(converter, "CPlane");
    Shiboken::Conversions::registerConverterName(converter, "CPlane*");
    Shiboken::Conversions::registerConverterName(converter, "CPlane&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::CPlane).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        CPlane_PythonToCpp_CPlane_COPY,
        is_CPlane_PythonToCpp_CPlane_COPY_Convertible);


}
