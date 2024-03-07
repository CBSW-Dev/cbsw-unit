cmake_minimum_required(VERSION 3.10)

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()


project(CBSW_Unit VERSION 1.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CBSW_UNIT_INCLUDE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CBSW_UNIT_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CBSW_UNIT_EXAMPLES_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/examples)

configure_file(${CBSW_UNIT_SOURCE_DIRECTORY}/settings/version.hpp.in settings/version.hpp)

add_library(cbsw-unit)
add_subdirectory(${CBSW_UNIT_SOURCE_DIRECTORY})

target_precompile_headers(cbsw-unit PRIVATE ${CBSW_UNIT_SOURCE_DIRECTORY}/pch.hpp)
target_include_directories(cbsw-unit PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(cbsw-unit PUBLIC "${CBSW_UNIT_INCLUDE_DIRECTORY}")
target_include_directories(cbsw-unit PUBLIC "${CBSW_UNIT_SOURCE_DIRECTORY}")

target_compile_options(cbsw-unit PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

option(CBSW_UNIT_BUILD_EXAMPLES "Build the example applications" ON)

if(CBSW_UNIT_BUILD_EXAMPLES)
    add_subdirectory(${CBSW_UNIT_EXAMPLES_DIRECTORY})
endif()

install(TARGETS cbsw-unit DESTINATION lib)
install(DIRECTORY ${CBSW_UNIT_INCLUDE_DIRECTORY} DESTINATION include/cbsw-unit)