#pragma once

#include <string>

namespace CBSW::Unit {
    class Output {
    public:
        virtual ~Output() = default;

        virtual Output& operator<< (char value) noexcept = 0;
        virtual Output& operator<< (const char* value) noexcept = 0;
        virtual Output& operator<< (const std::string& value) noexcept = 0;

        virtual Output& operator<<(short value) noexcept = 0;
        virtual Output& operator<<(unsigned short value) noexcept = 0;

        virtual Output& operator<<(int value) noexcept = 0;
        virtual Output& operator<<(unsigned int value) noexcept = 0;

        virtual Output& operator<<(long value) noexcept = 0;
        virtual Output& operator<<(unsigned long value) noexcept = 0;

        virtual Output& operator<<(long long value) noexcept = 0;
        virtual Output& operator<<(unsigned long long value) noexcept = 0;

        virtual Output& operator<<(float value) noexcept = 0;

        virtual Output& operator<<(double value) noexcept = 0;
        virtual Output& operator<<(long double value) noexcept = 0;

        virtual Output& operator<<(bool value) noexcept = 0;

        virtual Output& operator<<(const void* value) noexcept = 0;

        virtual Output& operator<< (std::nullptr_t) noexcept = 0;

        virtual Output& operator<< (void (*func)(Output&) noexcept) noexcept = 0;

        virtual void flush() noexcept = 0;

        static void endl(Output& output) noexcept;

        struct Levels {
            void (*critical)(Output&) noexcept;
            void (*error)(Output&) noexcept;
            void (*warning)(Output&) noexcept;
            void (*info)(Output&) noexcept;
            void (*debug)(Output&) noexcept;
            void (*trace)(Output&) noexcept;
        };
        virtual const Levels& levels() const noexcept;

        struct Status {
            void (*success)(Output&) noexcept;
            void (*failure)(Output&) noexcept;
            void (*skip)(Output&) noexcept;
            void (*pending)(Output&) noexcept;
            void (*info)(Output&) noexcept;
            void (*trace)(Output&) noexcept;
            void (*reset)(Output&) noexcept;
        };
        virtual const Status& status() const noexcept;

        struct Characters {
            void (*tick)(Output&) noexcept;
            void (*cross)(Output&) noexcept;
        };
        virtual const Characters& characters() const noexcept;
    };
}