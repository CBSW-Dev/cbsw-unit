#pragma once

#include "settings/isettings.hpp"

namespace CBSW::Unit {
    class ArgumentParser;
    class InternalSettings: public ISettings {
    public:
        InternalSettings();

        const ReporterType& reporter() const noexcept override;
        ThreadsType threads() const noexcept;
        const ColorSupportType& colorSupport() const noexcept override;
        bool printVersion() const noexcept override;
        bool printHelp() const noexcept override;

        void loadFromArgs(const ArgumentParser& arguments);
    private:
        void loadReporterFromArgs(const ArgumentParser& arguments);
        void loadThreadsFromArgs(const ArgumentParser& arguments);
        void loadColorSupportFromArgs(const ArgumentParser& arguments);
        void loadPrintHelpFromArgs(const ArgumentParser& arguments);
        void loadPrintVersionFromArgs(const ArgumentParser& arguments);

    private:
        ReporterType _reporter;
        ThreadsType _threads;
        ColorSupportType _colorSupport;
        bool _printVersion;
        bool _printHelp;
    };
}