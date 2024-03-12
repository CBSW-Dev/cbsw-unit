#pragma once

#include "icase.hpp"
#include "ifixture.hpp"

namespace CBSW::Unit {
    class Case: public ICase {
    public:
        friend class Fixture;

        using Function = void (*)(ICase&);


        Case(IFixture& fixture, Function function, Description description, Filename filename, LineNumber lineNumber) noexcept;
    private:
        void run(IReporter& reporter) noexcept override;

        const IFixture& parent() const noexcept override;
        Description description() const noexcept override;
        Filename filename() const noexcept override;
        LineNumber lineNumber() const noexcept override;
    private:
        IFixture& _parent;
        Function _function;
        Description _description;
        Filename _filename;
        LineNumber _lineNumber;
    };
}