#pragma once
#include <Python.h>
#include <utility>
#include "malen/py_conversions.h"

namespace malen
{
template <typename KT, typename VT>
std::pair<PyObject*, PyObject*> kwarg(const KT &key, const VT &val)
{
    return {convert_to_python(key), convert_to_python(val)};
}

template <typename KT, template<typename...> class VC, typename VT>
std::pair<PyObject*, PyObject*> kwarg(const KT &key, const VC<VT> &val)
{
    return {convert_to_python(key), convert_to_python(val)};
}
}