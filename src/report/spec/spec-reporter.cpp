#include "pch.hpp"
#include "spec-reporter.hpp"
#include "suite/ifixture.hpp"
#include "suite/icase.hpp"
#include "assert/exception.hpp"
#include "utility/unused.hpp"
#include "report/ireport.hpp"

namespace CBSW::Unit {
    namespace {
        void printSuccessReport(Output& output, uint32_t successfulCases, uint32_t totalCases) {
            output << output.status().success << successfulCases << " of " << totalCases << " tests succesful" << output.status().reset << output.endl;
        }

        void printFailedReport(Output& output, const IReport& report, uint32_t failedCases, uint32_t totalCases) {
            output << output.status().failure << output.characters().cross << " " << failedCases << " of " << totalCases << " tests failed" << output.status().reset << Output::endl;
            output << Output::endl;

            for (auto failure: report.failedCases()) {
                output << output.status().info << failure.number << ") " << failure.testCase->description() << ": ";
                output << output.status().failure << failure.exception.description() << "\r\n";
                output << output.status().trace << "  @ " << failure.exception.filename() << ":" << failure.exception.lineNumber()<< output.status().reset << Output::endl;
            }
        }

        void printOutputReport(Output& output, const IReport& report) {
            const IReport::FailedCases& failedCases = report.failedCases();
            const IReport::SuccessfulCases& successfulCases = report.successfulCases();

            uint32_t failedCasesCount = std::distance(failedCases.begin(), failedCases.end());
            uint32_t successfulCasesCount = std::distance(successfulCases.begin(), successfulCases.end());

            if (failedCasesCount == 0) {
                printSuccessReport(output, successfulCasesCount, successfulCasesCount + failedCasesCount);
            } else {
                printFailedReport(output, report, failedCasesCount, successfulCasesCount + failedCasesCount);
            }
        }
    }
    SpecReporter::SpecReporter(Output& output) noexcept:
        _output(&output)
    {}

    void SpecReporter::onBegin() noexcept {
        (*_output) << _output->endl;
    }

    void SpecReporter::onEnd(const IReport& report) noexcept {
        printOutputReport(*_output, report);
        (*_output) << _output->endl;
    }

    void SpecReporter::onBeginFixture(const IFixture& fixture) noexcept {
        (*_output) << _output->status().info << _indent << fixture.description() << _output->status().reset << _output->endl;
        ++_indent;
    }

    void SpecReporter::onEndFixture(const IFixture& fixture) noexcept {
        unused(fixture);
        --_indent;
    }

    void SpecReporter::onBeginCase(const ICase& testCase) noexcept {
        unused(testCase);
    }

    void SpecReporter::onCaseSuccess(const ICase& testCase) noexcept {
        (*_output) << _output->status().success << _indent << _output->characters().tick << ' ' << testCase.description() << _output->status().reset << _output->endl;
    }

    void SpecReporter::onCaseFailure(uint32_t failureNumber, const Exception& exception) noexcept {
        (*_output) << _output->status().failure << _indent << failureNumber << ") " << exception.testCase().description() << _output->status().reset << _output->endl;
    }

    void SpecReporter::onEndCase(const ICase& testCase) noexcept {
        unused(testCase);
    }

    void SpecReporter::setOutput(Output& output) noexcept {
        _output = &output;
    }
}