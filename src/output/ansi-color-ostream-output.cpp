#include "pch.hpp"
#include "ansi-color-ostream-output.hpp"

namespace CBSW::Unit {
    namespace {
        constexpr const char* backgroundRed = "\x1B[41m";
        constexpr const char* foregroundBlack = "\x1B[30m";
        constexpr const char* foregroundRed = "\x1B[31m";
        constexpr const char* foregroundGreen = "\x1B[32m";
        constexpr const char* foregroundMagenta = "\x1B[35m";
        constexpr const char* foregroundDarkGrey = "\x1B[90m";
        constexpr const char* foregroundYellow = "\x1B[93m";
        constexpr const char* foregroundWhite = "\x1B[97m";
        constexpr const char* foregroundGrey = "\x1B[37m";
        constexpr const char* modifierReset = "\x1B[0m";

        void localLevelCritical(Output& output) noexcept {
            output << backgroundRed << foregroundBlack;
        }

        void localLevelError(Output& output) noexcept {
            output << foregroundRed;
        }

        void localLevelWarning(Output& output) noexcept {
            output << foregroundYellow;
        }

        void localLevelInfo(Output& output) noexcept {
            output << foregroundWhite;
        }

        void localLevelDebug(Output& output) noexcept {
            output << foregroundGrey;
        }

        void localLevelTrace(Output& output) noexcept {
            output << foregroundGrey;
        }

        Output::Levels localLevels = {
            &localLevelCritical,
            &localLevelError,
            &localLevelWarning,
            &localLevelInfo,
            &localLevelDebug,
            &localLevelTrace,
        };

        void localStatusSuccess(Output& output) noexcept {
            output << foregroundGreen;
        }

        void localStatusFailure(Output& output) noexcept {
            output << foregroundRed;
        }

        void localStatusSkip(Output& output) noexcept {
            output << foregroundDarkGrey;
        }

        void localStatusPending(Output& output) noexcept {
            output << foregroundMagenta;
        }

        void localStatusInfo(Output& output) noexcept {
            output << foregroundWhite;
        }

        void localStatusTrace(Output& output) noexcept {
            output << foregroundDarkGrey;
        }

        void localStatusReset(Output& output) noexcept {
            output << modifierReset;
        }

        Output::Status localStatus = {
            &localStatusSuccess,
            &localStatusFailure,
            &localStatusSkip,
            &localStatusPending,
            &localStatusInfo,
            &localStatusTrace,
            &localStatusReset,
        };

        constexpr const char* utf8Tick = "\xE2\x9C\x94";
        constexpr const char* utf8Cross = "\xE2\x9C\x98";

        void localCharactersTick(Output& output) noexcept {
            output << utf8Tick;
        }

        void localCharactersCross(Output& output) noexcept {
            output << utf8Cross;
        }

        Output::Characters localCharacters = {
            &localCharactersTick,
            &localCharactersCross
        };
    }

    const AnsiColorOStreamOutput::Levels& AnsiColorOStreamOutput::levels() const noexcept {
        return localLevels;
    }

    const AnsiColorOStreamOutput::Status& AnsiColorOStreamOutput::status() const noexcept {
        return localStatus;
    }

    const AnsiColorOStreamOutput::Characters& AnsiColorOStreamOutput::characters() const noexcept {
        return localCharacters;
    }
}