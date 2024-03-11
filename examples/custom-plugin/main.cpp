#include "custom-plugin.hpp"

#include <iostream>
#include <cbsw-unit>

#define suite CBSW_UNIT_SUITE
#define describe CBSW_UNIT_FIXTURE
#define it CBSW_UNIT_CASE
#define assert CBSW_UNIT_ASSERT
#define beforeEach CBSW_UNIT_BEFORE_EACH
#define afterEach CBSW_UNIT_AFTER_EACH

suite("Test Suite") {
    describe("This is a test fixture") {
        beforeEach() {

        }

        afterEach() {

        }

        it("This is a failing scenario") {
            assert(1 == 0);
        }

        it("This is a passing scenario") {
            assert(1 == 1);
        }
    }
}

//this registers the plugin with the cbsw-unit plugins.
//If the application is run with the command line parameter --custom-plugin-trap then the application will not run the tests,
//but rather, print a message and exit
CustomPlugin customPlugin;

int cbsw_unit_main(::CBSW::Unit::Arguments& arguments, ::CBSW::Unit::Runner& runner) {
    runner.installPlugin(customPlugin);
    return runner.run();
}