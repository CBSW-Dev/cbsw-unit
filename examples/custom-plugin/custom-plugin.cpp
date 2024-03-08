#include "custom-plugin.hpp"

#include <iostream>

int CustomPlugin::initialise(::CBSW::Unit::Arguments& arguments, ::CBSW::Unit::PluginNextHandler& next) {
    for (char* argument: arguments) {
        if (std::string(argument) == "--custom-plugin-trap") {
            std::cout << "custom-plugin-trap" << std::endl;
            return EXIT_FAILURE;
        }
    }
    return next.next(arguments);
}
