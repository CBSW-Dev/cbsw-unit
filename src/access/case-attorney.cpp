#include "pch.hpp"
#include "case-attorney.hpp"

#include "suite/icase.hpp"
#include "suite/ifixture.hpp"

namespace CBSW::Unit::Access {
    void CaseAttorney::addCase(IFixture& fixture, ICase& testCase) noexcept {
        fixture.addCase(testCase);
    }
}