#pragma once

namespace CBSW::Unit {
    class IFixture;
    class Fixture;

    namespace Access {
        class FixtureAttorney {
            friend class ::CBSW::Unit::Fixture;
        private:
            static void addFixture(IFixture* parent, IFixture& fixture) noexcept;
        };
    }
}