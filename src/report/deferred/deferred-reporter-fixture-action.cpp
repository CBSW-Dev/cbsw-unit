#include "pch.hpp"
#include "deferred-reporter-fixture-action.hpp"

namespace CBSW::Unit {
    DeferredReporterFixtureAction::DeferredReporterFixtureAction(void (IReporter::*function)(const IFixture&) noexcept, const IFixture& fixture):
        _function(function),
        _fixture(fixture)
    {}

    void DeferredReporterFixtureAction::run(IReporter& reporter) noexcept {
        (reporter.*_function)(_fixture);
    }

    DeferredReporterAction* DeferredReporterFixtureAction::clone() const noexcept {
        return new DeferredReporterFixtureAction(_function, _fixture);
    }
}