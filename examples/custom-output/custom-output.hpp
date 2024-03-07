#pragma once

#include <cbsw-unit>

class CustomOutput: public ::CBSW::Unit::Output {
public:
    CustomOutput(std::ostream& stream);

    Output& operator<< (char value) noexcept override;
    Output& operator<< (const char* value) noexcept override;
    Output& operator<< (const std::string& value) noexcept override;

    Output& operator<<(short value) noexcept override;
    Output& operator<<(unsigned short value) noexcept override;

    Output& operator<<(int value) noexcept override;
    Output& operator<<(unsigned int value) noexcept override;

    Output& operator<<(long value) noexcept override;
    Output& operator<<(unsigned long value) noexcept override;

    Output& operator<<(long long value) noexcept override;
    Output& operator<<(unsigned long long value) noexcept override;

    Output& operator<<(float value) noexcept override;

    Output& operator<<(double value) noexcept override;
    Output& operator<<(long double value) noexcept override;

    Output& operator<<(bool value) noexcept override;

    Output& operator<<(const void* value) noexcept override;

    Output& operator<< (std::nullptr_t) noexcept override;

    Output& operator<< (void (*func)(Output&) noexcept) noexcept override;

    void flush() noexcept override;

    const Characters& characters() const noexcept override;
private:
    void printRainbow(char character);
private:
    std::ostream& _stream;
    uint32_t _index;
    bool _escape;
};