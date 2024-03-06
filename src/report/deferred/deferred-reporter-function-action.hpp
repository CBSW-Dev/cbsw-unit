#pragma once

#include "deferred-reporter-action.hpp"
#include "assert/exception.hpp"
namespace CBSW::Unit {
    template <class TParameter> class DeferredReporterFunctionAction: public DeferredReporterAction {
    public:
        using FunctionType = void (IReporter::*)(const TParameter& parameter);

        DeferredReporterFunctionAction(const TParameter& parameter, FunctionType function):
            _parameter(parameter),
            _function(function)
        {}

        void run(IReporter& reporter) noexcept override {
            (reporter.*_function)(_parameter);
        }

        DeferredReporterAction* clone() const override {
            return new DeferredReporterFunctionAction<TParameter>(_parameter, _function);
        }
    private:
        const TParameter& _parameter;
        FunctionType _function;
    };

    template <> class DeferredReporterFunctionAction<Exception>: public DeferredReporterAction {
    public:
        using FunctionType = void (IReporter::*)(const Exception& parameter);

        DeferredReporterFunctionAction(const Exception& parameter, FunctionType function):
            _parameter(parameter),
            _function(function)
        {}

        void run(IReporter& reporter) noexcept override {
            (reporter.*_function)(_parameter);
        }

        DeferredReporterAction* clone() const override {
            return new DeferredReporterFunctionAction<Exception>(_parameter, _function);
        }
    private:
        Exception _parameter;
        FunctionType _function;
    };

    template <> class DeferredReporterFunctionAction<void>: public DeferredReporterAction {
    public:
        using FunctionType = void (IReporter::*)();

        DeferredReporterFunctionAction(FunctionType function):
            _function(function)
        {}

        void run(IReporter& reporter) noexcept override {
            (reporter.*_function)();
        }

        DeferredReporterAction* clone() const override {
            return new DeferredReporterFunctionAction<void>(_function);
        }
    private:
        FunctionType _function;
    };
}