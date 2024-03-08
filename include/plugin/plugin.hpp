#pragma once

namespace CBSW::Unit {
    class PluginNextHandler {
    public:
        virtual ~PluginNextHandler() = default;

        virtual int next(int argc, char** argv) noexcept = 0;
    };

    class Plugin {
    public:
        Plugin();
        virtual ~Plugin() = default;
        virtual int initialise(int argc, char** argv, PluginNextHandler& next) = 0;
    };
}
