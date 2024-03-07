#pragma once

#include <cstdint>

namespace CBSW::Unit {
    class Version {
        static std::uint16_t major() noexcept;
        static std::uint16_t minor() noexcept;
        static std::uint16_t revision() noexcept;
    };
}