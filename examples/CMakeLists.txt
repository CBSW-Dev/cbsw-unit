add_executable(cbsw-unit-simple ${CBSW_UNIT_EXAMPLES_DIRECTORY}/simple/main.cpp)
target_include_directories(cbsw-unit-simple PRIVATE ${CBSW_UNIT_INCLUDE_DIRECTORY})
target_link_libraries(cbsw-unit-simple cbsw-unit)