#pragma once

#include "suite/fixture.hpp"
#include "settings/isettings.hpp"

namespace CBSW::Unit {
    class RootFixture: public Fixture {
    public:
        RootFixture() noexcept;
        void run(IReporter& reporter, ISettings& settings) noexcept;
    private:
        void run(IReporter& reporter) noexcept override;
        void run(IReporter& reporter, uint8_t threadCount) noexcept;
    };
}

::CBSW::Unit::RootFixture* cbsw_unit_root_fixture();