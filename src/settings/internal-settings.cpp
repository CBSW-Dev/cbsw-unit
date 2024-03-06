#include "pch.hpp"
#include "internal-settings.hpp"
#include "argument-parser.hpp"

#include <set>
#include <sstream>

namespace CBSW::Unit {
    namespace {
        using ValidReporters = std::set<std::string>;
        ValidReporters validReporters = {"spec"};

        std::string contineValidReportersString(ValidReporters::iterator& it, const ValidReporters::iterator& end) {
            std::stringstream output;
            output << (*it);
            ++it;
            for (;it != end; ++it) {
                output << "," << (*it);
            }
            return output.str();
        }

        std::string validReportersString() {
            std::ostringstream ss;
            std::string output;
            ValidReporters::iterator it = validReporters.begin();
            const ValidReporters::iterator end = validReporters.end();
            if (it == end) {
                return "";
            }
            return contineValidReportersString(it, end);
        }
    }
    InternalSettings::InternalSettings():
        _reporter("spec"),
        _threads(4)
    {}

    const InternalSettings::ReporterType& InternalSettings::reporter() const noexcept {
        return _reporter;
    }

    InternalSettings::ThreadsType InternalSettings::threads() const noexcept {
        return _threads;
    }

    void InternalSettings::loadFromArgs(const ArgumentParser& arguments) {
        loadReporterFromArgs(arguments);
        loadThreadsFromArgs(arguments);
    }

    void InternalSettings::loadReporterFromArgs(const ArgumentParser& arguments) {
        ArgumentParser::Argument argument = arguments.getArgument("--cbsw-unit-reporter");
        if (!argument.isValid) {
            return;
        }
        auto it = validReporters.find(argument.value);
        if (it == validReporters.end()) {
            std::string error = "Invalid command line option: --cbsw-unit-reporter must be one of [";
            error += validReportersString();
            error += "]";
            throw std::runtime_error(error.c_str());
        }
        _reporter = argument.value;
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
}