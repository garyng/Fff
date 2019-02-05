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

#include "imgui_custom.h"
#include "utilities/constraints.h"
#include "utilities/nameof.h"
#include "logger/ILogger.h"
#include "Vectors.h"

# define PI 3.141592653589793238462643383279502884L /* pi */

#include <boost/format.hpp>
#include <boost/core/demangle.hpp>