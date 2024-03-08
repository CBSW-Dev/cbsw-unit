#include "suite/internal-runner.hpp"
#include "plugin/plugins.hpp"

#include <iostream>

namespace {
    ::CBSW::Unit::InternalRunner runner;
}

int delegateMain(::CBSW::Unit::Arguments& arguments) {
    return cbsw_unit_main(arguments, runner);
}

int delegatePlugins(::CBSW::Unit::Arguments& arguments) {
    return cbsw_unit_plugins().run(arguments, &delegateMain);
}

int main(int argc, char** argv) {
    ::CBSW::Unit::Arguments arguments(argv, argv + argc);
    try {
        return runner.initialise(arguments, &delegatePlugins);

    } catch (std::exception& exception) {
        std::string error = exception.what();
        std::cout << "Application failed with exception: \r\n    " << error << std::endl;
    } catch (...) {
        std::cout << "Application failed with unknown exception" << std::endl;
    }
    return EXIT_FAILURE;
}