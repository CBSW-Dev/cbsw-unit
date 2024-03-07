#pragma once

#include "report/ireporter.hpp"
#include "output/output.hpp"

namespace CBSW::Unit {
    class MinReporter: public IReporter {
    public:
        MinReporter(Output& output) noexcept;

        void onEnd(const IReport& report) noexcept override;

        void setOutput(Output& output) noexcept override;
    private:
        Output* _output;
    };
}