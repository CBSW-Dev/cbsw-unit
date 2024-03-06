#include "pch.hpp"
#include "before-each-attorney.hpp"

#include "suite/ibefore-each.hpp"
#include "suite/ifixture.hpp"

namespace CBSW::Unit::Access {
    void BeforeEachAttorney::addBeforeEach(IFixture& fixture, IBeforeEach& beforeEach) noexcept {
        fixture.addBeforeEach(beforeEach);
    }
}