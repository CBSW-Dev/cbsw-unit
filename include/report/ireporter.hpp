#pragma once

#include <cstdint>
#include <string>

namespace CBSW::Unit {
    class IReport;
    class IFixture;
    class ICase;
    class IBeforeEach;
    class IAfterEach;
    class Exception;
    class Output;

    class IReporter {
    public:
        virtual ~IReporter() = default;

        virtual void onBegin() noexcept;
        virtual void onEnd(const IReport& report) noexcept;

        virtual void onBeginFixture(const IFixture& fixture) noexcept;
        virtual void onEndFixture(const IFixture& fixture) noexcept;

        virtual void onBeginCase(const ICase& testCase) noexcept;
        virtual void onCaseSuccess(const ICase& testCase) noexcept;
        virtual void onCaseFailure(uint32_t failureNumber, const Exception& exception) noexcept;
        virtual void onEndCase(const ICase& testCase) noexcept;

        virtual void onBeginBeforeEach(const IBeforeEach& beforeEach) noexcept;
        virtual void onEndBeforeEach(const IBeforeEach& beforeEach) noexcept;

        virtual void onBeginAfterEach(const IAfterEach& afterEach) noexcept;
        virtual void onEndAfterEach(const IAfterEach& afterEach) noexcept;

        virtual void setOutput(Output& output) noexcept = 0;
    };
}