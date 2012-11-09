/*
 * This file is part of PyPP.
 *
 * PyPP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PyPP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PyPP.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _PY_API_TUPLE_
#define _PY_API_TUPLE_

#include "Python.h"

#ifdef __cplusplus
extern "C" {
#endif


PyObject*   PyTuple_New(Py_ssize_t len);
PyObject*   PyTuple_Pack(Py_ssize_t n, ...);
Py_ssize_t  PyTuple_Size(PyObject* tuple);
Py_ssize_t  PyTuple_GET_SIZE(PyObject* tuple);
PyObject*   PyTuple_GetItem(PyObject* tuple, Py_ssize_t pos);
PyObject*   PyTuple_GET_ITEM(PyObject* tuple, Py_ssize_t pos);
PyObject*   PyTuple_GetSlice(PyObject* tuple, Py_ssize_t low, Py_ssize_t high);
int         PyTuple_SetItem(PyObject* tuple, Py_ssize_t pos, PyObject* obj);
void        PyTuple_SET_ITEM(PyObject* tuple, Py_ssize_t pos, PyObject* obj);
int         PyTuple_Resize(PyObject** tuple, Py_ssize_t newsize);
int         PyTuple_ClearFreeList(void);



#ifdef __cplusplus
}
#endif
#endif // _PY_API_TUPLE_
