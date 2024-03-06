#pragma once

#include "runnable-thread.hpp"

namespace CBSW::Unit {
    class RunnableThreadPool {
    public:
        RunnableThreadPool(uint32_t capacity, uint32_t total) noexcept;
        ~RunnableThreadPool() noexcept;

        void waitForSpace();

        void runRunnable(IRunnable& runnable, IReporter& reporter, IReport& report);

        void terminate();
        void join();
    private:
        void threadMain();
        void processThreadCompletion();
        void waitForThreadsCompletion();
    private:
        uint32_t _capacity;
        uint32_t _total;
        uint32_t _count;
        RunnableThread** _threads;

        RunnableThreadSynchronisation _sync;
        std::mutex _mutex;
        std::condition_variable _condition;

        bool _terminate;
        std::thread _thread;
    };
}