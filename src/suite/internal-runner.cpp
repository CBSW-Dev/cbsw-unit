#include "pch.hpp"
#include "internal-runner.hpp"
#include "suite/root-fixture.hpp"
#include "report/spec/spec-reporter.hpp"
#include "report/deferred/deferred-reporter.hpp"
#include "report/report.hpp"
#include "output/ansi-color-ostream-output.hpp"

#include "settings/argument-parser.hpp"

namespace CBSW::Unit {
    InternalRunner::InternalRunner() noexcept:
        _output(nullptr),
        _reporter(nullptr),
        _report(new Report())
    {}

    InternalRunner::~InternalRunner() noexcept {
        delete _report;
        delete _reporter;
        delete _output;
    }

    void InternalRunner::initialise(int argc, char** argv) {
        ArgumentParser argumentParser(argc, argv);
        _settings.loadFromArgs(argumentParser);

        initialiseOutput();
        initialiseReporter();
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
        cbsw_unit_root_fixture().run(reporter, *_report, _settings);
        return EXIT_SUCCESS;
    }

    void InternalRunner::initialiseReporter() noexcept {
        //default case
        _reporter = new SpecReporter(*_output);
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