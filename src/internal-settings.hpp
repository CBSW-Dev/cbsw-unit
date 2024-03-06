#pragma once

#include "isettings.hpp"

namespace CBSW::Unit {
    class InternalSettings: public ISettings {
    public:
        InternalSettings();

        const ReporterType& reporter() const noexcept override;
        ThreadsType threads() const noexcept;
    private:
        ReporterType _reporter;
        ThreadsType _threads;
    };
}