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
#ifndef _PY_API_OBJECT_
#define _PY_API_OBJECT_


#ifdef __cplusplus
extern "C" {
#endif

#define PyObject_VAR_HEAD
#define PyObject_HEAD_INIT
#define PyObject_HEAD

typedef struct
{
    const char* tp_name;
    void* tp_alloc;
} PyTypeObject;

typedef struct
{
} PyObject;

typedef struct 
{
} PyMethodObject;

typedef struct
{
    int ob_size;
} PyVarObject;



int Py_INCREF(PyObject* obj);
int Py_DECREF(PyObject* obj);
#define Py_XINCREF(x); {if(x) Py_INCREF(x);}
#define Py_XDECREF(x); {if(x) Py_DECREF(x);}



PyObject* PyObject_New(void*, PyTypeObject *type);
void PyObject_Del(PyObject* obj);

#ifdef __cplusplus
}
#endif
#endif // _PY_API_OBJECT_
