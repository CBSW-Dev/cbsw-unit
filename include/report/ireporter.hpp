#pragma once

#include <cstdint>
#include <string>

namespace CBSW::Unit {
    class IReport;
    class IFixture;
    class ICase;
    class IBeforeEach;
    class Exception;

    class IReporter {
    public:
        virtual ~IReporter() = default;

        virtual void onBegin() noexcept;
        virtual void onEnd(const IReport& report) noexcept;

        virtual void onBeginFixture(const IFixture& fixture) noexcept;
        virtual void onEndFixture(const IFixture& fixture) noexcept;

        virtual void onBeginCase(const ICase& testCase) noexcept;
        virtual void onCaseSuccess(const ICase& testCase) noexcept;
        virtual void onCaseFailure(const Exception& exception) noexcept;
        virtual void onEndCase(const ICase& testCase) noexcept;

        virtual void onBeginBeforeEach(const IBeforeEach& beforeEach) noexcept;
        virtual void onEndBeforeEach(const IBeforeEach& beforeEach) noexcept;

        virtual void onCriticalError(const std::string& message, const char* filename, std::uint32_t lineNumber);

    };
}