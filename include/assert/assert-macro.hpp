#pragma once

#include "utility/macros.hpp"

#define CBSW_UNIT_ASSERT(...) if (!( CBSW_UNIT_CONCATENATE(,__VA_ARGS__) )) {throw ::CBSW::Unit::AssertionException(cbsw_unit_case, #__VA_ARGS__, __FILE__, __LINE__);}