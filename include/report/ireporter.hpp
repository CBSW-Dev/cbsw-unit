#pragma once

namespace CBSW::Unit {
    class IReport;
    class IFixture;
    class ICase;
    class Exception;

    class IReporter {
    public:
        virtual ~IReporter() = default;

        virtual void onBegin() noexcept = 0;
        virtual void onEnd(const IReport& report) noexcept = 0;

        virtual void onBeginFixture(const IFixture& fixture) noexcept = 0;
        virtual void onEndFixture(const IFixture& fixture) noexcept = 0;

        virtual void onBeginCase(const ICase& testCase) noexcept = 0;
        virtual void onCaseSuccess(const ICase& testCase) noexcept = 0;
        virtual void onCaseFailure(const Exception& exception) noexcept = 0;
        virtual void onEndCase(const ICase& testCase) noexcept = 0;
    };
}