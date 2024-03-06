#include "pch.hpp"
#include "argument-parser.hpp"

namespace CBSW::Unit {
    namespace {
        inline bool isCbswUnitArgument(const std::string& argument) {
            return argument.substr(0, 11) == "--cbsw-unit";
        }

        using KeyValuePair = std::pair<std::string, std::string>;

        KeyValuePair parseArgument(const std::string& argument) {
            auto pos = argument.find('=');
            if (pos == argument.npos) {
                return KeyValuePair(argument, "");
            }

            return KeyValuePair(argument.substr(0, pos), argument.substr(pos+1));
        }
    }

    ArgumentParser::ArgumentParser(int argc, char** argv) noexcept {
        for (int i = 0; i < argc; ++i) {
            std::string argument = argv[i];
            if (isCbswUnitArgument(argument)) {
                _args.insert(parseArgument(argument));
            }
        }
    }

    ArgumentParser::Argument ArgumentParser::getArgument(const std::string& key) const noexcept {
        auto it = _args.find(key);
        if (it == _args.end()) {
            return Argument{false, ""};
        }
        return Argument{true, it->second};
    }
}