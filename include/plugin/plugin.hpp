#pragma once

#include "arguments.hpp"

namespace CBSW::Unit {
    class PluginNextHandler {
    public:
        virtual ~PluginNextHandler() = default;

        virtual int next(Arguments& arguments) noexcept = 0;
    };

    class Plugin {
    public:
        Plugin();
        virtual ~Plugin() = default;
        virtual int initialise(Arguments& arguments, PluginNextHandler& next) = 0;
    };
}
