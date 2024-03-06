#include "pch.hpp"
#include "output/output.hpp"

namespace CBSW::Unit {
    namespace {
        void nullFunction(Output&) noexcept {}
        Output::Levels nullLevels = {
            &nullFunction,
            &nullFunction,
            &nullFunction,
            &nullFunction,
            &nullFunction,
            &nullFunction
        };

        Output::Status nullStatus = {
            &nullFunction,
            &nullFunction,
            &nullFunction,
            &nullFunction,
            &nullFunction,
            &nullFunction,
            &nullFunction
        };

        Output::Characters nullCharacters = {
            &nullFunction,
            &nullFunction
        };
    }

    void Output::endl(Output& output) noexcept {
        output << "\r\n";
        output.flush();
        (void)output;
    }

    const Output::Levels& Output::levels() const noexcept {
        return nullLevels;
    }

    const Output::Status& Output::status() const noexcept {
        return nullStatus;
    }

    const Output::Characters& Output::characters() const noexcept {
        return nullCharacters;
    }
}