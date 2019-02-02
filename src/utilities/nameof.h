#pragma once

#include <string>
#include <typeinfo>
#include <boost/core/demangle.hpp>

std::string demangle(const char* name);

// from https://stackoverflow.com/questions/281818/unmangling-the-result-of-stdtype-infoname
template <class T>
std::string nameof(const T& t)
{
	return boost::core::demangle(typeid(t).name());
}
