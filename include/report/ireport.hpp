#pragma once

#include "assert/exception.hpp"
#include <list>

namespace CBSW::Unit {
    class ICase;

    class IReport {
    public:
        virtual ~IReport() = default;

        //returns the failure number
        virtual uint32_t onFailure(const ICase& testCase, const Exception& failure) noexcept = 0;
        virtual void onSuccess(const ICase& testCase) noexcept = 0;
        virtual void onSkip(const ICase& testCase) noexcept = 0;

        struct FailedCase {
            uint32_t number;
            const ICase* testCase;
            Exception exception;
        };

        struct SuccessfulCase {
            const ICase* testCase;
        };

        struct SkippedCase {
            const ICase* testCase;
        };

        using FailedCases = std::list<FailedCase>;
        using SuccessfulCases = std::list<SuccessfulCase>;
        using SkippedCases = std::list<SkippedCase>;

        virtual const FailedCases& failedCases() const = 0;
        virtual const SuccessfulCases& successfulCases() const = 0;
        virtual const SkippedCases& skippedCases() const = 0;
    };
}