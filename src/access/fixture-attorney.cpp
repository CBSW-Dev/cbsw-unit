#include "pch.hpp"
#include "fixture-attorney.hpp"

#include "suite/ifixture.hpp"

namespace CBSW::Unit {
    namespace Access {
        void FixtureAttorney::addFixture(IFixture* parent, IFixture& fixture) noexcept {
            //A parent at address nullptr, is the root fixture
            if (parent != nullptr) {
                parent->addFixture(fixture);
            }
        }
    }
}