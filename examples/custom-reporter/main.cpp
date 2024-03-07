#include "custom-reporter.hpp"

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

int cbsw_unit_main(int argc, char** argv, ::CBSW::Unit::Runner& runner) {
    CustomReporter reporter(runner.output());
    runner.setReporter(reporter);
    return runner.run();
}