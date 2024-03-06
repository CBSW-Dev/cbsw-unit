#pragma once

#include "ibefore-each.hpp"
#include "ifixture.hpp"

namespace CBSW::Unit {
    class BeforeEach: public IBeforeEach {
    public:
        friend class Fixture;

        using Function = void (*)();

        BeforeEach(IFixture& fixture, Function function, Filename filename, LineNumber lineNumber) noexcept;
    private:
        void run(IReporter& reporter, IReport& report) noexcept override;

        const IFixture& parent() const noexcept override;
        Filename filename() const noexcept override;
        LineNumber lineNumber() const noexcept override;
    private:
        IFixture& _parent;
        Function _function;
        Filename _filename;
        LineNumber _lineNumber;
    };
}