#pragma once

#include "suite/irunnable.hpp"
#include "report/deferred/deferred-reporter.hpp"
#include <mutex>
#include <thread>
#include <condition_variable>
namespace CBSW::Unit {
    struct RunnableThreadSynchronisation {
        std::mutex completeMutex;
        std::condition_variable completeCondition;
        std::mutex outputMutex;
    };

    class RunnableThread {
    public:
        RunnableThread(IRunnable& runnable, IReporter& reporter, IReport& report, RunnableThreadSynchronisation& synchronisation) noexcept;
        ~RunnableThread();
        bool complete() const volatile;
    private:
        void threadMain();
    private:
        IRunnable& _runnable;
        DeferredReporter _reporter;
        IReport& _report;
        RunnableThreadSynchronisation& _synchronisation;

        bool _complete;

        std::thread _thread;
    };
}