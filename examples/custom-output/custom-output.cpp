#include "custom-output.hpp"

#include <iostream>
#include <sstream>

namespace {
    const char* rainbow[7] = {
        "\x1B[38;5;196m",
        "\x1B[38;5;202m",
        "\x1B[38;5;226m",
        "\x1B[38;5;76m",
        "\x1B[38;5;27m",
        "\x1B[38;5;27m",
        "\x1B[38;5;93m"
    };
}

CustomOutput::CustomOutput(std::ostream& stream):
    _stream(stream),
    _index(0)
{}

void CustomOutput::printRainbow(char character) {
    if (!isspace(character)) {
        _stream << rainbow[_index];
        _index = (_index + 1) % 7;
    }
    _stream << character;
}

::CBSW::Unit::Output& CustomOutput::operator<< (char value) noexcept {
    printRainbow(value);
    return *this;
}

::CBSW::Unit::Output& CustomOutput::operator<< (const char* value) noexcept {
    return this->operator<<(std::string(value));
}

::CBSW::Unit::Output& CustomOutput::operator<< (const std::string& value) noexcept {
    for (auto character: value) {
        printRainbow(character);
    }
    return *this;
}

::CBSW::Unit::Output& CustomOutput::operator<<(short value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}

::CBSW::Unit::Output& CustomOutput::operator<<(unsigned short value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}

::CBSW::Unit::Output& CustomOutput::operator<<(int value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}

::CBSW::Unit::Output& CustomOutput::operator<<(unsigned int value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}


::CBSW::Unit::Output& CustomOutput::operator<<(long value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}

::CBSW::Unit::Output& CustomOutput::operator<<(unsigned long value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}


::CBSW::Unit::Output& CustomOutput::operator<<(long long value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}

::CBSW::Unit::Output& CustomOutput::operator<<(unsigned long long value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}


::CBSW::Unit::Output& CustomOutput::operator<<(float value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}


::CBSW::Unit::Output& CustomOutput::operator<<(double value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}

::CBSW::Unit::Output& CustomOutput::operator<<(long double value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}


::CBSW::Unit::Output& CustomOutput::operator<<(bool value) noexcept {
    return this->operator<<(value ? "true" : "false");
}


::CBSW::Unit::Output& CustomOutput::operator<<(const void* value) noexcept {
    std::stringstream ss;
    ss << value;
    return this->operator<<(ss.str());
}


::CBSW::Unit::Output& CustomOutput::operator<< (std::nullptr_t) noexcept {
    return this->operator<<("nullptr");
}

::CBSW::Unit::Output& CustomOutput::operator<< (void (*func)(::CBSW::Unit::Output&) noexcept) noexcept {
    func(*this);
    return *this;
}

void CustomOutput::flush() noexcept {
    _stream.flush();
}