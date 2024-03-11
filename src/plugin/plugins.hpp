#pragma once

#include "plugin/plugin.hpp"

namespace CBSW::Unit {

    class PluginFinal {
    public:
        virtual ~PluginFinal() = default;

        virtual int finalPluginFunction() = 0;
    };

    class Plugins {
    public:
        int run(Arguments& arguments, PluginFinal& final);

        void registerPlugin(Plugin& plugin);
    private:
        using PluginList = std::list<Plugin*>;
        PluginList _plugins;
    };
}
