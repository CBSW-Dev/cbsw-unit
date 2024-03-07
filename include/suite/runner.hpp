#pragma once

namespace CBSW::Unit {
    class Output;
    class ISettings;
    class IReporter;

    class Runner {
    public:
        virtual Output& output() noexcept = 0;

        virtual ISettings& settings() noexcept = 0;

        virtual int run() noexcept = 0;
        virtual int run(IReporter& reporter) noexcept = 0;

        virtual void setReporter(IReporter& reporter) noexcept = 0;
        virtual void setOutput(Output& output) noexcept = 0;
    };
}

extern int cbsw_unit_main(::CBSW::Unit::Runner& runner);