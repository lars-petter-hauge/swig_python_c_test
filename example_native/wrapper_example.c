#include "Python.h"
#include <stdio.h>
#include "example.h"

static PyObject * example_wrapper(PyObject * self, PyObject * args)
{
  int input_a;
  int input_b;

  int result;
  PyObject * ret;

  // parse arguments
  if (!PyArg_ParseTuple(args, "ii", &input_a, &input_b)) {
    return NULL;
  }

  // run the actual function
  result = add(input_a, input_b);

  // build the resulting string into a Python object.
  ret = PyLong_FromLong(result);
  //free(result);

  return ret;
}

static PyMethodDef ExampleMethods[] = {
 { "add", example_wrapper, METH_VARARGS, "Add Numbers" },
 { NULL, NULL, 0, NULL }
};

static struct PyModuleDef add_definition = {
    PyModuleDef_HEAD_INIT,
    "add",
    "A Python module extension for C++ lib",
    -1,
    ExampleMethods
};

PyMODINIT_FUNC PyInit_example(void) {
    Py_Initialize();
    return PyModule_Create(&add_definition);
}
