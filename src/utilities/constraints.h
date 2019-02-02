#pragma once

#ifdef _MSC_VER
template <class TDerived, class TBase>
using IsBaseOf = std::enable_if_t<std::is_base_of_v<TBase, TDerived>>;


template <class T>
using IsArithmetic = std::enable_if_t<std::is_arithmetic_v<T>>;

#elif __GNUC__
// code::blocks's gcc is too old
template <class TDerived, class TBase>
using IsBaseOf = typename std::enable_if<std::is_base_of<TBase, TDerived>::value>::type;

template <class T>
using IsArithmetic = typename std::enable_if<std::is_arithmetic<T>::value>::type;
#endif
