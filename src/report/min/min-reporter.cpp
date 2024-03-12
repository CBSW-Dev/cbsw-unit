#include "pch.hpp"
#include "min-reporter.hpp"

#include "report/ireport.hpp"

namespace CBSW::Unit {
    namespace {
        void printSuccessfulCases(Output& output, const IReport& report) {
            const uint32_t successfulCases = std::distance(report.successfulCases().begin(), report.successfulCases().end());
            output << output.status().success << successfulCases << " passing" << output.status().reset << output.endl;
        }

        void printFailedCases(Output& output, const IReport& report) {
            const uint32_t failedCases = std::distance(report.failedCases().begin(), report.failedCases().end());
            output << output.status().failure << failedCases << " failing" << output.status().reset << output.endl;
        }
    }

    MinReporter::MinReporter(Output& output) noexcept:
        _output(&output)
    {}

    void MinReporter::onEnd() noexcept {
        (*_output) << _output->endl;
        printSuccessfulCases(*_output, _report);
        printFailedCases(*_output, _report);
        (*_output) << _output->endl;
    }

    void MinReporter::onCaseSuccess(const ICase& testCase) noexcept {
        _report.onSuccess(testCase);
    }

    void MinReporter::onCaseFailure(const Exception& exception) noexcept {
        _report.onFailure(exception);
    }

    void MinReporter::setOutput(Output& output) noexcept {
        _output = &output;
    }

}