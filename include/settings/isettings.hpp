#pragma once

#include <string>
#include <cstdint>

namespace CBSW::Unit {
    class ISettings {
    public:
        virtual ~ISettings() = default;

        using ReporterType = std::string;
        using ThreadsType = std::uint8_t;

        virtual const ReporterType& reporter() const noexcept = 0;
        virtual ThreadsType threads() const noexcept = 0;
    };
}