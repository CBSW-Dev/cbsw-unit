#pragma once

#include "plugin/plugin.hpp"

namespace CBSW::Unit {
    using PluginFinalFunction = int (*)(int argc, char** argv);
    class Plugins {
    public:
        int run(int argc, char** argv, PluginFinalFunction final);

        void registerPlugin(Plugin& plugin);
    private:
        using PluginList = std::list<Plugin*>;
        PluginList _plugins;
    };
}

CBSW::Unit::Plugins& cbsw_unit_plugins() noexcept;

