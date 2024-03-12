#pragma once

#include "report/ireporter.hpp"
#include "output/output.hpp"
#include "output/output-indent.hpp"
#include "report/report.hpp"

namespace CBSW::Unit {
    class SpecReporter: public IReporter {
    public:
        SpecReporter(Output& output) noexcept;

        void onBegin() noexcept override;
        void onEnd() noexcept override;

        void onBeginFixture(const IFixture& fixture) noexcept override;
        void onEndFixture(const IFixture& fixture) noexcept override;

        void onBeginCase(const ICase& testCase) noexcept override;
        void onCaseSuccess(const ICase& testCase) noexcept override;
        void onCaseFailure(const Exception& exception) noexcept override;
        void onEndCase(const ICase& testCase) noexcept override;

        void setOutput(Output& output) noexcept override;
    private:
        Output* _output;
        OutputIndent _indent;

        Report _report;
        uint32_t _failureNumber;
    };
}