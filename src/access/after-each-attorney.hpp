#pragma once

namespace CBSW::Unit {
    class IFixture;
    class IAfterEach;
    class AfterEach;

    namespace Access {
        class AfterEachAttorney {
            friend class ::CBSW::Unit::AfterEach;
        private:
            static void addAfterEach(IFixture& fixture, IAfterEach& testCase) noexcept;
        };
    }
}