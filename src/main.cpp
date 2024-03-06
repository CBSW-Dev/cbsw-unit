#include "suite/internal-runner.hpp"

#include <iostream>

namespace {
    ::CBSW::Unit::InternalRunner runner;
}

int main(int argc, char** argv) {
    try {
        runner.initialise(argc, argv);
        return cbsw_unit_main(runner);
    } catch (std::exception& exception) {
        std::string error = exception.what();
        std::cout << "Application failed with exception: \r\n    " << error << std::endl;
    } catch (...) {
        std::cout << "Application failed with unknown exception" << std::endl;
    }
    return EXIT_FAILURE;
}