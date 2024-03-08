#include "suite/internal-runner.hpp"
#include "plugin/plugins.hpp"

#include <iostream>

namespace {
    ::CBSW::Unit::InternalRunner runner;
}

int delegateMain(int argc, char** argv) {
    return cbsw_unit_main(argc, argv, runner);
}

int delegatePlugins(int argc, char** argv) {
    return cbsw_unit_plugins().run(argc, argv, &delegateMain);
}

int main(int argc, char** argv) {
    try {
        return runner.initialise(argc, argv, &delegatePlugins);

    } catch (std::exception& exception) {
        std::string error = exception.what();
        std::cout << "Application failed with exception: \r\n    " << error << std::endl;
    } catch (...) {
        std::cout << "Application failed with unknown exception" << std::endl;
    }
    return EXIT_FAILURE;
}