#include "pathTable.h"

// PathTable initialization functions.
// For the interesting stuff, check pathTable.I


PathTable::
PathTable() {
}

PathTable::
~PathTable() {
}

PathTable::
PathTable(PyObject* pathData, PyObject* connections) {
  initTable(pathData, connections);
}


void PathTable::
initTable(PyObject* pathData, PyObject* connections) {
  StringUC str;
  int strlen;
  int len;
  int numNeighbors;
  std::vector<unsigned short> neighbors;
  PyObject *obj = NULL;
  PyObject *obj2 = NULL;
  unsigned short num
#if PY_MAJOR_VERSION >= 3
  bool unicode;
#endif

  // Init _pathData from received values (list of strings)
  _pathData.clear();

  if(!PyList_Check(pathData)) {
    PyErr_SetString(PyExc_TypeError, "pathData: Expected a list!");
    return;
  }

  len = PyList_Size(pathData);

  for(int i=0; i<len; ++i) {
    obj = PyList_GetItem(pathData,i);

#if PY_MAJOR_VERSION >= 3
    unicode = PyUnicode_Check(obj);

    if(unicode) {
      obj = PyUnicode_AsEncodedString(obj, "UTF-8", "strict");

      if(obj == NULL) {
        PyErr_SetString(PyExc_TypeError, "pathData: Could not decode UTF-8 string!");
        return;
      }
    } else if(!PyBytes_Check(obj)) {
      PyErr_SetString(PyExc_TypeError, "pathData: Non-string encountered in list!");
      return;
    }

    strlen = PyBytes_Size(obj);

    str.assign((unsigned char*)PyBytes_AsString(obj), strlen);

    if(unicode) {
      Py_DECREF(obj);
    }
#else
    if(!PyString_Check(obj)) {
      PyErr_SetString(PyExc_TypeError, "pathData: Non-string encountered in list!");
      return;
    }

    strlen = PyString_Size(obj);

    str.assign((unsigned char*)PyString_AsString(obj), strlen);
#endif

    _pathData.push_back(str);
  }

  // Init _connectionData from received values (list of list of int/None)
  _connectionData.clear();

  if(!PyList_Check(connections)) {
    PyErr_SetString(PyExc_TypeError, "connections: Expected a list!");
    return;    
  }

  len = PyList_Size(connections);

  for(int i=0; i<len; ++i) {
    obj = PyList_GetItem(connections,i);

    if (!PyList_Check(obj)) {
      PyErr_SetString(PyExc_TypeError, "connections: Non-list element encountered!");
      return;
    }

    neighbors.clear();

    numNeighbors = PyList_Size(obj);

    for(int j=0; j<numNeighbors; ++j) {
      obj2 = PyList_GetItem(obj,j);

#if PY_MAJOR_VERSION >= 3
      if(!PyLong_Check(obj2)) {
#else
      if(!PyInt_Check(obj2)) {
#endif
        if(obj2 != Py_None) {
          PyErr_SetString(PyExc_TypeError, "connections: Invalid sub-element encountered!");
          return;
        }
        num = 65535;
      }
      else {
#if PY_MAJOR_VERSION >= 3
        num = (unsigned short)PyLong_AsUnsignedLongMask(obj2);
#else
        num = (unsigned short)PyInt_AsUnsignedLongMask(obj2);
#endif
      }

      neighbors.push_back(num);
    }

    _connectionData.push_back(neighbors);
  }
}
