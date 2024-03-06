#pragma once

#include "utility/macros.hpp"

#define CBSW_UNIT_AFTER_EACH_MAKE_VARIABLE(COUNTER) CBSW_UNIT_CONCATENATE(cbsw_unit_after_each_,COUNTER)
#define CBSW_UNIT_AFTER_EACH_MAKE_FUNCTION(COUNTER) CBSW_UNIT_CONCATENATE(cbsw_unit_after_each_func_,COUNTER)

#define CBSW_UNIT_AFTER_EACH_(COUNTER, FILE, LINE)                                                                                                           \
    /*Forward declare the function*/                                                                                                                                    \
    void CBSW_UNIT_AFTER_EACH_MAKE_FUNCTION(COUNTER)();                                                                                          \
                                                                                                                                                                        \
    /*Allocate a local variable giving it the current fixture from the scope, a pointer to the function, the description, filename, and line number*/                   \
    const ::CBSW::Unit::AfterEach CBSW_UNIT_AFTER_EACH_MAKE_VARIABLE(COUNTER)(cbsw_unit_fixture(), &CBSW_UNIT_AFTER_EACH_MAKE_FUNCTION(COUNTER), FILE, LINE);   \
                                                                                                                                                                        \
    /*Allow the user to provide the implementation*/                                                                                                                    \
    void CBSW_UNIT_AFTER_EACH_MAKE_FUNCTION(COUNTER)()

#define CBSW_UNIT_AFTER_EACH() CBSW_UNIT_AFTER_EACH_(__COUNTER__, __FILE__, __LINE__)