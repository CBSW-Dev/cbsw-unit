#pragma once

#define CBSW_UNIT_FIXTURE_MAKE_NAMESPACE(COUNTER) CBSW_UNIT_CONCATENATE(CBSW_UNIT_FIXTURE,COUNTER)
#define CBSW_UNIT_FIXTURE_MAKE_VARIABLE(COUNTER) CBSW_UNIT_CONCATENATE(cbsw_unit_fixture_,COUNTER)


#define CBSW_UNIT_FIXTURE_(description, COUNTER, FILE, LINE)                                                                                            \
/*A fixture is a syntactic sugar for a namespace, with a variable to store all the objects declared within the namespace*/                  \
namespace CBSW_UNIT_FIXTURE_MAKE_NAMESPACE(COUNTER) {                                                                                       \
    /*Declare a local variable that will be used to store the fixtures, and cases*/                                                         \
    ::CBSW::Unit::Fixture CBSW_UNIT_FIXTURE_MAKE_VARIABLE(COUNTER)(cbsw_unit_fixture(), description, FILE, LINE);                   \
    /*Create a function that can be used to access this variable (providing a consitent name so that the case macros know what to call)     \
    /*This works because scope resolution will pick up the "closest" function with this name"*/                                             \
    [[maybe_unused]] ::CBSW::Unit::Fixture& cbsw_unit_fixture() {                                                                                \
        return CBSW_UNIT_FIXTURE_MAKE_VARIABLE(COUNTER);                                                                                    \
    }                                                                                                                                       \
}                                                                                                                                           \
/*Now the user can provide the content of the namespace providing their own braces*/                                                        \
namespace CBSW_UNIT_FIXTURE_MAKE_NAMESPACE(COUNTER)

#define CBSW_UNIT_FIXTURE(description) CBSW_UNIT_FIXTURE_(description, __COUNTER__, __FILE__, __LINE__)