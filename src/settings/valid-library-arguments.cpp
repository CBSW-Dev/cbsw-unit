#include "pch.hpp"
#include "valid-library-arguments.hpp"

namespace CBSW::Unit {
    ValidLibraryArguments::ValidLibraryArguments() noexcept:
        std::set<std::string>::set{
            "--cbsw-unit-reporter",
            "--cbsw-unit-threads",
            "--cbsw-unit-color-support",
            "--cbsw-unit-version",
            "--cbsw-unit-help",
        }
    {}

    ValidLibraryArguments& ValidLibraryArguments::instance() noexcept {
        static ValidLibraryArguments arguments;
        return arguments;
    }
}