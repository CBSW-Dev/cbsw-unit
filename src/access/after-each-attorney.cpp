#include "pch.hpp"
#include "after-each-attorney.hpp"

#include "suite/iafter-each.hpp"
#include "suite/ifixture.hpp"

namespace CBSW::Unit::Access {
    void AfterEachAttorney::addAfterEach(IFixture& fixture, IAfterEach& afterEach) noexcept {
        fixture.addAfterEach(afterEach);
    }
}