#pragma once

#include "report/ireporter.hpp"
#include "output/output.hpp"
#include "output/output-indent.hpp"
#include "deferred-reporter-action-list.hpp"

#include <list>
#include <mutex>

namespace CBSW::Unit {
    class DeferredReporterAction;

    class DeferredReporter: public IReporter {
    public:
        DeferredReporter(IReporter& deferred, std::mutex& outputMutex) noexcept;

        void onBegin() noexcept override;
        void onEnd() noexcept override;

        void onBeginFixture(const IFixture& fixture) noexcept override;
        void onEndFixture(const IFixture& fixture) noexcept override;

        void onBeginCase(const ICase& testCase) noexcept override;
        void onCaseSuccess(const ICase& testCase) noexcept override;
        void onCaseFailure(const Exception& exception) noexcept override;
        void onEndCase(const ICase& testCase) noexcept override;

        void onBeginBeforeEach(const IBeforeEach& beforeEach) noexcept override;
        void onEndBeforeEach(const IBeforeEach& beforeEach) noexcept override;

        void onBeginAfterEach(const IAfterEach& afterEach) noexcept override;
        void onEndAfterEach(const IAfterEach& afterEach) noexcept override;

        void setOutput(Output& output) noexcept override;
    public:
        void resolveActions() noexcept;
    private:
        IReporter& _deferred;
        DeferredReporterActionList _actions;
        std::mutex& _outputMutex;
    };
}