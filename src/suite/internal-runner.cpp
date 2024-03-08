#include "pch.hpp"
#include "internal-runner.hpp"
#include "suite/root-fixture.hpp"
#include "report/spec/spec-reporter.hpp"
#include "report/dot/dot-reporter.hpp"
#include "report/min/min-reporter.hpp"
#include "report/deferred/deferred-reporter.hpp"
#include "report/report.hpp"
#include "output/ansi-color-ostream-output.hpp"

#include "settings/version.hpp"
#include "settings/argument-parser.hpp"

#include "settings/valid-library-arguments.hpp"
#include <vector>

namespace CBSW::Unit {
    namespace {
        void printVersion() {
            std::cout << "\r\ncbsw-unit v" << Version::major() << "." << Version::minor() << "." << Version::revision() << "\r\n" << std::endl;
        }

        void printHelp() {
            std::cout   << "\r\ncbsw-unit command line options:\r\n"
                << "    --cbsw-unit-reporter=<flag>                - specifies the reporter, <flag> can be one of [spec, min, dot]\r\n"
                << "    --cbsw-unit-color-support=<flag>           - specifies the color support, <flag> can be one of [none, ansi]\r\n"
                << "    --cbsw-unit-threads=<number>               - specifies the number of threads to use when running fixtures\r\n"
                << "    --cbsw-unit-version                        - print the unit test library version and exit\r\n"
                << "    --cbsw-unit-help                           - print this message and exit\r\n"
                << std::endl;
        }
    }

    InternalRunner::InternalRunner() noexcept:
        _deleteOutput(true),
        _output(nullptr),
        _deleteReporter(true),
        _reporter(nullptr),
        _report(new Report())
    {}

    InternalRunner::~InternalRunner() noexcept {
        delete _report;
        if (_deleteReporter) {
            delete _reporter;
        }
        if (_deleteOutput) {
            delete _output;
        }
    }

    int InternalRunner::initialise(Arguments& arguments, int (*next)(Arguments&)) {
        ArgumentParser argumentParser(arguments);
        _settings.loadFromArgs(argumentParser);

        initialiseOutput();
        initialiseReporter();

        if (_settings.printHelp() == true) {
            printHelp();
            return 0;
        }
        if (_settings.printVersion() == true) {
            printVersion();
            return 0;
        }

        for (auto it = arguments.begin(), end = arguments.end(); it != end; ++it) {
            if (ValidLibraryArguments::instance().find(*it) != ValidLibraryArguments::instance().end()) {
                it = arguments.erase(it);
            }
        }

        return next(arguments);
    }

    Output& InternalRunner::output() noexcept {
        return *_output;
    }

    ISettings& InternalRunner::settings() noexcept {
        return _settings;
    }

    int InternalRunner::run() noexcept {
        run(*_reporter);
        return EXIT_SUCCESS;
    }

    int InternalRunner::run(IReporter& reporter) noexcept {
        cbsw_unit_root_fixture()->run(reporter, *_report, _settings);
        return EXIT_SUCCESS;
    }

    void InternalRunner::setReporter(IReporter& reporter) noexcept {
        if (_deleteReporter) {
            delete _reporter;
        }
        _reporter = &reporter;
        _deleteReporter = false;
    }

    void InternalRunner::setOutput(Output& output) noexcept {
        if (_deleteOutput) {
            delete _output;
        }
        _output = &output;
        _reporter->setOutput(output);
        _deleteOutput = false;
    }

    void InternalRunner::initialiseReporter() noexcept {
        if (_settings.reporter() == "dot") {
            _reporter = new DotReporter(*_output);
        } else if (_settings.reporter() == "min") {
            _reporter = new MinReporter(*_output);
        } else {
            //default case
            _reporter = new SpecReporter(*_output);
        }
    }

    void InternalRunner::initialiseOutput() noexcept {
        if (_settings.colorSupport() == "ansi") {
            _output = new AnsiColorOStreamOutput(std::cout);
        } else {
            //default
            _output = new OStreamOutput(std::cout);
        }
    }
}