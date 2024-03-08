#pragma once

#include <cstdint>

namespace CBSW::Unit {
    class OutputIndent;
    class Output;
}

::CBSW::Unit::Output& operator <<(::CBSW::Unit::Output& output, const ::CBSW::Unit::OutputIndent& indent) noexcept;

namespace CBSW::Unit {
    class OutputIndent {
        friend ::CBSW::Unit::Output& ::operator <<(::CBSW::Unit::Output& output, const ::CBSW::Unit::OutputIndent& indent) noexcept;
    public:
        OutputIndent();
        OutputIndent& operator++() noexcept;
        OutputIndent& operator--() noexcept;
    private:
        std::uint32_t _indent;
    };
}