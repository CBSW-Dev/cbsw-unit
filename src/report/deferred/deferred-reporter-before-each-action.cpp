#include "pch.hpp"
#include "deferred-reporter-before-each-action.hpp"

namespace CBSW::Unit {
    DeferredReporterBeforeEachAction::DeferredReporterBeforeEachAction(void (IReporter::*function)(const IBeforeEach&) noexcept, const IBeforeEach& beforeEach):
        _function(function),
        _beforeEach(beforeEach)
    {}

    void DeferredReporterBeforeEachAction::run(IReporter& reporter) noexcept {
        (reporter.*_function)(_beforeEach);
    }

    DeferredReporterAction* DeferredReporterBeforeEachAction::clone() const noexcept {
        return new DeferredReporterBeforeEachAction(_function, _beforeEach);
    }
}