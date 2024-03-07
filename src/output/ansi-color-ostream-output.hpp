#pragma once

#include "ostream-output.hpp"

namespace CBSW::Unit {
    class AnsiColorOStreamOutput: public OStreamOutput {
    public:
        using OStreamOutput::OStreamOutput;
    private:
        const Levels& levels() const noexcept override;
        const Status& status() const noexcept override;
        const Characters& characters() const noexcept override;
    };
}