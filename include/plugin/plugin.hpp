#pragma once

namespace CBSW::Unit {
    class Plugin {
    public:
        Plugin();
        virtual ~Plugin() = default;
        virtual int initialise(int argc, char** argv, int (*next)(int, char**)) = 0;
    };
}