#include "pch.hpp"
#include "output-indent.hpp"
#include "output/output.hpp"

namespace {
    static constexpr const char* space() noexcept {
        return "  ";
    }
}
::CBSW::Unit::Output& operator <<(::CBSW::Unit::Output& output, const ::CBSW::Unit::OutputIndent& indent) noexcept {
    for (std::uint32_t i = 0; i < indent._indent; ++i) {
        output << space();
    }
    return output;
}

namespace CBSW::Unit {
    OutputIndent& OutputIndent::operator++() noexcept {
        ++_indent;
        return *this;
    }

    OutputIndent& OutputIndent::operator--() noexcept {
        if (_indent != 0) {
            --_indent;
        }
        return *this;
    }
}