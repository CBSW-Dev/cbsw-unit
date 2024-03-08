#pragma once

#include "plugin/plugin.hpp"

namespace CBSW::Unit {
    using PluginFinalFunction = int (*)(Arguments& arguments);
    class Plugins {
    public:
        int run(Arguments& arguments, PluginFinalFunction final);

        void registerPlugin(Plugin& plugin);
    private:
        using PluginList = std::list<Plugin*>;
        PluginList _plugins;
    };
}

CBSW::Unit::Plugins& cbsw_unit_plugins() noexcept;

