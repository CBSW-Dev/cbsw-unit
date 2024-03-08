#pragma once

#include <set>
#include <string>

namespace CBSW::Unit {
    class ValidLibraryArguments: public std::set<std::string> {
    public:
        ValidLibraryArguments() noexcept;

        static ValidLibraryArguments& instance() noexcept;
    };


}