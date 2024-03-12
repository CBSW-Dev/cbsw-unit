#pragma once

#include "deferred-reporter-action.hpp"

namespace CBSW::Unit {
    class DeferredReporterCaseFailureAction: public DeferredReporterAction {
    public:
        DeferredReporterCaseFailureAction(void (IReporter::*function)(uint32_t, const Exception&) noexcept, uint32_t failureNumber, const Exception& exception);

        void run(IReporter& reporter) noexcept override;

        DeferredReporterAction* clone() const noexcept override;
    private:
        void (IReporter::*_function)(uint32_t, const Exception&) noexcept;
        uint32_t _failureNumber;
        const Exception& _exception;
    };
}