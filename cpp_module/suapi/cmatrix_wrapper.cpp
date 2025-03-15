
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "cmatrix_wrapper.h"

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
Sbk_CMatrix_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::CMatrix >()))
        return -1;

    ::CMatrix *cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "CMatrix", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: CMatrix::CMatrix()
    // 1: CMatrix::CMatrix(CMatrix)
    if (numArgs == 0) {
        overloadId = 0; // CMatrix()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), (pyArgs[0])))) {
        overloadId = 1; // CMatrix(CMatrix)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrix_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // CMatrix()
        {

            if (!PyErr_Occurred()) {
                // CMatrix()
                cptr = new ::CMatrix();
            }
            break;
        }
        case 1: // CMatrix(const CMatrix & CMatrix)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::CMatrix cppArg0_local;
            ::CMatrix *cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // CMatrix(CMatrix)
                cptr = new ::CMatrix(*cppArg0);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::CMatrix >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_CMatrix_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_CMatrix_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CMatrix");
        return -1;
}

static PyObject *Sbk_CMatrixFunc_ProjectPoint(PyObject *self, PyObject *pyArg)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: CMatrix::ProjectPoint(CVector3D&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArg)))) {
        overloadId = 0; // ProjectPoint(CVector3D&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_ProjectPoint_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::CVector3D cppArg0_local;
        ::CVector3D *cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // ProjectPoint(CVector3D&)
            CVector3D cppResult = cppSelf->ProjectPoint(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrixFunc_ProjectPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.ProjectPoint");
        return {};
}

static PyObject *Sbk_CMatrixFunc_SetAxis(PyObject *self, PyObject *args)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "SetAxis", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: CMatrix::SetAxis(int,CVector3D)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArgs[1])))) {
        overloadId = 0; // SetAxis(int,CVector3D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_SetAxis_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::CVector3D cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // SetAxis(int,CVector3D)
            cppSelf->SetAxis(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_CMatrixFunc_SetAxis_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CMatrix.SetAxis");
        return {};
}

static PyObject *Sbk_CMatrixFunc_SetRow(PyObject *self, PyObject *args)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "SetRow", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: CMatrix::SetRow(int,CVector3D)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArgs[1])))) {
        overloadId = 0; // SetRow(int,CVector3D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_SetRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::CVector3D cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // SetRow(int,CVector3D)
            cppSelf->SetRow(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_CMatrixFunc_SetRow_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CMatrix.SetRow");
        return {};
}

static PyObject *Sbk_CMatrixFunc_SetScale(PyObject *self, PyObject *pyArg)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: CMatrix::SetScale(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // SetScale(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_SetScale_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // SetScale(double)
            cppSelf->SetScale(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_CMatrixFunc_SetScale_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.SetScale");
        return {};
}

static PyObject *Sbk_CMatrixFunc_gl_multiply_matrix(PyObject *self)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // gl_multiply_matrix()
            cppSelf->gl_multiply_matrix();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject *Sbk_CMatrixFunc_multiply(PyObject *self, PyObject *pyArg)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: CMatrix::multiply(CMatrix&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), (pyArg)))) {
        overloadId = 0; // multiply(CMatrix&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_multiply_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::CMatrix cppArg0_local;
        ::CMatrix *cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // multiply(CMatrix&)
            CMatrix cppResult = cppSelf->multiply(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrixFunc_multiply_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.multiply");
        return {};
}

static PyObject *Sbk_CMatrix___copy__(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    ::CMatrix &cppSelf =  *reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyMethodDef Sbk_CMatrix_methods[] = {
    {"ProjectPoint", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_ProjectPoint), METH_O},
    {"SetAxis", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_SetAxis), METH_VARARGS},
    {"SetRow", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_SetRow), METH_VARARGS},
    {"SetScale", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_SetScale), METH_O},
    {"gl_multiply_matrix", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_gl_multiply_matrix), METH_NOARGS},
    {"multiply", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_multiply), METH_O},

    {"__copy__", reinterpret_cast<PyCFunction>(Sbk_CMatrix___copy__), METH_NOARGS},
    {nullptr, nullptr} // Sentinel
};

static PyObject *Sbk_CMatrix_get_scale(PyObject *self, void *)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->scale);
    return pyOut;
}
static int Sbk_CMatrix_set_scale(PyObject *self, PyObject *pyIn, void *)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'scale' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'scale', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->scale;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject *Sbk_CMatrix_get_isIdentity(PyObject *self, void *)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    bool cppOut_local = cppSelf->isIdentity;
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_CMatrix_set_isIdentity(PyObject *self, PyObject *pyIn, void *)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'isIdentity' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'isIdentity', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->isIdentity;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->isIdentity = cppOut_local;

    return 0;
}

static PyObject *Sbk_CMatrix_get_flags(PyObject *self, void *)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    bool cppOut_local = cppSelf->flags;
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_CMatrix_set_flags(PyObject *self, PyObject *pyIn, void *)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'flags' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'flags', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->flags;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->flags = cppOut_local;

    return 0;
}

// Getters and Setters for CMatrix
static PyGetSetDef Sbk_CMatrix_getsetlist[] = {
    {const_cast<char *>("scale"), Sbk_CMatrix_get_scale, Sbk_CMatrix_set_scale},
    {const_cast<char *>("isIdentity"), Sbk_CMatrix_get_isIdentity, Sbk_CMatrix_set_isIdentity},
    {const_cast<char *>("flags"), Sbk_CMatrix_get_flags, Sbk_CMatrix_set_flags},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_CMatrix_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_CMatrix_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_CMatrix_Type = nullptr;
static SbkObjectType *Sbk_CMatrix_TypeF(void)
{
    return _Sbk_CMatrix_Type;
}

static PyType_Slot Sbk_CMatrix_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_CMatrix_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_CMatrix_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_CMatrix_methods)},
    {Py_tp_getset,      reinterpret_cast<void *>(Sbk_CMatrix_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_CMatrix_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_CMatrix_spec = {
    "suapi.CMatrix",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_CMatrix_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void CMatrix_PythonToCpp_CMatrix_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_CMatrix_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_CMatrix_PythonToCpp_CMatrix_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CMatrix_TypeF())))
        return CMatrix_PythonToCpp_CMatrix_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *CMatrix_PTR_CppToPython_CMatrix(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::CMatrix *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_CMatrix_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// C++ to Python copy conversion.
static PyObject *CMatrix_COPY_CppToPython_CMatrix(const void *cppIn) {
    return Shiboken::Object::newObject(Sbk_CMatrix_TypeF(), new ::CMatrix(*reinterpret_cast<const ::CMatrix *>(cppIn)), true, true);
}

// Python to C++ copy conversion.
static void CMatrix_PythonToCpp_CMatrix_COPY(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::CMatrix *>(cppOut) = *reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(pyIn)));
}
static PythonToCppFunc is_CMatrix_PythonToCpp_CMatrix_COPY_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CMatrix_TypeF())))
        return CMatrix_PythonToCpp_CMatrix_COPY;
    return {};
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *CMatrix_SignatureStrings[] = {
    "1:suapi.CMatrix()",
    "0:suapi.CMatrix(CMatrix:suapi.CMatrix)",
    "suapi.CMatrix.ProjectPoint(point:suapi.CVector3D)->suapi.CVector3D",
    "suapi.CMatrix.SetAxis(axis:int,v:suapi.CVector3D)",
    "suapi.CMatrix.SetRow(row:int,v:suapi.CVector3D)",
    "suapi.CMatrix.SetScale(scale:double)",
    "suapi.CMatrix.gl_multiply_matrix()",
    "suapi.CMatrix.multiply(R:suapi.CMatrix)->suapi.CMatrix",
    "suapi.CMatrix.__copy__()",
    nullptr}; // Sentinel

void init_CMatrix(PyObject *module)
{
    _Sbk_CMatrix_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "CMatrix",
        "CMatrix",
        &Sbk_CMatrix_spec,
        CMatrix_SignatureStrings,
        &Shiboken::callCppDestructor< ::CMatrix >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_CMATRIX_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_CMatrix_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_CMatrix_TypeF(),
        CMatrix_PythonToCpp_CMatrix_PTR,
        is_CMatrix_PythonToCpp_CMatrix_PTR_Convertible,
        CMatrix_PTR_CppToPython_CMatrix,
        CMatrix_COPY_CppToPython_CMatrix);

    Shiboken::Conversions::registerConverterName(converter, "CMatrix");
    Shiboken::Conversions::registerConverterName(converter, "CMatrix*");
    Shiboken::Conversions::registerConverterName(converter, "CMatrix&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::CMatrix).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        CMatrix_PythonToCpp_CMatrix_COPY,
        is_CMatrix_PythonToCpp_CMatrix_COPY_Convertible);


}
