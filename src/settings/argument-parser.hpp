#pragma once

#include "plugin/arguments.hpp"

#include <map>
#include <string>

namespace CBSW::Unit {
    class ArgumentParser {
    public:
        ArgumentParser(const Arguments& arguments) noexcept;

        struct Argument {
            bool isValid;
            std::string value;
        };

        Argument getArgument(const std::string& key) const noexcept;
    private:
        using ArgMap = std::map<std::string, std::string>;
        ArgMap _args;

    };
}