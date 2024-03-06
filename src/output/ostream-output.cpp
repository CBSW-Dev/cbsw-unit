#include "pch.hpp"
#include "ostream-output.hpp"

namespace CBSW::Unit {
    OStreamOutput::OStreamOutput(std::ostream& stream) noexcept:
        _stream(stream)
    {}

    OStreamOutput& OStreamOutput::operator<< (char value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<< (const char* value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<< (const std::string& value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(short value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(unsigned short value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(int value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(unsigned int value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(long value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(unsigned long value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(long long value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(unsigned long long value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(float value) noexcept {
        _stream << value;
        return *this;
    }


    OStreamOutput& OStreamOutput::operator<<(double value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(long double value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(bool value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<<(const void* value) noexcept {
        _stream << value;
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<< (std::nullptr_t) noexcept {
        _stream << "nullptr";
        return *this;
    }

    OStreamOutput& OStreamOutput::operator<< (void (*func)(Output&) noexcept) noexcept{
        func(*this);
        return *this;
    }

    void OStreamOutput::flush() noexcept {
        _stream.flush();
    }

}