#pragma once

namespace CBSW::Unit {
    class IFixture;
    class IBeforeEach;
    class BeforeEach;

    namespace Access {
        class BeforeEachAttorney {
            friend class ::CBSW::Unit::BeforeEach;
        private:
            static void addBeforeEach(IFixture& fixture, IBeforeEach& testCase) noexcept;
        };
    }
}