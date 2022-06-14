cmake_minimum_required(VERSION 3.16)
project(
  example
  VERSION 0.0.1
  LANGUAGES C CXX)

# Project options
# ==============================================================================

# Build msgpack-cxx without Boost (experimental)
option(MSGPACK_USE_BOOST "Build msgpack-cxx with Boost" ON)

# Declare dependencies
# ==============================================================================

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
include(FetchContent)
include(FetchContent_Declare_msgpack)

FetchContent_MakeAvailable(msgpackc)

add_executable(example)
target_sources(example PRIVATE main.cpp)
target_link_libraries(example PUBLIC msgpackc-cxx)

# This line fixes the issue
# target_compile_definitions(msgpackc-cxx INTERFACE MSGPACK_NO_BOOST)