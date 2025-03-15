
// default includes
#include <shiboken.h>
#include <typeinfo>

// module include
#include "suapi_python.h"

// main header
#include "suentityiterator_wrapper.h"

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

void SUEntityIteratorWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

SUEntityIteratorWrapper::SUEntityIteratorWrapper() : SUEntityIterator()
{
    resetPyMethodCache();
    // ... middle
}

SUEntityIteratorWrapper::~SUEntityIteratorWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_SUEntityIterator_Init(PyObject *self, PyObject *args, PyObject *kwds)
{
    SbkObject *sbkSelf = reinterpret_cast<SbkObject *>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::SUEntityIterator >()))
        return -1;

    ::SUEntityIteratorWrapper *cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // SUEntityIterator()
            cptr = new ::SUEntityIteratorWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::SUEntityIterator >(), cptr)) {
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

static PyObject *Sbk_SUEntityIteratorFunc___iter__(PyObject *self)
{
    ::SUEntityIterator *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntityIterator *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITYITERATOR_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __iter__()
            // Begin code injection

            Py_INCREF(self);
            pyResult = self;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_SUEntityIteratorFunc___next__(PyObject *self)
{
    ::SUEntityIterator *cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::SUEntityIterator *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITYITERATOR_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __next__()
            // Begin code injection

            SUEntity* entity;
            if (cppSelf->next( & entity )) {
            if(entity->GetType() == 16)
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUEDGE_IDX]), entity);
            else if (entity->GetType() == 18)
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUFACE_IDX]), entity);
            else
            pyResult = 0;
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyMethodDef Sbk_SUEntityIterator_methods[] = {

    {nullptr, nullptr} // Sentinel
};

static int Sbk_SUEntityIterator_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::SUEntityIterator *>(Shiboken::Conversions::cppPointer(SbksuapiTypes[SBK_SUENTITYITERATOR_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<SUEntityIteratorWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_SUEntityIterator_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_SUEntityIterator_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_SUEntityIterator_Type = nullptr;
static SbkObjectType *Sbk_SUEntityIterator_TypeF(void)
{
    return _Sbk_SUEntityIterator_Type;
}

static PyType_Slot Sbk_SUEntityIterator_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_SUEntityIterator_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_SUEntityIterator_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_SUEntityIterator_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        reinterpret_cast<void *>(Sbk_SUEntityIteratorFunc___iter__)},
    {Py_tp_iternext,    reinterpret_cast<void *>(Sbk_SUEntityIteratorFunc___next__)},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_SUEntityIterator_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void *>(Sbk_SUEntityIterator_Init)},
    {Py_tp_new,         reinterpret_cast<void *>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_SUEntityIterator_spec = {
    "suapi.SUEntityIterator",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_SUEntityIterator_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void SUEntityIterator_PythonToCpp_SUEntityIterator_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_SUEntityIterator_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_SUEntityIterator_PythonToCpp_SUEntityIterator_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_SUEntityIterator_TypeF())))
        return SUEntityIterator_PythonToCpp_SUEntityIterator_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *SUEntityIterator_PTR_CppToPython_SUEntityIterator(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::SUEntityIterator *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_SUEntityIterator_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *SUEntityIterator_SignatureStrings[] = {
    "suapi.SUEntityIterator()",
    "suapi.SUEntityIterator.__iter__()->suapi.SUEntityIterator",
    "suapi.SUEntityIterator.__next__()->suapi.SUEntity",
    nullptr}; // Sentinel

void init_SUEntityIterator(PyObject *module)
{
    _Sbk_SUEntityIterator_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "SUEntityIterator",
        "SUEntityIterator*",
        &Sbk_SUEntityIterator_spec,
        SUEntityIterator_SignatureStrings,
        &Shiboken::callCppDestructor< ::SUEntityIterator >,
        0,
        0,
        0    );
    
    SbksuapiTypes[SBK_SUENTITYITERATOR_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_SUEntityIterator_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_SUEntityIterator_TypeF(),
        SUEntityIterator_PythonToCpp_SUEntityIterator_PTR,
        is_SUEntityIterator_PythonToCpp_SUEntityIterator_PTR_Convertible,
        SUEntityIterator_PTR_CppToPython_SUEntityIterator);

    Shiboken::Conversions::registerConverterName(converter, "SUEntityIterator");
    Shiboken::Conversions::registerConverterName(converter, "SUEntityIterator*");
    Shiboken::Conversions::registerConverterName(converter, "SUEntityIterator&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEntityIterator).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::SUEntityIteratorWrapper).name());



}
