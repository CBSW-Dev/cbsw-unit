#include "internal-runner.hpp"

namespace {
    ::CBSW::Unit::InternalRunner runner;
}

int main(int argc, char** argv) {
    runner.initialise(argc, argv);
    return cbsw_unit_main(runner);
}