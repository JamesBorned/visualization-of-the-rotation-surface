#pragma once

#include "line.hpp"
#include "parabola.hpp"
#include "parallel.hpp"
#include "surface.hpp"

namespace mt {
	Function* FunctionFactory(const std::string& funcName);
}