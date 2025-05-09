
#include <sbkpython.h>
#include <shiboken.h>
#include <algorithm>
#include <signature.h>
#include "suapi_python.h"



// Extra includes

// Current module's type array.
PyTypeObject **SbksuapiTypes = nullptr;
// Current module's PyObject pointer.
PyObject *SbksuapiModuleObject = nullptr;
// Current module's converter array.
SbkConverter **SbksuapiTypeConverters = nullptr;
// Global functions ------------------------------------------------------------

static PyMethodDef suapi_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_TriangleMesh(PyObject *module);
void init_SUUVHelper(PyObject *module);
void init_SUModel(PyObject *module);
void init_SUEntityIterator(PyObject *module);
void init_SUEntity(PyObject *module);
void init_SUMaterial(PyObject *module);
void init_SULoop(PyObject *module);
void init_SUVertex(PyObject *module);
void init_SUTexture(PyObject *module);
void init_SUEdgeUse(PyObject *module);
void init_SUDrawingElement(PyObject *module);
void init_SUFace(PyObject *module);
void init_SUEntities(PyObject *module);
void init_SUEdge(PyObject *module);
void init_SUComponentInstance(PyObject *module);
void init_SUComponentDefinition(PyObject *module);
void init_SUAttributeDictionary(PyObject *module);
void init_CVector3D(PyObject *module);
void init_CVector2D(PyObject *module);
void init_CPlane(PyObject *module);
void init_CMatrix33(PyObject *module);
void init_CMatrix(PyObject *module);


// Module initialization ------------------------------------------------------------

// Primitive Type converters.

// C++ to Python conversion for type 'std::wstring'.
static PyObject *std_wstring_CppToPython_std_wstring(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::wstring *>(const_cast<void *>(cppIn));
    // ========================================================================
    // START of custom code block [file: glue.cpp (return_pyunicode)]
    return PyUnicode_FromWideChar(cppInRef.c_str(), cppInRef.size());

    // END of custom code block [file: glue.cpp (return_pyunicode)]
    // ========================================================================

}
// Python to C++ conversions for type 'std::wstring'.
static void PyUnicode_PythonToCpp_std_wstring(PyObject *pyIn, void *cppOut) {
    // ========================================================================
    // START of custom code block [file: glue.cpp (conversion_pyunicode)]
    Py_UNICODE* unicode = PyUnicode_AS_UNICODE(pyIn);
    size_t size = PyUnicode_GET_SIZE(pyIn);
    *reinterpret_cast<::std::wstring *>(cppOut) = std::wstring(unicode, size);

    // END of custom code block [file: glue.cpp (conversion_pyunicode)]
    // ========================================================================

}
static PythonToCppFunc is_PyUnicode_PythonToCpp_std_wstring_Convertible(PyObject *pyIn) {
    if (PyUnicode_Check(pyIn))
        return PyUnicode_PythonToCpp_std_wstring;
    return {};
}
static void Py_None_PythonToCpp_std_wstring(PyObject *pyIn, void *cppOut) {
    // ========================================================================
    // START of custom code block [file: glue.cpp (conversion_pynone)]
    *reinterpret_cast<::std::wstring *>(cppOut) = std::wstring();

    // END of custom code block [file: glue.cpp (conversion_pynone)]
    // ========================================================================

}
static PythonToCppFunc is_Py_None_PythonToCpp_std_wstring_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Py_None_PythonToCpp_std_wstring;
    return {};
}


// Container Type converters.

// C++ to Python conversion for type 'std::vector<double >'.
static PyObject *std_vector_double__CppToPython_std_vector_double_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<double > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<double >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        double cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_double__PythonToCpp_std_vector_double_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<double > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    double cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_double__PythonToCpp_std_vector_double__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<double>(), pyIn))
        return std_vector_double__PythonToCpp_std_vector_double_;
    return {};
}

// C++ to Python conversion for type 'std::vector<std::wstring >'.
static PyObject *std_vector_std_wstring__CppToPython_std_vector_std_wstring_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<std::wstring > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<std::wstring >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::std::wstring cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX], &cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_std_wstring__PythonToCpp_std_vector_std_wstring_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<std::wstring > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::std::wstring cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX], pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_std_wstring__PythonToCpp_std_vector_std_wstring__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX], pyIn))
        return std_vector_std_wstring__PythonToCpp_std_vector_std_wstring_;
    return {};
}

// C++ to Python conversion for type 'std::vector<SUAttributeDictionary* >'.
static PyObject *std_vector_SUAttributeDictionaryPTR__CppToPython_std_vector_SUAttributeDictionaryPTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<SUAttributeDictionary* > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<SUAttributeDictionary* >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::SUAttributeDictionary* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUATTRIBUTEDICTIONARY_IDX]), cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_SUAttributeDictionaryPTR__PythonToCpp_std_vector_SUAttributeDictionaryPTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<SUAttributeDictionary* > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::SUAttributeDictionary* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUATTRIBUTEDICTIONARY_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_SUAttributeDictionaryPTR__PythonToCpp_std_vector_SUAttributeDictionaryPTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbksuapiTypes[SBK_SUATTRIBUTEDICTIONARY_IDX], pyIn))
        return std_vector_SUAttributeDictionaryPTR__PythonToCpp_std_vector_SUAttributeDictionaryPTR_;
    return {};
}

// C++ to Python conversion for type 'std::vector<SUEdge* >'.
static PyObject *std_vector_SUEdgePTR__CppToPython_std_vector_SUEdgePTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<SUEdge* > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<SUEdge* >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::SUEdge* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUEDGE_IDX]), cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_SUEdgePTR__PythonToCpp_std_vector_SUEdgePTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<SUEdge* > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::SUEdge* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUEDGE_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_SUEdgePTR__PythonToCpp_std_vector_SUEdgePTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbksuapiTypes[SBK_SUEDGE_IDX], pyIn))
        return std_vector_SUEdgePTR__PythonToCpp_std_vector_SUEdgePTR_;
    return {};
}

// C++ to Python conversion for type 'std::vector<SUFace* >'.
static PyObject *std_vector_SUFacePTR__CppToPython_std_vector_SUFacePTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<SUFace* > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<SUFace* >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::SUFace* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUFACE_IDX]), cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_SUFacePTR__PythonToCpp_std_vector_SUFacePTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<SUFace* > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::SUFace* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUFACE_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_SUFacePTR__PythonToCpp_std_vector_SUFacePTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbksuapiTypes[SBK_SUFACE_IDX], pyIn))
        return std_vector_SUFacePTR__PythonToCpp_std_vector_SUFacePTR_;
    return {};
}

// C++ to Python conversion for type 'std::vector<SUComponentInstance* >'.
static PyObject *std_vector_SUComponentInstancePTR__CppToPython_std_vector_SUComponentInstancePTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<SUComponentInstance* > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<SUComponentInstance* >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::SUComponentInstance* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX]), cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_SUComponentInstancePTR__PythonToCpp_std_vector_SUComponentInstancePTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<SUComponentInstance* > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::SUComponentInstance* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_SUComponentInstancePTR__PythonToCpp_std_vector_SUComponentInstancePTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbksuapiTypes[SBK_SUCOMPONENTINSTANCE_IDX], pyIn))
        return std_vector_SUComponentInstancePTR__PythonToCpp_std_vector_SUComponentInstancePTR_;
    return {};
}

// C++ to Python conversion for type 'std::vector<SULoop* >'.
static PyObject *std_vector_SULoopPTR__CppToPython_std_vector_SULoopPTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<SULoop* > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<SULoop* >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::SULoop* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SULOOP_IDX]), cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_SULoopPTR__PythonToCpp_std_vector_SULoopPTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<SULoop* > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::SULoop* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SULOOP_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_SULoopPTR__PythonToCpp_std_vector_SULoopPTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbksuapiTypes[SBK_SULOOP_IDX], pyIn))
        return std_vector_SULoopPTR__PythonToCpp_std_vector_SULoopPTR_;
    return {};
}

// C++ to Python conversion for type 'std::vector<SUEdgeUse* >'.
static PyObject *std_vector_SUEdgeUsePTR__CppToPython_std_vector_SUEdgeUsePTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<SUEdgeUse* > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<SUEdgeUse* >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::SUEdgeUse* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUEDGEUSE_IDX]), cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_SUEdgeUsePTR__PythonToCpp_std_vector_SUEdgeUsePTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<SUEdgeUse* > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::SUEdgeUse* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUEDGEUSE_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_SUEdgeUsePTR__PythonToCpp_std_vector_SUEdgeUsePTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbksuapiTypes[SBK_SUEDGEUSE_IDX], pyIn))
        return std_vector_SUEdgeUsePTR__PythonToCpp_std_vector_SUEdgeUsePTR_;
    return {};
}

// C++ to Python conversion for type 'std::vector<SUVertex* >'.
static PyObject *std_vector_SUVertexPTR__CppToPython_std_vector_SUVertexPTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<SUVertex* > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<SUVertex* >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::SUVertex* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUVERTEX_IDX]), cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_SUVertexPTR__PythonToCpp_std_vector_SUVertexPTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<SUVertex* > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::SUVertex* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUVERTEX_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_SUVertexPTR__PythonToCpp_std_vector_SUVertexPTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbksuapiTypes[SBK_SUVERTEX_IDX], pyIn))
        return std_vector_SUVertexPTR__PythonToCpp_std_vector_SUVertexPTR_;
    return {};
}

// C++ to Python conversion for type 'std::vector<SUComponentDefinition* >'.
static PyObject *std_vector_SUComponentDefinitionPTR__CppToPython_std_vector_SUComponentDefinitionPTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<SUComponentDefinition* > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<SUComponentDefinition* >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::SUComponentDefinition* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX]), cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_SUComponentDefinitionPTR__PythonToCpp_std_vector_SUComponentDefinitionPTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<SUComponentDefinition* > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::SUComponentDefinition* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_SUComponentDefinitionPTR__PythonToCpp_std_vector_SUComponentDefinitionPTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbksuapiTypes[SBK_SUCOMPONENTDEFINITION_IDX], pyIn))
        return std_vector_SUComponentDefinitionPTR__PythonToCpp_std_vector_SUComponentDefinitionPTR_;
    return {};
}

// C++ to Python conversion for type 'std::vector<SUMaterial* >'.
static PyObject *std_vector_SUMaterialPTR__CppToPython_std_vector_SUMaterialPTR_(const void *cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<SUMaterial* > *>(const_cast<void *>(cppIn));

            // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::std::vector<SUMaterial* >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
        ::SUMaterial* cppItem(*it);
        PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUMATERIAL_IDX]), cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void std_vector_SUMaterialPTR__PythonToCpp_std_vector_SUMaterialPTR_(PyObject *pyIn, void *cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<SUMaterial* > *>(cppOut);

          // TEMPLATE - pyseq_to_cpplist_conversion - START
    // PYSIDE-795: Turn all sequences into iterables.
    Shiboken::AutoDecRef it(PyObject_GetIter(pyIn));
    PyObject *(*iternext)(PyObject *) = *Py_TYPE(it)->tp_iternext;
    for (;;) {
    Shiboken::AutoDecRef pyItem(iternext(it));
    if (pyItem.isNull()) {
    if (PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_StopIteration))
    PyErr_Clear();
    break;
    }
    ::SUMaterial* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbksuapiTypes[SBK_SUMATERIAL_IDX]), pyItem, &(cppItem));
    cppOutRef.push_back(cppItem);
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is_std_vector_SUMaterialPTR__PythonToCpp_std_vector_SUMaterialPTR__Convertible(PyObject *pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbksuapiTypes[SBK_SUMATERIAL_IDX], pyIn))
        return std_vector_SUMaterialPTR__PythonToCpp_std_vector_SUMaterialPTR_;
    return {};
}


#if defined _WIN32 || defined __CYGWIN__
    #define SBK_EXPORT_MODULE __declspec(dllexport)
#elif __GNUC__ >= 4
    #define SBK_EXPORT_MODULE __attribute__ ((visibility("default")))
#else
    #define SBK_EXPORT_MODULE
#endif

#ifdef IS_PY3K
static struct PyModuleDef moduledef = {
    /* m_base     */ PyModuleDef_HEAD_INIT,
    /* m_name     */ "suapi",
    /* m_doc      */ nullptr,
    /* m_size     */ -1,
    /* m_methods  */ suapi_methods,
    /* m_reload   */ nullptr,
    /* m_traverse */ nullptr,
    /* m_clear    */ nullptr,
    /* m_free     */ nullptr
};

#endif

// The signatures string for the global functions.
// Multiple signatures have their index "n:" in front.
static const char *suapi_SignatureStrings[] = {
    nullptr}; // Sentinel

SBK_MODULE_INIT_FUNCTION_BEGIN(suapi)
    // Create an array of wrapper types for the current module.
    static PyTypeObject *cppApi[SBK_suapi_IDX_COUNT];
    SbksuapiTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter *sbkConverters[SBK_suapi_CONVERTERS_IDX_COUNT];
    SbksuapiTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject *module = Shiboken::Module::create("suapi", &moduledef);
#else
    PyObject *module = Shiboken::Module::create("suapi", suapi_methods);
#endif

    // Make module available from global scope
    SbksuapiModuleObject = module;

    // Initialize classes in the type system
    init_TriangleMesh(module);
    init_SUUVHelper(module);
    init_SUModel(module);
    init_SUEntityIterator(module);
    init_SUEntity(module);
    init_SUMaterial(module);
    init_SULoop(module);
    init_SUVertex(module);
    init_SUTexture(module);
    init_SUEdgeUse(module);
    init_SUDrawingElement(module);
    init_SUFace(module);
    init_SUEntities(module);
    init_SUEdge(module);
    init_SUComponentInstance(module);
    init_SUComponentDefinition(module);
    init_SUAttributeDictionary(module);
    init_CVector3D(module);
    init_CVector2D(module);
    init_CPlane(module);
    init_CMatrix33(module);
    init_CMatrix(module);

    // Register converter for type 'suapi.std::wstring'.
    SbksuapiTypeConverters[SBK_STD_WSTRING_IDX] = Shiboken::Conversions::createConverter(0, std_wstring_CppToPython_std_wstring);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX], "std::wstring");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX],
        PyUnicode_PythonToCpp_std_wstring,
        is_PyUnicode_PythonToCpp_std_wstring_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_STD_WSTRING_IDX],
        Py_None_PythonToCpp_std_wstring,
        is_Py_None_PythonToCpp_std_wstring_Convertible);


    // Register converter for type 'std::vector<double>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_DOUBLE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_double__CppToPython_std_vector_double_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_DOUBLE_IDX], "std::vector<double>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_DOUBLE_IDX],
        std_vector_double__PythonToCpp_std_vector_double_,
        is_std_vector_double__PythonToCpp_std_vector_double__Convertible);

    // Register converter for type 'std::vector<std::wstring>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_STD_WSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_std_wstring__CppToPython_std_vector_std_wstring_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_STD_WSTRING_IDX], "std::vector<std::wstring>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_STD_WSTRING_IDX],
        std_vector_std_wstring__PythonToCpp_std_vector_std_wstring_,
        is_std_vector_std_wstring__PythonToCpp_std_vector_std_wstring__Convertible);

    // Register converter for type 'std::vector<SUAttributeDictionary*>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUATTRIBUTEDICTIONARYPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_SUAttributeDictionaryPTR__CppToPython_std_vector_SUAttributeDictionaryPTR_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUATTRIBUTEDICTIONARYPTR_IDX], "std::vector<SUAttributeDictionary*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUATTRIBUTEDICTIONARYPTR_IDX],
        std_vector_SUAttributeDictionaryPTR__PythonToCpp_std_vector_SUAttributeDictionaryPTR_,
        is_std_vector_SUAttributeDictionaryPTR__PythonToCpp_std_vector_SUAttributeDictionaryPTR__Convertible);

    // Register converter for type 'std::vector<SUEdge*>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUEDGEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_SUEdgePTR__CppToPython_std_vector_SUEdgePTR_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUEDGEPTR_IDX], "std::vector<SUEdge*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUEDGEPTR_IDX],
        std_vector_SUEdgePTR__PythonToCpp_std_vector_SUEdgePTR_,
        is_std_vector_SUEdgePTR__PythonToCpp_std_vector_SUEdgePTR__Convertible);

    // Register converter for type 'std::vector<SUFace*>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUFACEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_SUFacePTR__CppToPython_std_vector_SUFacePTR_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUFACEPTR_IDX], "std::vector<SUFace*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUFACEPTR_IDX],
        std_vector_SUFacePTR__PythonToCpp_std_vector_SUFacePTR_,
        is_std_vector_SUFacePTR__PythonToCpp_std_vector_SUFacePTR__Convertible);

    // Register converter for type 'std::vector<SUComponentInstance*>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTINSTANCEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_SUComponentInstancePTR__CppToPython_std_vector_SUComponentInstancePTR_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTINSTANCEPTR_IDX], "std::vector<SUComponentInstance*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTINSTANCEPTR_IDX],
        std_vector_SUComponentInstancePTR__PythonToCpp_std_vector_SUComponentInstancePTR_,
        is_std_vector_SUComponentInstancePTR__PythonToCpp_std_vector_SUComponentInstancePTR__Convertible);

    // Register converter for type 'std::vector<SULoop*>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SULOOPPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_SULoopPTR__CppToPython_std_vector_SULoopPTR_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SULOOPPTR_IDX], "std::vector<SULoop*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SULOOPPTR_IDX],
        std_vector_SULoopPTR__PythonToCpp_std_vector_SULoopPTR_,
        is_std_vector_SULoopPTR__PythonToCpp_std_vector_SULoopPTR__Convertible);

    // Register converter for type 'std::vector<SUEdgeUse*>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUEDGEUSEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_SUEdgeUsePTR__CppToPython_std_vector_SUEdgeUsePTR_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUEDGEUSEPTR_IDX], "std::vector<SUEdgeUse*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUEDGEUSEPTR_IDX],
        std_vector_SUEdgeUsePTR__PythonToCpp_std_vector_SUEdgeUsePTR_,
        is_std_vector_SUEdgeUsePTR__PythonToCpp_std_vector_SUEdgeUsePTR__Convertible);

    // Register converter for type 'std::vector<SUVertex*>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUVERTEXPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_SUVertexPTR__CppToPython_std_vector_SUVertexPTR_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUVERTEXPTR_IDX], "std::vector<SUVertex*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUVERTEXPTR_IDX],
        std_vector_SUVertexPTR__PythonToCpp_std_vector_SUVertexPTR_,
        is_std_vector_SUVertexPTR__PythonToCpp_std_vector_SUVertexPTR__Convertible);

    // Register converter for type 'std::vector<SUComponentDefinition*>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTDEFINITIONPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_SUComponentDefinitionPTR__CppToPython_std_vector_SUComponentDefinitionPTR_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTDEFINITIONPTR_IDX], "std::vector<SUComponentDefinition*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUCOMPONENTDEFINITIONPTR_IDX],
        std_vector_SUComponentDefinitionPTR__PythonToCpp_std_vector_SUComponentDefinitionPTR_,
        is_std_vector_SUComponentDefinitionPTR__PythonToCpp_std_vector_SUComponentDefinitionPTR__Convertible);

    // Register converter for type 'std::vector<SUMaterial*>'.
    SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUMATERIALPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_vector_SUMaterialPTR__CppToPython_std_vector_SUMaterialPTR_);
    Shiboken::Conversions::registerConverterName(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUMATERIALPTR_IDX], "std::vector<SUMaterial*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbksuapiTypeConverters[SBK_SUAPI_STD_VECTOR_SUMATERIALPTR_IDX],
        std_vector_SUMaterialPTR__PythonToCpp_std_vector_SUMaterialPTR_,
        is_std_vector_SUMaterialPTR__PythonToCpp_std_vector_SUMaterialPTR__Convertible);

    // Register primitive types converters.

    Shiboken::Module::registerTypes(module, SbksuapiTypes);
    Shiboken::Module::registerTypeConverters(module, SbksuapiTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module suapi");
    }
    FinishSignatureInitialization(module, suapi_SignatureStrings);

SBK_MODULE_INIT_FUNCTION_END
