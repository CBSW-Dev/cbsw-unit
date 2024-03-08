target_sources(cbsw-unit PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/suite/fixture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/suite/root-fixture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/suite/runnable-thread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/suite/runnable-thread-pool.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/suite/case.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/suite/before-each.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/suite/after-each.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/suite/internal-runner.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/access/case-attorney.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/access/fixture-attorney.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/access/before-each-attorney.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/access/after-each-attorney.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/assert/exception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/assert/assertion-exception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/assert/unhandled-exception.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/output/output.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/output/output-indent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/output/ostream-output.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/output/ansi-color-ostream-output.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/report/ireporter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/report/spec/spec-reporter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/report/dot/dot-reporter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/report/min/min-reporter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/report/deferred/deferred-reporter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/report/deferred/deferred-reporter-action-list.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/report/report.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/plugin/plugin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/plugin/plugins.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/settings/internal-settings.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/settings/argument-parser.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
