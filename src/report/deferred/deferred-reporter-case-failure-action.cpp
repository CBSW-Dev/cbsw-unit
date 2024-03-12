#include "pch.hpp"
#include "deferred-reporter-case-failure-action.hpp"

namespace CBSW::Unit {
    DeferredReporterCaseFailureAction::DeferredReporterCaseFailureAction(void (IReporter::*function)(uint32_t, const Exception&) noexcept, uint32_t failureNumber, const Exception& exception):
        _function(function),
        _failureNumber(failureNumber),
        _exception(exception)
    {}

    void DeferredReporterCaseFailureAction::run(IReporter& reporter) noexcept {
        (reporter.*_function)(_failureNumber, _exception);
    }

    DeferredReporterAction* DeferredReporterCaseFailureAction::clone() const noexcept {
        return new DeferredReporterCaseFailureAction(_function, _failureNumber, _exception);
    }
}