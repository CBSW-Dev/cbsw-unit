#include "pch.hpp"
#include "deferred-reporter.hpp"
#include "deferred-reporter-fixture-action.hpp"
#include "deferred-reporter-case-action.hpp"
#include "deferred-reporter-case-failure-action.hpp"
#include "deferred-reporter-before-each-action.hpp"
#include "deferred-reporter-after-each-action.hpp"

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
        _actions.push_back(new DeferredReporterFixtureAction(&IReporter::onBeginFixture, fixture));
    }

    void DeferredReporter::onEndFixture(const IFixture& fixture) noexcept {
        _actions.push_back(new DeferredReporterFixtureAction(&IReporter::onEndFixture, fixture));
    }

    void DeferredReporter::onBeginCase(const ICase& testCase) noexcept {
        _actions.push_back(new DeferredReporterCaseAction(&IReporter::onBeginCase, testCase));
    }

    void DeferredReporter::onCaseSuccess(const ICase& testCase) noexcept {
        _actions.push_back(new DeferredReporterCaseAction(&IReporter::onCaseSuccess, testCase));
    }

    void DeferredReporter::onCaseFailure(uint32_t failureNumber, const Exception& exception) noexcept {
        _actions.push_back(new DeferredReporterCaseFailureAction(&IReporter::onCaseFailure, failureNumber, exception));
    }

    void DeferredReporter::onEndCase(const ICase& testCase) noexcept {
        _actions.push_back(new DeferredReporterCaseAction(&IReporter::onEndCase, testCase));
    }

    void DeferredReporter::onBeginBeforeEach(const IBeforeEach& beforeEach) noexcept {
        _actions.push_back(new DeferredReporterBeforeEachAction(&IReporter::onBeginBeforeEach, beforeEach));
    }

    void DeferredReporter::onEndBeforeEach(const IBeforeEach& beforeEach) noexcept {
        _actions.push_back(new DeferredReporterBeforeEachAction(&IReporter::onEndBeforeEach, beforeEach));
    }

    void DeferredReporter::onBeginAfterEach(const IAfterEach& afterEach) noexcept {
        _actions.push_back(new DeferredReporterAfterEachAction(&IReporter::onBeginAfterEach, afterEach));
    }

    void DeferredReporter::onEndAfterEach(const IAfterEach& afterEach) noexcept {
        _actions.push_back(new DeferredReporterAfterEachAction(&IReporter::onEndAfterEach, afterEach));
    }

    void DeferredReporter::setOutput(Output& output) noexcept {
        _deferred.setOutput(output);
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