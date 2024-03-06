#include "pch.hpp"
#include "root-fixture.hpp"
#include "runnable-thread-pool.hpp"
#include "report/ireporter.hpp"
#include "utility/unused.hpp"

namespace CBSW::Unit {
    RootFixture::RootFixture() noexcept:
    //We do a dodgy cast of the parent to null, so the constructor still can accept a reference, but it can be used to detect end of "fixture chain"
        Fixture(*reinterpret_cast<IFixture*>(static_cast<void*>(nullptr)), "", "", 0)
    {}

    void RootFixture::run(IReporter& reporter, IReport& report, ISettings& settings) noexcept {
        auto threadCount = settings.threads();
        if (threadCount == 1) {
            //use a simpler single threaded routine if the thread count is 1
            run(reporter, report);
        } else {
            //use the multithreaded routine
            run(reporter, report, threadCount);
        }
    }

    void RootFixture::run(IReporter& reporter, IReport& report) noexcept {
        //begin the report
        reporter.onBegin();

        for (IRunnable* runnable: _runnables) {
            //iterate through the runnables, running each item
            runnable->run(reporter, report);
        }
        //end the report
        reporter.onEnd(report);
    }

    void RootFixture::run(IReporter& reporter, IReport& report, uint8_t threadCount) noexcept {
        //begin the report
        reporter.onBegin();

        //use a thread pool with the size specified in threadCount
        RunnableThreadPool threadPool(threadCount, _runnables.size());

        for (IRunnable* runnable: _runnables) {
            //iterate through the runnables, waiting for space in the threadpool
            threadPool.waitForSpace();
            //and then using the thread pool to execute the runnable in a thread
            threadPool.runRunnable(*runnable, reporter, report);
        }
        //All runnables have been scheduled, so terminate the pool, this will block waiting for all running threads to complete
        threadPool.terminate();
         //end the report
        reporter.onEnd(report);
    }
}

::CBSW::Unit::IFixture& cbsw_unit_fixture() {
    return cbsw_unit_root_fixture();
}

::CBSW::Unit::RootFixture& cbsw_unit_root_fixture() {
    static ::CBSW::Unit::RootFixture root_fixture;
    return root_fixture;

}