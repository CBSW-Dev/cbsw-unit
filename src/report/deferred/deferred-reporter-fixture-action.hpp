#pragma once

#include "deferred-reporter-action.hpp"

namespace CBSW::Unit {
    class DeferredReporterFixtureAction: public DeferredReporterAction {
    public:
        DeferredReporterFixtureAction(void (IReporter::*function)(const IFixture&) noexcept, const IFixture& fixture);

        void run(IReporter& reporter) noexcept override;

        DeferredReporterAction* clone() const noexcept override;
    private:
        void (IReporter::*_function)(const IFixture&) noexcept;
        const IFixture& _fixture;
    };
}