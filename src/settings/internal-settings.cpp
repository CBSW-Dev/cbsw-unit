#include "pch.hpp"
#include "internal-settings.hpp"
#include "argument-parser.hpp"

#include <set>
#include <sstream>

namespace CBSW::Unit {
    namespace {
        class StringSet: public std::set<std::string> {
        public:
            using std::set<std::string>::set;

            std::string join(const std::string& delimiter) const noexcept {
                std::ostringstream ss;
                std::string output;
                iterator it = begin();
                const iterator end = this->end();
                if (it == end) {
                    return "";
                }
                return contineJoin(it, end, delimiter);
            }
        private:
            std::string contineJoin(iterator& it, const iterator& end, const std::string& delimiter) const noexcept {
                std::stringstream output;
                output << (*it);
                ++it;
                for (;it != end; ++it) {
                    output << delimiter << (*it);
                }
                return output.str();
            }
        };


        using ValidReporters = StringSet;
        ValidReporters validReporters = {"spec", "dot", "min"};
        ValidReporters validColorSupport = {"none", "ansi"};

        void loadValidSetStringFromArgs(std::string& result, const ArgumentParser& arguments, const StringSet& set, const std::string& argument) {
            ArgumentParser::Argument arg = arguments.getArgument(argument);
            if (!arg.isValid) {
                return;
            }
            auto it = set.find(arg.value);
            if (it == set.end()) {
                std::string error = "Invalid command line option: ";
                error += argument;
                error += " must be one of [";
                error += set.join(",");
                error += "]";
                throw std::runtime_error(error.c_str());
            }
            result =  arg.value;
        }
    }
    InternalSettings::InternalSettings():
        _reporter("spec"),
        _threads(4),
        _colorSupport("none")
    {}

    const InternalSettings::ReporterType& InternalSettings::reporter() const noexcept {
        return _reporter;
    }

    InternalSettings::ThreadsType InternalSettings::threads() const noexcept {
        return _threads;
    }

    const InternalSettings::ColorSupportType& InternalSettings::colorSupport() const noexcept {
        return _colorSupport;
    }

    void InternalSettings::loadFromArgs(const ArgumentParser& arguments) {
        loadReporterFromArgs(arguments);
        loadThreadsFromArgs(arguments);
        loadColorSupportFromArgs(arguments);
    }

    void InternalSettings::loadReporterFromArgs(const ArgumentParser& arguments) {
        loadValidSetStringFromArgs(_reporter, arguments, validReporters, "--cbsw-unit-reporter");
    }

    void InternalSettings::loadThreadsFromArgs(const ArgumentParser& arguments) {
        ArgumentParser::Argument argument = arguments.getArgument("--cbsw-unit-threads");
        if (!argument.isValid) {
            return;
        }
        std::stringstream ss;
        ss << argument.value;
        uint32_t value;
        ss >> value;
        if (!ss) {
            std::string error = "Invalid command line option: --cbsw-unit-thread is not a number";
            throw std::runtime_error(error.c_str());
        }
        if ((value < 1) || (value > 8)) {
            std::string error = "Invalid command line option: --cbsw-unit-thread must be between 1 & 8";
            throw std::runtime_error(error.c_str());
        }
        _threads = static_cast<uint8_t>(value);
    }

    void InternalSettings::loadColorSupportFromArgs(const ArgumentParser& arguments) {
        loadValidSetStringFromArgs(_colorSupport, arguments, validColorSupport, "--cbsw-unit-color-support");
    }
}