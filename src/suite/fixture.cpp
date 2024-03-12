#include "pch.hpp"

#include "suite/fixture.hpp"
#include "suite/icase.hpp"
#include "suite/ibefore-each.hpp"
#include "suite/iafter-each.hpp"
#include "access/fixture-attorney.hpp"
#include "report/ireporter.hpp"
#include "report/ireport.hpp"

namespace CBSW::Unit {
    Fixture::Fixture(IFixture* parent, Description description, Filename filename, LineNumber lineNumber) noexcept:
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

    void Fixture::addBeforeEach(IBeforeEach& beforeEach) noexcept {
        _beforeEachs.push_back(&beforeEach);
    }

    void Fixture::addAfterEach(IAfterEach& afterEach) noexcept {
        _afterEachs.push_back(&afterEach);
    }

    void Fixture::run(IReporter& reporter) noexcept {
        reporter.onBeginFixture(*this);
        for (IRunnable* runnable: _runnables) {
            runBeforeEachs(reporter);
            runnable->run(reporter);
            runAfterEachs(reporter);
        }
        reporter.onEndFixture(*this);
    }

    const IFixture* Fixture::parent() const noexcept {
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

    void Fixture::runBeforeEachs(IReporter& reporter) noexcept {
        for (IBeforeEach* beforeEach: _beforeEachs) {
            beforeEach->run(reporter);
        }
    }

    void Fixture::runAfterEachs(IReporter& reporter) noexcept {
        for (IAfterEach* afterEach: _afterEachs) {
            afterEach->run(reporter);
        }
    }
}