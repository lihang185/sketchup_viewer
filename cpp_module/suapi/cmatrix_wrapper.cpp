
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

static PyObject *Sbk_CMatrixFunc_GetData(PyObject *self)
{
    ::CMatrix *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CMatrix *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CMATRIX_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // GetData()
            std::vector<double > cppResult = cppSelf->GetData();
            pyResult = Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_DOUBLE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_CMatrixFunc_Multiply(PyObject *self, PyObject *pyArg)
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
    // 0: CMatrix::Multiply(CMatrix&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), (pyArg)))) {
        overloadId = 0; // Multiply(CMatrix&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_Multiply_TypeError;

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
            // Multiply(CMatrix&)
            CMatrix cppResult = cppSelf->Multiply(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrixFunc_Multiply_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.Multiply");
        return {};
}

static PyObject *Sbk_CMatrixFunc_Multiply2(PyObject *self, PyObject *pyArg)
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
    // 0: CMatrix::Multiply2(CMatrix&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), (pyArg)))) {
        overloadId = 0; // Multiply2(CMatrix&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_Multiply2_TypeError;

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
            // Multiply2(CMatrix&)
            CMatrix cppResult = cppSelf->Multiply2(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrixFunc_Multiply2_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.Multiply2");
        return {};
}

static PyObject *Sbk_CMatrixFunc_NewFromData(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static CMatrix::NewFromData(std::vector<double>&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_DOUBLE_IDX], (pyArg)))) {
        overloadId = 0; // NewFromData(std::vector<double>&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_NewFromData_TypeError;

    // Call function/method
    {
        ::std::vector<double > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // NewFromData(std::vector<double>&)
            CMatrix cppResult = ::CMatrix::NewFromData(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrixFunc_NewFromData_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.NewFromData");
        return {};
}

static PyObject *Sbk_CMatrixFunc_NewFromRotate(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static CMatrix::NewFromRotate(CVector3D&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArg)))) {
        overloadId = 0; // NewFromRotate(CVector3D&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_NewFromRotate_TypeError;

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
            // NewFromRotate(CVector3D&)
            CMatrix cppResult = ::CMatrix::NewFromRotate(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrixFunc_NewFromRotate_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.NewFromRotate");
        return {};
}

static PyObject *Sbk_CMatrixFunc_NewFromScale(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static CMatrix::NewFromScale(CVector3D&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArg)))) {
        overloadId = 0; // NewFromScale(CVector3D&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_NewFromScale_TypeError;

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
            // NewFromScale(CVector3D&)
            CMatrix cppResult = ::CMatrix::NewFromScale(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrixFunc_NewFromScale_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.NewFromScale");
        return {};
}

static PyObject *Sbk_CMatrixFunc_NewFromTranslate(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static CMatrix::NewFromTranslate(CVector3D&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArg)))) {
        overloadId = 0; // NewFromTranslate(CVector3D&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_NewFromTranslate_TypeError;

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
            // NewFromTranslate(CVector3D&)
            CMatrix cppResult = ::CMatrix::NewFromTranslate(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CMATRIX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrixFunc_NewFromTranslate_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.NewFromTranslate");
        return {};
}

static PyObject *Sbk_CMatrixFunc_TransformPoint(PyObject *self, PyObject *pyArg)
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
    // 0: CMatrix::TransformPoint(CVector3D&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArg)))) {
        overloadId = 0; // TransformPoint(CVector3D&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CMatrixFunc_TransformPoint_TypeError;

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
            // TransformPoint(CVector3D&)
            CVector3D cppResult = cppSelf->TransformPoint(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CMatrixFunc_TransformPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CMatrix.TransformPoint");
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
    {"GetData", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_GetData), METH_NOARGS},
    {"Multiply", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_Multiply), METH_O},
    {"Multiply2", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_Multiply2), METH_O},
    {"NewFromData", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_NewFromData), METH_O|METH_STATIC},
    {"NewFromRotate", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_NewFromRotate), METH_O|METH_STATIC},
    {"NewFromScale", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_NewFromScale), METH_O|METH_STATIC},
    {"NewFromTranslate", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_NewFromTranslate), METH_O|METH_STATIC},
    {"TransformPoint", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_TransformPoint), METH_O},
    {"gl_multiply_matrix", reinterpret_cast<PyCFunction>(Sbk_CMatrixFunc_gl_multiply_matrix), METH_NOARGS},

    {"__copy__", reinterpret_cast<PyCFunction>(Sbk_CMatrix___copy__), METH_NOARGS},
    {nullptr, nullptr} // Sentinel
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
    {Py_tp_getset,      nullptr},
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
    "suapi.CMatrix.GetData()->std.vector[double]",
    "suapi.CMatrix.Multiply(R:suapi.CMatrix)->suapi.CMatrix",
    "suapi.CMatrix.Multiply2(R:suapi.CMatrix)->suapi.CMatrix",
    "suapi.CMatrix.NewFromData(data:std.vector[double])->suapi.CMatrix",
    "suapi.CMatrix.NewFromRotate(rotate:suapi.CVector3D)->suapi.CMatrix",
    "suapi.CMatrix.NewFromScale(scale:suapi.CVector3D)->suapi.CMatrix",
    "suapi.CMatrix.NewFromTranslate(translate:suapi.CVector3D)->suapi.CMatrix",
    "suapi.CMatrix.TransformPoint(point:suapi.CVector3D)->suapi.CVector3D",
    "suapi.CMatrix.gl_multiply_matrix()",
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
