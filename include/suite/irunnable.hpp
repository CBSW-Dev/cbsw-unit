#pragma once

namespace CBSW::Unit {
    class IReporter;

    class IRunnable {
    public:
        virtual ~IRunnable() = default;

        virtual void run(IReporter& reporter) noexcept = 0;
    };
}