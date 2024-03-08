#pragma once

#include "irunnable.hpp"

namespace CBSW::Unit {
    namespace Access {
        //forward declare granularity friendship accessors. See https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Friendship_and_the_Attorney-Client
        class CaseAttorney;
        class FixtureAttorney;
        class BeforeEachAttorney;
        class AfterEachAttorney;
    }

    class ICase;
    class IBeforeEach;
    class IAfterEach;

    class IFixture: public IRunnable {
        friend class ::CBSW::Unit::Access::CaseAttorney;
        friend class ::CBSW::Unit::Access::BeforeEachAttorney;
        friend class ::CBSW::Unit::Access::AfterEachAttorney;
        friend class ::CBSW::Unit::Access::FixtureAttorney;

    public:
        using Description = const char*;
        using Filename = const char*;
        using LineNumber = std::uint32_t;

        virtual const IFixture* parent() const noexcept = 0;
        virtual Description description() const noexcept = 0;
        virtual Filename filename() const noexcept = 0;
        virtual LineNumber lineNumber() const noexcept = 0;
    protected:
        virtual void addCase(ICase& testCase) noexcept = 0;
        virtual void addFixture(IFixture& fixture) noexcept = 0;
        virtual void addBeforeEach(IBeforeEach& beforeEach) noexcept = 0;
        virtual void addAfterEach(IAfterEach& afterEach) noexcept = 0;
    private:
        static void * operator new(std::size_t) = delete;      // Prevent cases from being allocated on the heap
        static void * operator new [] (std::size_t) = delete;  // Prevent case arrays from being allocated on the heap
    };
}

CBSW::Unit::IFixture* cbsw_unit_fixture();