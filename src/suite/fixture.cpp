#include "pch.hpp"

#include "suite/fixture.hpp"
#include "suite/icase.hpp"
#include "access/fixture-attorney.hpp"
#include "report/ireporter.hpp"

namespace CBSW::Unit {
    Fixture::Fixture(IFixture& parent, Description description, Filename filename, LineNumber lineNumber) noexcept:
        _parent(parent),
        _description(description),
        _filename(filename),
        _lineNumber(lineNumber)
    {
        Access::FixtureAttorney::addFixture(parent, *this);
    }

    void Fixture::addCase(ICase& testCase) noexcept {
        _runnables.push_back(&testCase);
    }

    void Fixture::addFixture(IFixture& fixture) noexcept {
        _runnables.push_back(&fixture);
    }

    void Fixture::run(IReporter& reporter, IReport& report) noexcept {
        reporter.onBeginFixture(*this);
        for (IRunnable* runnable: _runnables) {
            runnable->run(reporter, report);
        }
        reporter.onEndFixture(*this);
    }

    const IFixture& Fixture::parent() const noexcept {
        return _parent;
    }

    Fixture::Description Fixture::description() const noexcept {
        return _description;
    }

    Fixture::Filename Fixture::filename() const noexcept {
        return _filename;
    }

    Fixture::LineNumber Fixture::lineNumber() const noexcept {
        return _lineNumber;
    }
}