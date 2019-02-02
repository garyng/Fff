#pragma once

// For Hypodermic
template<class ArgumentType, class ResultType>
struct unary_function
{
	typedef ArgumentType argument_type;
	typedef ResultType result_type;
};

#include <memory.h>

#include <imgui.h>
#include <bindings/imgui_impl_freeglut.h>
#include <bindings/imgui_impl_opengl2.h>
#include <GL/freeglut.h>

#ifdef _MSC_VER
#pragma warning (disable: 4505) // unreferenced local function has been removed
#endif

#include <Hypodermic/ContainerBuilder.h>

#include <coveo/linq.h>
using namespace coveo::linq;

#ifdef _MSC_VER
template <class TDerived, class TBase>
using IsBaseOf = std::enable_if_t<std::is_base_of_v<TBase, TDerived>>;
#elif __GNUC__
// code::blocks's gcc is too old
template <class TDerived, class TBase>
using IsBaseOf = typename std::enable_if<std::is_base_of<TBase, TDerived>::value>::type;
#endif
