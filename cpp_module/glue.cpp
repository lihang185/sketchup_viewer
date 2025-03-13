#include <Python.h>

// @snippet my_format_string
// hahaha1
// @snippet my_format_string

// @snippet return_pyunicode
return PyUnicode_FromWideChar(%in.c_str(), %in.size());
// @snippet return_pyunicode

// @snippet conversion_pyunicode
Py_UNICODE* unicode = PyUnicode_AS_UNICODE(%in);
size_t size = PyUnicode_GET_SIZE(%in);
%out = std::wstring(unicode, size);
// @snippet conversion_pyunicode

// @snippet conversion_pynone
%out = %OUTTYPE();
// @snippet conversion_pynone

