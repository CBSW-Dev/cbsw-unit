#pragma once

#include "report/ireport.hpp"
#include <list>

namespace CBSW::Unit {
    class Report: public IReport {
    public:
        void onFailure(const ICase& testCase, const Exception& failure) noexcept override;
        void onSuccess(const ICase& testCase) noexcept override;
        void onSkip(const ICase& testCase) noexcept override;

        const FailedCases& failedCases() const override;
        const SuccessfulCases& successfulCases() const override;
        const SkippedCases& skippedCases() const override;
    private:
        FailedCases _failedCases;
        SuccessfulCases _successfulCases;
        SkippedCases _skippedCases;
    };
}