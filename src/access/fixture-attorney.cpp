#include "pch.hpp"
#include "fixture-attorney.hpp"

#include "suite/ifixture.hpp"

namespace CBSW::Unit {
    namespace Access {
        namespace {
            bool isNonRoot(IFixture* parent) {
                return parent != nullptr;
            }
        }
        void FixtureAttorney::addFixture(IFixture& parent, IFixture& fixture) noexcept {
            //A parent at address nullptr, is the root fixture
            if (isNonRoot(&parent)) {
                parent.addFixture(fixture);
            }
        }
    }
}