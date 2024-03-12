#include "pch.hpp"
#include "dot-reporter.hpp"

#include "suite/ifixture.hpp"
#include "suite/icase.hpp"
#include "utility/unused.hpp"
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

    DotReporter::DotReporter(Output& output) noexcept:
        _output(&output)
    {}

    void DotReporter::onBegin() noexcept {
        (*_output) << _output->endl;
    }

    void DotReporter::onEnd() noexcept {
        (*_output) << _output->endl << _output->endl;
        printSuccessfulCases(*_output, _report);
        printFailedCases(*_output, _report);
        (*_output) << _output->endl;
    }

    void DotReporter::onCaseSuccess(const ICase& testCase) noexcept {
        unused(testCase);
        (*_output) << _output->status().success << ".";
        _report.onSuccess(testCase);
    }

    void DotReporter::onCaseFailure(const Exception& exception) noexcept {
        (*_output) << _output->status().failure << "!";
        _report.onFailure(exception);
    }

    void DotReporter::setOutput(Output& output) noexcept {
        _output = &output;
    }

}