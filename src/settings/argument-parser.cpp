#include "pch.hpp"
#include "argument-parser.hpp"
#include "valid-library-arguments.hpp"

namespace CBSW::Unit {
    namespace {
        inline bool isCbswUnitArgument(const std::string& argument) {
            return ValidLibraryArguments::instance().find(argument) != ValidLibraryArguments::instance().end();
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

    ArgumentParser::ArgumentParser(const Arguments& arguments) noexcept {
        for (auto arg: arguments) {
            std::string argument(arg);
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