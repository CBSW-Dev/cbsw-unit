#include "pch.hpp"
#include "deferred-reporter.hpp"
#include "deferred-reporter-function-action.hpp"

namespace CBSW::Unit {
    DeferredReporter::DeferredReporter(IReporter& deferred, std::mutex& outputMutex) noexcept:
        _deferred(deferred),
        _outputMutex(outputMutex)
    {}

    void DeferredReporter::onBegin() noexcept {
        _deferred.onBegin();
    }

    void DeferredReporter::onEnd(const IReport& report) noexcept {
        _deferred.onEnd(report);
    };

    void DeferredReporter::onBeginFixture(const IFixture& fixture) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<IFixture>(fixture, &IReporter::onBeginFixture));
    }

    void DeferredReporter::onEndFixture(const IFixture& fixture) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<IFixture>(fixture, &IReporter::onEndFixture));
    }

    void DeferredReporter::onBeginCase(const ICase& testCase) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<ICase>(testCase, &IReporter::onBeginCase));
    }

    void DeferredReporter::onCaseSuccess(const ICase& testCase) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<ICase>(testCase, &IReporter::onCaseSuccess));
    }

    void DeferredReporter::onCaseFailure( const Exception& exception) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<Exception>(exception, &IReporter::onCaseFailure));
    }

    void DeferredReporter::onEndCase(const ICase& testCase) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<ICase>(testCase, &IReporter::onEndCase));
    }

    void DeferredReporter::onBeginBeforeEach(const IBeforeEach& beforeEach) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<IBeforeEach>(beforeEach, &IReporter::onBeginBeforeEach));
    }

    void DeferredReporter::onEndBeforeEach(const IBeforeEach& beforeEach) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<IBeforeEach>(beforeEach, &IReporter::onEndBeforeEach));
    }

    void DeferredReporter::onBeginAfterEach(const IAfterEach& afterEach) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<IAfterEach>(afterEach, &IReporter::onBeginAfterEach));
    }

    void DeferredReporter::onEndAfterEach(const IAfterEach& afterEach) noexcept {
        _actions.push_back(new DeferredReporterFunctionAction<IAfterEach>(afterEach, &IReporter::onEndAfterEach));
    }


    void DeferredReporter::resolveActions() noexcept {
        {
            std::lock_guard<std::mutex> lock(_outputMutex);
            for (DeferredReporterAction* action: _actions) {
                action->run(_deferred);
            }
        }
        _actions.clear();
    }
}