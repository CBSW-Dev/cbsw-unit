#include "pch.hpp"
#include "deferred-reporter-case-action.hpp"

namespace CBSW::Unit {
    DeferredReporterCaseAction::DeferredReporterCaseAction(void (IReporter::*function)(const ICase&) noexcept, const ICase& testCase):
        _function(function),
        _testCase(testCase)
    {}

    void DeferredReporterCaseAction::run(IReporter& reporter) noexcept {
        (reporter.*_function)(_testCase);
    }

    DeferredReporterAction* DeferredReporterCaseAction::clone() const noexcept {
        return new DeferredReporterCaseAction(_function, _testCase);
    }
}