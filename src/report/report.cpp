#include "pch.hpp"
#include "report.hpp"

#include "utility/unused.hpp"

namespace CBSW::Unit {
    Report::Report():
        _failureNumber(0)
    {}

    uint32_t Report::onFailure(const ICase& testCase, const Exception& failure) noexcept {
        std::lock_guard<std::mutex> lock(_accessMutex);

        _failedCases.push_back(FailedCase{++_failureNumber, &testCase, failure});
        return _failureNumber;
    }

    void Report::onSuccess(const ICase& testCase) noexcept {
        std::lock_guard<std::mutex> lock(_accessMutex);
        _successfulCases.push_back(SuccessfulCase{&testCase});
    }

    void Report::onSkip(const ICase& testCase) noexcept {
        std::lock_guard<std::mutex> lock(_accessMutex);
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