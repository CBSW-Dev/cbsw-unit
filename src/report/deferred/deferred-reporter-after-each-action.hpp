#pragma once

#include "deferred-reporter-action.hpp"

namespace CBSW::Unit {
    class DeferredReporterAfterEachAction: public DeferredReporterAction {
    public:
        DeferredReporterAfterEachAction(void (IReporter::*function)(const IAfterEach&) noexcept, const IAfterEach& afterEach);

        void run(IReporter& reporter) noexcept override;

        DeferredReporterAction* clone() const noexcept override;
    private:
        void (IReporter::*_function)(const IAfterEach&) noexcept;
        const IAfterEach& _afterEach;
    };
}