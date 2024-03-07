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

        void setReporter(IReporter& reporter) noexcept;
        void setOutput(Output& output) noexcept;
    private:
        void initialiseReporter() noexcept;
        void initialiseOutput() noexcept;
    private:
        bool _deleteOutput;
        Output* _output;
        bool _deleteReporter;
        IReporter* _reporter;
        IReport* _report;
        InternalSettings _settings;
    };
}