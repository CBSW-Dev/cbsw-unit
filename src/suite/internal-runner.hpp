#pragma once
#include "settings/internal-settings.hpp"
#include "suite/runner.hpp"

namespace CBSW::Unit {
    class IReport;

    class InternalRunner: public Runner {
    public:
        InternalRunner();
        ~InternalRunner();

        void initialise(int argc, char** argv);

        Output& output() noexcept override;

        ISettings& settings() noexcept override;

        int run() noexcept override;
        int run(IReporter& reporter) noexcept override;
    private:
        Output* _output;
        IReporter* _reporter;
        IReport* _report;
        InternalSettings _settings;
    };
}