#include "pch.hpp"
#include "runnable-thread.hpp"
#include "report/deferred/deferred-reporter.hpp"
namespace CBSW::Unit {
    RunnableThread::RunnableThread(IRunnable& runnable, IReporter& reporter, RunnableThreadSynchronisation& synchronisation) noexcept:
        _runnable(runnable),
        _reporter(reporter, synchronisation.outputMutex),
        _synchronisation(synchronisation),
        _complete(false),
        _thread(&RunnableThread::threadMain, this)
    {}

        RunnableThread::~RunnableThread() {
        if (_thread.joinable()) {
            _thread.join();
        }
    }

    void RunnableThread::threadMain() {
        _runnable.run(_reporter);
        _reporter.resolveActions();

        std::lock_guard lock(_synchronisation.completeMutex);
        _complete = true;
        _synchronisation.completeCondition.notify_one();
    }

    bool RunnableThread::complete() const volatile {
        return _complete;
    }
}