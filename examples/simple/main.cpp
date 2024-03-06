#include <cbsw-unit>

CBSW_UNIT_SUITE("Test Suite") {
    CBSW_UNIT_FIXTURE("This is a test fixture") {
        CBSW_UNIT_BEFORE_EACH() {

        }

        CBSW_UNIT_CASE("This is a failing scenario") {
            CBSW_UNIT_ASSERT(1 == 0);
        }

        CBSW_UNIT_CASE("This is a passing scenario") {
            CBSW_UNIT_ASSERT(1 == 1);
        }
    }
}

int cbsw_unit_main(::CBSW::Unit::Runner& runner) {
    return runner.run();
}