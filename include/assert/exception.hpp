#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>

namespace CBSW::Unit {
    class ICase;

    class ExceptionStringHolder {
    public:
        using Description = std::string;
        ExceptionStringHolder(const Description& description);
    protected:
        Description _description;
    };

    class Exception: public ExceptionStringHolder, public std::runtime_error {
    public:
        using Filename = const char*;
        using LineNumber = std::uint32_t;

        Exception(ICase& testCase, const Description& description, Filename filename, LineNumber lineNumber) noexcept;

        const ICase& testCase() const noexcept;
        Description description() const noexcept;
        Filename filename() const noexcept;
        LineNumber lineNumber() const noexcept;
    private:
        ICase& _testCase;
        Filename _filename;
        LineNumber _lineNumber;
    };
}