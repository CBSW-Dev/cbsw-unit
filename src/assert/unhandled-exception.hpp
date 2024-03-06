#pragma once
#include "assert/exception.hpp"


namespace CBSW::Unit {
    class UnhandledException: public Exception {
    public:
        UnhandledException(ICase& testCase) noexcept;
    };
}