#pragma once
#include "settings/internal-settings.hpp"
#include "suite/runner.hpp"

namespace CBSW::Unit {
    class IReport;

    class InternalRunner: public Runner {
    public:
        InternalRunner() noexcept;
        ~InternalRunner() noexcept;

        void initialise(int argc, char** argv);

        Output& output() noexcept override;

        ISettings& settings() noexcept override;

        int run() noexcept override;
        int run(IReporter& reporter) noexcept override;
    private:
        void initialiseReporter() noexcept;
        void initialiseOutput() noexcept;
    private:
        Output* _output;
        IReporter* _reporter;
        IReport* _report;
        InternalSettings _settings;
    };
}