#pragma once

#include <map>
#include <string>

namespace CBSW::Unit {
    class ArgumentParser {
    public:
        ArgumentParser(int argc, char** argv) noexcept;

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