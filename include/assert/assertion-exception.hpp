#pragma once

#include "exception.hpp"

namespace CBSW::Unit {
    class AssertionException: public Exception {
    public:
        AssertionException(ICase& testCase, Description description, Filename filename, LineNumber lineNumber) noexcept;
    };
}