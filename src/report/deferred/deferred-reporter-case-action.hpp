#pragma once

#include "deferred-reporter-action.hpp"

namespace CBSW::Unit {
    class DeferredReporterCaseAction: public DeferredReporterAction {
    public:
        DeferredReporterCaseAction(void (IReporter::*function)(const ICase&) noexcept, const ICase& testCase);

        void run(IReporter& reporter) noexcept override;

        DeferredReporterAction* clone() const noexcept override;
    private:
        void (IReporter::*_function)(const ICase&) noexcept;
        const ICase& _testCase;
    };
}