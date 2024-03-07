#include "custom-reporter.hpp"

CustomReporter::CustomReporter(::CBSW::Unit::Output& output):
    _output(output),
    _index(0)
{}

void CustomReporter::onBegin() noexcept {
    _output << _output.levels().error << (++_index) << ") onBegin" << _output.status().reset << _output.endl;
}

void CustomReporter::onEnd(const ::CBSW::Unit::IReport& report) noexcept {
    _output << _output.levels().error << (++_index) << ") onEnd" << _output.status().reset << _output.endl;
}

void CustomReporter::onBeginFixture(const ::CBSW::Unit::IFixture& fixture) noexcept {
    _output << _output.levels().warning << (++_index) << ") onBeginFixture\r\n    " << fixture.description() << _output.status().reset << _output.endl;
}

void CustomReporter::onEndFixture(const ::CBSW::Unit::IFixture& fixture) noexcept {
    _output << _output.levels().warning<< (++_index) << ") onEndFixture\r\n    " << fixture.description() << _output.status().reset << _output.endl;
}

void CustomReporter::onBeginCase(const ::CBSW::Unit::ICase& testCase) noexcept {
    _output << _output.levels().info << (++_index) << ") onBeginCase\r\n    " << testCase.description() << _output.status().reset << _output.endl;
}

void CustomReporter::onCaseSuccess(const ::CBSW::Unit::ICase& testCase) noexcept {
    _output << _output.levels().info << (++_index) << ") onCaseSuccess\r\n    " << testCase.description() << _output.status().reset << _output.endl;
}

void CustomReporter::onCaseFailure(const ::CBSW::Unit::Exception& exception) noexcept {
    _output << _output.levels().info << (++_index) << ") onCaseFailure\r\n    " << exception.testCase().description() << _output.status().reset << _output.endl;
}

void CustomReporter::onEndCase(const ::CBSW::Unit::ICase& testCase) noexcept {
    _output << _output.levels().info << (++_index) << ") onEndCase\r\n    " << testCase.description() << _output.status().reset << _output.endl;
}

void CustomReporter::onBeginBeforeEach(const ::CBSW::Unit::IBeforeEach& beforeEach) noexcept {
    _output << _output.levels().trace << (++_index) << ") onBeginBeforeEach" << _output.status().reset << _output.endl;;
}

void CustomReporter::onEndBeforeEach(const ::CBSW::Unit::IBeforeEach& beforeEach) noexcept {
    _output << _output.levels().trace << (++_index) << ") onEndBeforeEach" << _output.status().reset << _output.endl;;
}

void CustomReporter::onBeginAfterEach(const ::CBSW::Unit::IAfterEach& afterEach) noexcept {
    _output << _output.levels().trace << (++_index) << ") onBeginAfterEach" << _output.status().reset << _output.endl;;
}

void CustomReporter::onEndAfterEach(const ::CBSW::Unit::IAfterEach& afterEach) noexcept {
    _output << _output.levels().trace << (++_index) << ") onEndAfterEach" << _output.status().reset << _output.endl;;
}

void CustomReporter::setOutput(::CBSW::Unit::Output& output) noexcept {
    _output = output;
}