#pragma once

namespace CBSW::Unit {
    class IFixture;
    class ICase;
    class Case;

    namespace Access {
        class CaseAttorney {
            friend class ::CBSW::Unit::Case;
        private:
            static void addCase(IFixture& fixture, ICase& testCase) noexcept;
        };
    }
}