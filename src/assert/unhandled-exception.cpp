#include "pch.hpp"
#include "unhandled-exception.hpp"

namespace CBSW::Unit {
    UnhandledException::UnhandledException(ICase& testCase) noexcept:
        Exception(testCase, "Unhandled Exception", "", 0)
    {}
}