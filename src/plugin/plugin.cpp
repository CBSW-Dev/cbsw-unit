#include "pch.hpp"
#include "plugin/plugin.hpp"
#include "plugins.hpp"


namespace CBSW::Unit {
    Plugin::Plugin() {
        cbsw_unit_plugins().registerPlugin(*this);
    }
}