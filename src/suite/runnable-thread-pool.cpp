#include "pch.hpp"
#include "runnable-thread-pool.hpp"

namespace CBSW::Unit {
    RunnableThreadPool::RunnableThreadPool(uint32_t capacity, uint32_t total) noexcept:
        _capacity(capacity),
        _total(total),
        _count(0),
        _threads(new RunnableThread*[capacity]),
        _terminate(false),
        _thread()
    {
        //default initialise all the threads to null
        for (uint32_t i = 0; i < capacity; ++i) {
            _threads[i] = nullptr;
        }

        //start the monitor thread
        _thread = std::thread(&RunnableThreadPool::threadMain, this);
    }

    RunnableThreadPool::~RunnableThreadPool() noexcept {
        //Wait for the monitor thread to complete
        if (_thread.joinable()) {
            terminate();
            _thread.join();
        }

        //delete all threads
        for (uint32_t i = 0; i < _capacity; ++i) {
            delete _threads[i];
        }
        //delete thread storage
        delete [] _threads;

    }

    void RunnableThreadPool::waitForSpace() {
        //acquire the lock
        std::unique_lock<std::mutex> lock(_mutex);
        //wait if we have hit capacity
        _condition.wait(lock, [&]() {
            return _count < _capacity;
        });

        //release the lock
    }

    void RunnableThreadPool::runRunnable(IRunnable& runnable, IReporter& reporter) {
        //acquire the lock
        std::lock_guard<std::mutex> lock(_mutex);

        //find the free thread slot and create a new runner
        for (uint32_t i = 0; i < _capacity; ++i) {
            if (_threads[i] == nullptr) {
                _threads[i] = new RunnableThread(runnable, reporter, _sync);
                break;
            }
        }
        //increase the count
        ++_count;

        //release the lock
    }

    void RunnableThreadPool::threadMain() {
        //continue looping until we tell the pool to stop
        while (_terminate == false) {
            {
                //wait for the complete condition to be trigged by either a thread in the pool, or the terminate function
                std::unique_lock lock(_sync.completeMutex);
                _sync.completeCondition.wait(lock);
            }
            //Process all threads that are complete, removing them from the pool
            processThreadCompletion();
        }

        while (_total != 0) {
            waitForThreadsCompletion();
        }
    }

    void RunnableThreadPool::terminate() {
        {
            //acquire the complete lock
            std::lock_guard lock(_sync.completeMutex);
            //set the terminate flag
            _terminate = true;
            //notify the complete condition
            _sync.completeCondition.notify_one();
            //release the complete lock
        }

        _thread.join();
    }

    void RunnableThreadPool::processThreadCompletion() {
        //acquire the thread storage lock
        std::lock_guard<std::mutex> lock(_mutex);
        for (uint32_t i = 0; i < _capacity; ++i) {
            //if the thread is allocated, and complete
            if (_threads[i] != nullptr && _threads[i]->complete()) {
                //delete the thread
                delete _threads[i];
                //remove it from the pool
                _threads[i] = nullptr;
                //decrease the count
                --_count;
                //decrease the total (N.B. 0 means we have completed all runnables)
                --_total;

                //and notify that the condition is met, so that the waitForSpace function can unblock
                _condition.notify_one();
            }
        }
        //release the thread storage lock
    }
    void RunnableThreadPool::waitForThreadsCompletion() {
       //acquire the thread storage lock
       std::lock_guard<std::mutex> lock(_mutex);

       for (uint32_t i = 0; i < _capacity; ++i) {
            //if the thread is allocated (we do not care if it is complete yet)
            if (_threads[i] != nullptr) {
                //delete the thread, waiting for its completion via the destructor
                delete _threads[i];
                //remove it from the pool
                _threads[i] = nullptr;
                //decrease the count
                --_count;
                 //decrease the total (N.B. 0 means we have completed all runnables)
                 --_total;
                //and notify that the condition is met, so that the waitForSpace function can unblock
                _condition.notify_one();
            }
        }
        //release the thread storage lock
    }
}
