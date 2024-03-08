#pragma once

#include <cbsw-unit>

class CustomPlugin: public ::CBSW::Unit::Plugin {
public:
    int initialise(::CBSW::Unit::Arguments& arguments, ::CBSW::Unit::PluginNextHandler& next) override;
};