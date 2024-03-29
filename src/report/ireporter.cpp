#include "pch.hpp"
#include "report/ireporter.hpp"
#include "utility/unused.hpp"

namespace CBSW::Unit {
    void IReporter::onBegin() noexcept {}

    void IReporter::onEnd() noexcept {}

    void IReporter::onBeginFixture(const IFixture& fixture) noexcept {
        unused(fixture);
    }

    void IReporter::onEndFixture(const IFixture& fixture) noexcept {
        unused(fixture);
    }

    void IReporter::onBeginCase(const ICase& testCase) noexcept {
        unused(testCase);
    }

    void IReporter::onCaseSuccess(const ICase& testCase) noexcept {
        unused(testCase);
    }

    void IReporter::onCaseFailure(const Exception& exception) noexcept {
        unused(exception);
    }

    void IReporter::onEndCase(const ICase& testCase) noexcept {
        unused(testCase);
    }

    void IReporter::onBeginBeforeEach(const IBeforeEach& beforeEach) noexcept {
        unused(beforeEach);
    }

    void IReporter::onEndBeforeEach(const IBeforeEach& beforeEach) noexcept {
        unused(beforeEach);
    }

    void IReporter::onBeginAfterEach(const IAfterEach& afterEach) noexcept {
        unused(afterEach);
    }

    void IReporter::onEndAfterEach(const IAfterEach& afterEach) noexcept {
        unused(afterEach);
    }
}