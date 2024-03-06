add_executable(cbsw-unit-simple ${CBSW_UNIT_EXAMPLES_DIRECTORY}/simple/main.cpp)
target_include_directories(cbsw-unit-simple PRIVATE ${CBSW_UNIT_INCLUDE_DIRECTORY})
target_link_libraries(cbsw-unit-simple cbsw-unit)

add_executable(cbsw-unit-jest-style ${CBSW_UNIT_EXAMPLES_DIRECTORY}/jest-style/main.cpp)
target_include_directories(cbsw-unit-jest-style PRIVATE ${CBSW_UNIT_INCLUDE_DIRECTORY})
target_link_libraries(cbsw-unit-jest-style cbsw-unit)