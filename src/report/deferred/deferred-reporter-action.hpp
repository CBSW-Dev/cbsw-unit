#pragma once

#include "report/ireporter.hpp"
#include "output/output.hpp"

namespace CBSW::Unit {
    class DeferredReporterAction {
    public:
        virtual ~DeferredReporterAction() = default;

        virtual void run(IReporter& deferred) noexcept = 0;

        virtual DeferredReporterAction* clone() const = 0;
    };
}