#pragma once

#include "output/output.hpp"

#include <iostream>

namespace CBSW::Unit {
    class OStreamOutput: public Output {
    public:
        OStreamOutput(std::ostream& stream) noexcept;
        OStreamOutput& operator<< (char value) noexcept override;
        OStreamOutput& operator<< (const char* value) noexcept override;
        OStreamOutput& operator<< (const std::string& value) noexcept override;

        OStreamOutput& operator<<(short value) noexcept override;
        OStreamOutput& operator<<(unsigned short value) noexcept override;

        OStreamOutput& operator<<(int value) noexcept override;
        OStreamOutput& operator<<(unsigned int value) noexcept override;

        OStreamOutput& operator<<(long value) noexcept override;
        OStreamOutput& operator<<(unsigned long value) noexcept override;

        OStreamOutput& operator<<(long long value) noexcept override;
        OStreamOutput& operator<<(unsigned long long value) noexcept override;

        OStreamOutput& operator<<(float value) noexcept override;

        OStreamOutput& operator<<(double value) noexcept override;
        OStreamOutput& operator<<(long double value) noexcept override;

        OStreamOutput& operator<<(bool value) noexcept override;

        OStreamOutput& operator<<(const void* value) noexcept override;

        OStreamOutput& operator<< (std::nullptr_t) noexcept override;

        OStreamOutput& operator<< (void (*func)(Output&) noexcept) noexcept override;

        void flush() noexcept override;
    private:
        std::ostream& _stream;
    };
}