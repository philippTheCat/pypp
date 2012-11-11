#ifndef _PYPP_API_FLOATOBJECT_
#define _PYPP_API_FLOATOBJECT_



typedef struct {
    PyObject_HEAD
    double ob_fval;
} PyFloatObject;

typedef struct {

} PyFloat_Type;


PyObject* PyFloat_FromString(PyObject* obj);
PyObject* PyFloat_FromDouble(double i);




#endif // _PYPP_API_FLOATOBJECT_

