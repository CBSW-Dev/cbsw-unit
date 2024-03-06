#include "pch.hpp"
#include "assert/exception.hpp"

namespace CBSW::Unit {
    ExceptionStringHolder::ExceptionStringHolder(const std::string& description):
        _description(description)
    {}


    Exception::Exception(ICase& testCase, const Description& description, Filename filename, LineNumber lineNumber) noexcept:
        ExceptionStringHolder(description),
        runtime_error(_description.c_str()),
        _testCase(testCase),
        _filename(filename),
        _lineNumber(lineNumber)
    {}

    const ICase& Exception::testCase() const noexcept {
        return _testCase;
    }

    Exception::Description Exception::description() const noexcept {
        return _description.c_str();
    }

    Exception::Filename Exception::filename() const noexcept {
        return _filename;
    }

    Exception::LineNumber Exception::lineNumber() const noexcept {
        return _lineNumber;
    }
}