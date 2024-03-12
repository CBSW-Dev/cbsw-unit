#include "pch.hpp"
#include "suite/before-each.hpp"
#include "access/before-each-attorney.hpp"
#include "report/ireporter.hpp"
#include "report/ireport.hpp"
#include "assert/unhandled-exception.hpp"

namespace CBSW::Unit {
    BeforeEach::BeforeEach(IFixture& fixture, Function function, Filename filename, LineNumber lineNumber) noexcept:
        _parent(fixture),
        _function(function),
        _filename(filename),
        _lineNumber(lineNumber)
    {
        Access::BeforeEachAttorney::addBeforeEach(fixture, *this);
    }

    void BeforeEach::run(IReporter& reporter) noexcept {
        reporter.onBeginBeforeEach(*this);
        _function();
        reporter.onEndBeforeEach(*this);
    }

    const IFixture& BeforeEach::parent() const noexcept {
        return _parent;
    }

    BeforeEach::Filename BeforeEach::filename() const noexcept {
        return _filename;
    }

    BeforeEach::LineNumber BeforeEach::lineNumber() const noexcept {
        return _lineNumber;
    }
}