#include "pch.hpp"
#include "suite/after-each.hpp"
#include "access/after-each-attorney.hpp"
#include "report/ireporter.hpp"
#include "report/ireport.hpp"
#include "assert/unhandled-exception.hpp"

namespace CBSW::Unit {
    AfterEach::AfterEach(IFixture& fixture, Function function, Filename filename, LineNumber lineNumber) noexcept:
        _parent(fixture),
        _function(function),
        _filename(filename),
        _lineNumber(lineNumber)
    {
        Access::AfterEachAttorney::addAfterEach(fixture, *this);
    }

    void AfterEach::run(IReporter& reporter, IReport& report) noexcept {
        (void)report;
        reporter.onBeginAfterEach(*this);
        _function();
        reporter.onEndAfterEach(*this);
    }

    const IFixture& AfterEach::parent() const noexcept {
        return _parent;
    }

    AfterEach::Filename AfterEach::filename() const noexcept {
        return _filename;
    }

    AfterEach::LineNumber AfterEach::lineNumber() const noexcept {
        return _lineNumber;
    }
}