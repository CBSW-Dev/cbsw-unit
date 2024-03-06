#include "pch.hpp"
#include "suite/case.hpp"
#include "access/case-attorney.hpp"
#include "report/ireporter.hpp"
#include "report/ireport.hpp"
#include "assert/unhandled-exception.hpp"

namespace CBSW::Unit {
    Case::Case(IFixture& fixture, Function function, Description description, Filename filename, LineNumber lineNumber) noexcept:
        _parent(fixture),
        _function(function),
        _description(description),
        _filename(filename),
        _lineNumber(lineNumber)
    {
        Access::CaseAttorney::addCase(fixture, *this);
    }

    void Case::run(IReporter& reporter, IReport& report) noexcept {
        (void)report;
        reporter.onBeginCase(*this);
        try {
            _function(*this);
            reporter.onCaseSuccess(*this);
            report.onSuccess(*this);
        } catch (const Exception& exception) {
            reporter.onCaseFailure(exception);
            report.onFailure(*this, exception);

        } catch (...) {
            const UnhandledException exception(*this);
            reporter.onCaseFailure(exception);
            report.onFailure(*this, exception);
        }
        reporter.onEndCase(*this);
    }

    const IFixture& Case::parent() const noexcept {
        return _parent;
    }

    Case::Description Case::description() const noexcept {
        return _description;
    }

    Case::Filename Case::filename() const noexcept {
        return _filename;
    }

    Case::LineNumber Case::lineNumber() const noexcept {
        return _lineNumber;
    }
}