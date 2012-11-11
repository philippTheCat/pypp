#ifndef _PYPP_API_STRINGOBJECT_
#define _PYPP_API_STRINGOBJECT_


typedef struct
{
    
} PyString_Type;


PyObject* PyString_FromString(const char* str);
PyObject* PyString_FromStringAndSize(const char* str, Py_ssize_t len);




#endif // _PYPP_API_STRINGOBJECT_

