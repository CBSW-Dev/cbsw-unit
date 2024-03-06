#include "pch.hpp"
#include "internal-runner.hpp"
#include "suite/root-fixture.hpp"
#include "report/spec/spec-reporter.hpp"
#include "report/deferred/deferred-reporter.hpp"
#include "report/report.hpp"
#include "output/color-support-ostream-output.hpp"

namespace CBSW::Unit {
    InternalRunner::InternalRunner():
        _output(new ColorSupportOStreamOutput(std::cout)),
        _reporter(new SpecReporter(*_output)),
        _report(new Report())
    {}

    InternalRunner::~InternalRunner() {
        delete _report;
        delete _reporter;
        delete _output;
    }

    void InternalRunner::initialise(int argc, char** argv) noexcept {
        (void)argc;
        (void)argv;
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
}