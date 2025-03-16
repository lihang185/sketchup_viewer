
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "cvector3d_wrapper.h"

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
Sbk_CVector3D_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::CVector3D >()))
        return -1;

    ::CVector3D *cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_CVector3D_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "CVector3D", 0, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: CVector3D::CVector3D()
    // 1: CVector3D::CVector3D(CVector3D)
    // 2: CVector3D::CVector3D(double,double,double)
    if (numArgs == 0) {
        overloadId = 0; // CVector3D()
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
        overloadId = 2; // CVector3D(double,double,double)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArgs[0])))) {
        overloadId = 1; // CVector3D(CVector3D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CVector3D_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // CVector3D()
        {

            if (!PyErr_Occurred()) {
                // CVector3D()
                cptr = new ::CVector3D();
            }
            break;
        }
        case 1: // CVector3D(const CVector3D & CVector3D)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::CVector3D cppArg0_local;
            ::CVector3D *cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // CVector3D(CVector3D)
                cptr = new ::CVector3D(*cppArg0);
            }
            break;
        }
        case 2: // CVector3D(double ix, double iy, double iz)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // CVector3D(double,double,double)
                cptr = new ::CVector3D(cppArg0, cppArg1, cppArg2);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::CVector3D >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_CVector3D_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_CVector3D_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "suapi.CVector3D");
        return -1;
}

static PyObject *Sbk_CVector3DFunc_CrossProduct(PyObject *self, PyObject *pyArg)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: CVector3D::CrossProduct(CVector3D&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArg)))) {
        overloadId = 0; // CrossProduct(CVector3D&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CVector3DFunc_CrossProduct_TypeError;

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
            // CrossProduct(CVector3D&)
            CVector3D cppResult = cppSelf->CrossProduct(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CVector3DFunc_CrossProduct_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CVector3D.CrossProduct");
        return {};
}

static PyObject *Sbk_CVector3DFunc_DotProduct(PyObject *self, PyObject *pyArg)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: CVector3D::DotProduct(CVector3D&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArg)))) {
        overloadId = 0; // DotProduct(CVector3D&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CVector3DFunc_DotProduct_TypeError;

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
            // DotProduct(CVector3D&)
            double cppResult = cppSelf->DotProduct(*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CVector3DFunc_DotProduct_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CVector3D.DotProduct");
        return {};
}

static PyObject *Sbk_CVector3DFunc_toTuple(PyObject *self)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toTuple()
            // Begin code injection

            // TEMPLATE - to_tuple - START
            pyResult = Py_BuildValue("ddd", cppSelf->x, cppSelf->y, cppSelf->z);
            // TEMPLATE - to_tuple - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_CVector3D___copy__(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    ::CVector3D &cppSelf =  *reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyMethodDef Sbk_CVector3D_methods[] = {
    {"CrossProduct", reinterpret_cast<PyCFunction>(Sbk_CVector3DFunc_CrossProduct), METH_O},
    {"DotProduct", reinterpret_cast<PyCFunction>(Sbk_CVector3DFunc_DotProduct), METH_O},
    {"toTuple", reinterpret_cast<PyCFunction>(Sbk_CVector3DFunc_toTuple), METH_NOARGS},

    {"__copy__", reinterpret_cast<PyCFunction>(Sbk_CVector3D___copy__), METH_NOARGS},
    {nullptr, nullptr} // Sentinel
};

static PyObject *Sbk_CVector3DFunc___mul__(PyObject *self, PyObject *pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbksuapiTypes[SBK_CVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbksuapiTypes[SBK_CVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: CVector3D::operator*(double)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // operator*(double)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return {};
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CVector3DFunc___mul___TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator*(double)
            CVector3D cppResult = (*cppSelf) * cppArg0;
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CVector3DFunc___mul___TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CVector3D.__mul__");
        return {};
}

static PyObject *Sbk_CVector3DFunc___add__(PyObject *self, PyObject *pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbksuapiTypes[SBK_CVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbksuapiTypes[SBK_CVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: CVector3D::operator+(CVector3D&)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArg)))) {
        overloadId = 0; // operator+(CVector3D&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return {};
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CVector3DFunc___add___TypeError;

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
            // operator+(CVector3D&)
            CVector3D cppResult = (*cppSelf) + (*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CVector3DFunc___add___TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CVector3D.__add__");
        return {};
}

static PyObject *Sbk_CVector3DFunc___neg__(PyObject *self)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // operator-()
            CVector3D cppResult = - (*cppSelf);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_CVector3DFunc___sub__(PyObject *self, PyObject *pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbksuapiTypes[SBK_CVECTOR3D_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbksuapiTypes[SBK_CVECTOR3D_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: CVector3D::operator-(CVector3D&)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), (pyArg)))) {
        overloadId = 0; // operator-(CVector3D&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return {};
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_CVector3DFunc___sub___TypeError;

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
            // operator-(CVector3D&)
            CVector3D cppResult = (*cppSelf) - (*cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_CVECTOR3D_IDX]), &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_CVector3DFunc___sub___TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "suapi.CVector3D.__sub__");
        return {};
}

static PyObject *Sbk_CVector3D_get_x(PyObject *self, void *)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->x);
    return pyOut;
}
static int Sbk_CVector3D_set_x(PyObject *self, PyObject *pyIn, void *)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_CVector3D_get_y(PyObject *self, void *)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->y);
    return pyOut;
}
static int Sbk_CVector3D_set_y(PyObject *self, PyObject *pyIn, void *)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject *Sbk_CVector3D_get_z(PyObject *self, void *)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->z);
    return pyOut;
}
static int Sbk_CVector3D_set_z(PyObject *self, PyObject *pyIn, void *)
{
    ::CVector3D *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(self)));
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

// Getters and Setters for CVector3D
static PyGetSetDef Sbk_CVector3D_getsetlist[] = {
    {const_cast<char *>("x"), Sbk_CVector3D_get_x, Sbk_CVector3D_set_x},
    {const_cast<char *>("y"), Sbk_CVector3D_get_y, Sbk_CVector3D_set_y},
    {const_cast<char *>("z"), Sbk_CVector3D_get_z, Sbk_CVector3D_set_z},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_CVector3D_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_CVector3D_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_CVector3D_Type = nullptr;
static SbkObjectType *Sbk_CVector3D_TypeF(void)
{
    return _Sbk_CVector3D_Type;
}

static PyType_Slot Sbk_CVector3D_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_CVector3D_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_CVector3D_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_CVector3D_methods)},
    {Py_tp_getset,      reinterpret_cast<void *>(Sbk_CVector3D_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_CVector3D_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    // type supports number protocol
    {Py_nb_multiply, (void *)Sbk_CVector3DFunc___mul__},
    {Py_nb_add, (void *)Sbk_CVector3DFunc___add__},
    {Py_nb_subtract, (void *)Sbk_CVector3DFunc___sub__},
    {Py_nb_negative, (void *)Sbk_CVector3DFunc___neg__},
    {0, nullptr}
};
static PyType_Spec Sbk_CVector3D_spec = {
    "suapi.CVector3D",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_CVector3D_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void CVector3D_PythonToCpp_CVector3D_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_CVector3D_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_CVector3D_PythonToCpp_CVector3D_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CVector3D_TypeF())))
        return CVector3D_PythonToCpp_CVector3D_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *CVector3D_PTR_CppToPython_CVector3D(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::CVector3D *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_CVector3D_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// C++ to Python copy conversion.
static PyObject *CVector3D_COPY_CppToPython_CVector3D(const void *cppIn) {
    return Shiboken::Object::newObject(Sbk_CVector3D_TypeF(), new ::CVector3D(*reinterpret_cast<const ::CVector3D *>(cppIn)), true, true);
}

// Python to C++ copy conversion.
static void CVector3D_PythonToCpp_CVector3D_COPY(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::CVector3D *>(cppOut) = *reinterpret_cast< ::CVector3D *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_CVECTOR3D_IDX], reinterpret_cast<SbkObject *>(pyIn)));
}
static PythonToCppFunc is_CVector3D_PythonToCpp_CVector3D_COPY_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_CVector3D_TypeF())))
        return CVector3D_PythonToCpp_CVector3D_COPY;
    return {};
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *CVector3D_SignatureStrings[] = {
    "2:suapi.CVector3D()",
    "1:suapi.CVector3D(CVector3D:suapi.CVector3D)",
    "0:suapi.CVector3D(ix:double,iy:double,iz:double)",
    "suapi.CVector3D.CrossProduct(R:suapi.CVector3D)->suapi.CVector3D",
    "suapi.CVector3D.DotProduct(R:suapi.CVector3D)->double",
    "suapi.CVector3D.toTuple()->PyObject",
    "suapi.CVector3D.__copy__()",
    "suapi.CVector3D.__mul__(scale:double)->suapi.CVector3D",
    "suapi.CVector3D.__add__(R:suapi.CVector3D)->suapi.CVector3D",
    "suapi.CVector3D.__neg__()->suapi.CVector3D",
    "suapi.CVector3D.__sub__(R:suapi.CVector3D)->suapi.CVector3D",
    nullptr}; // Sentinel

void init_CVector3D(PyObject *module)
{
    _Sbk_CVector3D_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "CVector3D",
        "CVector3D",
        &Sbk_CVector3D_spec,
        CVector3D_SignatureStrings,
        &Shiboken::callCppDestructor< ::CVector3D >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_CVECTOR3D_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_CVector3D_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_CVector3D_TypeF(),
        CVector3D_PythonToCpp_CVector3D_PTR,
        is_CVector3D_PythonToCpp_CVector3D_PTR_Convertible,
        CVector3D_PTR_CppToPython_CVector3D,
        CVector3D_COPY_CppToPython_CVector3D);

    Shiboken::Conversions::registerConverterName(converter, "CVector3D");
    Shiboken::Conversions::registerConverterName(converter, "CVector3D*");
    Shiboken::Conversions::registerConverterName(converter, "CVector3D&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::CVector3D).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        CVector3D_PythonToCpp_CVector3D_COPY,
        is_CVector3D_PythonToCpp_CVector3D_COPY_Convertible);


}
