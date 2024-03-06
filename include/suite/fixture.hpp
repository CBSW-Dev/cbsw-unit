#pragma once

#include "ifixture.hpp"

#include <list>

namespace CBSW::Unit {
    class Fixture: public IFixture {
    public:
        Fixture(IFixture& parent, Description description, Filename filename, LineNumber lineNumber) noexcept;
    private:
        void addCase(ICase& testCase) noexcept override;
        void addFixture(IFixture& fixture) noexcept override;

        void run(IReporter& reporter, IReport& report) noexcept override;
        const IFixture& parent() const noexcept override;
        Description description() const noexcept override;
        Filename filename() const noexcept override;
        LineNumber lineNumber() const noexcept override;
    protected:
        IFixture& _parent;
        Description _description;
        Filename _filename;
        LineNumber _lineNumber;

        using RunnableList = std::list<IRunnable*>;
        RunnableList _runnables;
    };
}