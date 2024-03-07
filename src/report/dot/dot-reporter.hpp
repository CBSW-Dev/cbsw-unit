#pragma once

#include "report/ireporter.hpp"
#include "output/output.hpp"

namespace CBSW::Unit {
    class DotReporter: public IReporter {
    public:
        DotReporter(Output& output) noexcept;

        void onBegin() noexcept override;
        void onEnd(const IReport& report) noexcept override;

        void onCaseSuccess(const ICase& testCase) noexcept override;
        void onCaseFailure( const Exception& exception) noexcept override;

        void setOutput(Output& output) noexcept override;
    private:
        Output* _output;
    };
}