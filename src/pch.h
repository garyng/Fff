﻿#pragma once

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

#include "utilities/constraints.h"