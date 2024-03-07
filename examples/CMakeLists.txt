add_executable(cbsw-unit-simple ${CBSW_UNIT_EXAMPLES_DIRECTORY}/simple/main.cpp)
target_include_directories(cbsw-unit-simple PRIVATE ${CBSW_UNIT_INCLUDE_DIRECTORY})
target_link_libraries(cbsw-unit-simple cbsw-unit)

add_executable(cbsw-unit-jest-style ${CBSW_UNIT_EXAMPLES_DIRECTORY}/jest-style/main.cpp)
target_include_directories(cbsw-unit-jest-style PRIVATE ${CBSW_UNIT_INCLUDE_DIRECTORY})
target_link_libraries(cbsw-unit-jest-style cbsw-unit)

add_executable(cbsw-unit-custom-reporter ${CBSW_UNIT_EXAMPLES_DIRECTORY}/custom-reporter/main.cpp)
target_sources(cbsw-unit-custom-reporter PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/custom-reporter/custom-reporter.cpp
)
target_include_directories(cbsw-unit-custom-reporter PRIVATE ${CBSW_UNIT_INCLUDE_DIRECTORY})
target_link_libraries(cbsw-unit-custom-reporter cbsw-unit)

add_executable(cbsw-unit-custom-output ${CBSW_UNIT_EXAMPLES_DIRECTORY}/custom-output/main.cpp)
target_sources(cbsw-unit-custom-output PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/custom-output/custom-output.cpp
)
target_include_directories(cbsw-unit-custom-output PRIVATE ${CBSW_UNIT_INCLUDE_DIRECTORY})
target_link_libraries(cbsw-unit-custom-output cbsw-unit)