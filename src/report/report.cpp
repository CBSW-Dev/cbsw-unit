#include "pch.hpp"
#include "report.hpp"

namespace CBSW::Unit {
    void Report::onFailure(const ICase& testCase, const Exception& failure) noexcept {
        _failedCases.push_back(FailedCase{&testCase, failure});
    }

    void Report::onSuccess(const ICase& testCase) noexcept {
        _successfulCases.push_back(SuccessfulCase{&testCase});
    }

    void Report::onSkip(const ICase& testCase) noexcept {
        _skippedCases.push_back(SkippedCase{&testCase});
    }

    const Report::FailedCases& Report::failedCases() const {
        return _failedCases;
    }

    const Report::SuccessfulCases& Report::successfulCases() const {
        return _successfulCases;
    }
    const Report::SkippedCases& Report::skippedCases() const {
        return _skippedCases;
    }
}