#pragma once

#include "deferred-reporter-action.hpp"

namespace CBSW::Unit {
    class DeferredReporterBeforeEachAction: public DeferredReporterAction {
    public:
        DeferredReporterBeforeEachAction(void (IReporter::*function)(const IBeforeEach&) noexcept, const IBeforeEach& beforeEach);

        void run(IReporter& reporter) noexcept override;

        DeferredReporterAction* clone() const noexcept override;
    private:
        void (IReporter::*_function)(const IBeforeEach&) noexcept;
        const IBeforeEach& _beforeEach;
    };
}