#pragma once

#include <cbsw-unit>

class CustomReporter: public ::CBSW::Unit::IReporter {
public:
    CustomReporter(::CBSW::Unit::Output& output);

    void onBegin() noexcept override;
    void onEnd() noexcept override;

    void onBeginFixture(const ::CBSW::Unit::IFixture& fixture) noexcept override;
    void onEndFixture(const ::CBSW::Unit::IFixture& fixture) noexcept override;

    void onBeginCase(const ::CBSW::Unit::ICase& testCase) noexcept override;
    void onCaseSuccess(const ::CBSW::Unit::ICase& testCase) noexcept override;
    void onCaseFailure(const ::CBSW::Unit::Exception& exception) noexcept override;
    void onEndCase(const ::CBSW::Unit::ICase& testCase) noexcept override;

    void onBeginBeforeEach(const ::CBSW::Unit::IBeforeEach& beforeEach) noexcept override;
    void onEndBeforeEach(const ::CBSW::Unit::IBeforeEach& beforeEach) noexcept override;

    void onBeginAfterEach(const ::CBSW::Unit::IAfterEach& afterEach) noexcept override;
    void onEndAfterEach(const ::CBSW::Unit::IAfterEach& afterEach) noexcept override;

    void setOutput(::CBSW::Unit::Output& output) noexcept override;
private:
    ::CBSW::Unit::Output& _output;
    uint32_t _index;
};