#include "pch.hpp"
#include "assert/assertion-exception.hpp"

namespace CBSW::Unit {
    AssertionException::AssertionException(ICase& testCase, Description description, Filename filename, LineNumber lineNumber) noexcept:
        Exception(testCase, description, filename, lineNumber) {}
}