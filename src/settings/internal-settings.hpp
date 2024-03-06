#pragma once

#include "settings/isettings.hpp"

namespace CBSW::Unit {
    class ArgumentParser;
    class InternalSettings: public ISettings {
    public:
        InternalSettings();

        const ReporterType& reporter() const noexcept override;
        ThreadsType threads() const noexcept;

        void loadFromArgs(const ArgumentParser& arguments);
    private:
        void loadReporterFromArgs(const ArgumentParser& arguments);
        void loadThreadsFromArgs(const ArgumentParser& arguments);
    private:
        ReporterType _reporter;
        ThreadsType _threads;
    };
}