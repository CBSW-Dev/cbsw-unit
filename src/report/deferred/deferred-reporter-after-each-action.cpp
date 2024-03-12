#include "pch.hpp"
#include "deferred-reporter-after-each-action.hpp"

namespace CBSW::Unit {
    DeferredReporterAfterEachAction::DeferredReporterAfterEachAction(void (IReporter::*function)(const IAfterEach&) noexcept, const IAfterEach& afterEach):
        _function(function),
        _afterEach(afterEach)
    {}

    void DeferredReporterAfterEachAction::run(IReporter& reporter) noexcept {
        (reporter.*_function)(_afterEach);
    }

    DeferredReporterAction* DeferredReporterAfterEachAction::clone() const noexcept {
        return new DeferredReporterAfterEachAction(_function, _afterEach);
    }
}