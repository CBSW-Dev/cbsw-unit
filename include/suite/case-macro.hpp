#pragma once

#include "utility/macros.hpp"

#define CBSW_UNIT_CASE_MAKE_VARIABLE(COUNTER) CBSW_UNIT_CONCATENATE(cbsw_unit_scenario_,COUNTER)
#define CBSW_UNIT_CASE_MAKE_FUNCTION(COUNTER) CBSW_UNIT_CONCATENATE(cbsw_unit_scenario_func_,COUNTER)

#define CBSW_UNIT_CASE_(description, COUNTER, FILE, LINE)                                                                                                           \
    /*Forward declare the function*/                                                                                                                                    \
    void CBSW_UNIT_CASE_MAKE_FUNCTION(COUNTER)(::CBSW::Unit::ICase& cbsw_unit_case);                                                                                          \
                                                                                                                                                                        \
    /*Allocate a local variable giving it the current fixture from the scope, a pointer to the function, the description, filename, and line number*/                   \
    const ::CBSW::Unit::Case CBSW_UNIT_CASE_MAKE_VARIABLE(COUNTER)(*cbsw_unit_fixture(), &CBSW_UNIT_CASE_MAKE_FUNCTION(COUNTER), description, FILE, LINE);   \
                                                                                                                                                                        \
    /*Allow the user to provide the implementation*/                                                                                                                    \
    void CBSW_UNIT_CASE_MAKE_FUNCTION(COUNTER)([[maybe_unused]]::CBSW::Unit::ICase& cbsw_unit_case)

#define CBSW_UNIT_CASE(description) CBSW_UNIT_CASE_(description, __COUNTER__, __FILE__, __LINE__)