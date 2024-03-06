#pragma once

#include "irunnable.hpp"

namespace CBSW::Unit {
    class IReporter;
    class IReport;
    class IFixture;

    class ICase: public IRunnable {
    public:
        using Description = const char*;
        using Filename = const char*;
        using LineNumber = std::uint32_t;

        virtual const IFixture& parent() const noexcept = 0;
        virtual Description description() const noexcept = 0;
        virtual Filename filename() const noexcept = 0;
        virtual LineNumber lineNumber() const noexcept = 0;
    private:
        static void * operator new(std::size_t) = delete;      // Prevent cases from being allocated on the heap
        static void * operator new [] (std::size_t) = delete;  // Prevent case arrays from being allocated on the heap
    };
}