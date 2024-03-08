#pragma once

#include "utility/macros.hpp"

#define CBSW_UNIT_BEFORE_EACH_MAKE_VARIABLE(COUNTER) CBSW_UNIT_CONCATENATE(cbsw_unit_before_each_,COUNTER)
#define CBSW_UNIT_BEFORE_EACH_MAKE_FUNCTION(COUNTER) CBSW_UNIT_CONCATENATE(cbsw_unit_before_each_func_,COUNTER)

#define CBSW_UNIT_BEFORE_EACH_(COUNTER, FILE, LINE)                                                                                                                 \
    /*Forward declare the function*/                                                                                                                                \
    void CBSW_UNIT_BEFORE_EACH_MAKE_FUNCTION(COUNTER)() noexcept;                                                                                                   \
                                                                                                                                                                    \
    /*Allocate a local variable giving it the current fixture from the scope, a pointer to the function, the description, filename, and line number*/               \
    const ::CBSW::Unit::BeforeEach CBSW_UNIT_BEFORE_EACH_MAKE_VARIABLE(COUNTER)(*cbsw_unit_fixture(), &CBSW_UNIT_BEFORE_EACH_MAKE_FUNCTION(COUNTER), FILE, LINE);    \
                                                                                                                                                                    \
    /*Allow the user to provide the implementation*/                                                                                                                \
    void CBSW_UNIT_BEFORE_EACH_MAKE_FUNCTION(COUNTER)() noexcept

#define CBSW_UNIT_BEFORE_EACH() CBSW_UNIT_BEFORE_EACH_(__COUNTER__, __FILE__, __LINE__)