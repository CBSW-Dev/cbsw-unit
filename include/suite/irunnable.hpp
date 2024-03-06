#pragma once

namespace CBSW::Unit {
    class IReporter;
    class IReport;

    class IRunnable {
    public:
        virtual ~IRunnable() = default;

        virtual void run(IReporter& reporter, IReport& report) noexcept = 0;
    };
}