#pragma once

#include <cbsw-unit>

class CustomReporter: public ::CBSW::Unit::IReporter {
public:
    CustomReporter(::CBSW::Unit::Output& output);

    void onBegin() noexcept;
    void onEnd(const ::CBSW::Unit::IReport& report) noexcept;

    void onBeginFixture(const ::CBSW::Unit::IFixture& fixture) noexcept;
    void onEndFixture(const ::CBSW::Unit::IFixture& fixture) noexcept;

    void onBeginCase(const ::CBSW::Unit::ICase& testCase) noexcept;
    void onCaseSuccess(const ::CBSW::Unit::ICase& testCase) noexcept;
    void onCaseFailure(const ::CBSW::Unit::Exception& exception) noexcept;
    void onEndCase(const ::CBSW::Unit::ICase& testCase) noexcept;

    void onBeginBeforeEach(const ::CBSW::Unit::IBeforeEach& beforeEach) noexcept;
    void onEndBeforeEach(const ::CBSW::Unit::IBeforeEach& beforeEach) noexcept;

    void onBeginAfterEach(const ::CBSW::Unit::IAfterEach& afterEach) noexcept;
    void onEndAfterEach(const ::CBSW::Unit::IAfterEach& afterEach) noexcept;
private:
    ::CBSW::Unit::Output& _output;
    uint32_t _index;
};