#include "pch.hpp"
#include "internal-settings.hpp"

namespace CBSW::Unit {
    InternalSettings::InternalSettings():
        _reporter("spec"),
        _threads(4)
    {}

    const InternalSettings::ReporterType& InternalSettings::reporter() const noexcept {
        return _reporter;
    }

    InternalSettings::ThreadsType InternalSettings::threads() const noexcept {
        return _threads;
    }
}