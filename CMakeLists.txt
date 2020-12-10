cmake_minimum_required(VERSION 3.0)

project(fmt_test)

add_subdirectory(external/fmtlib)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(hello src/main.cpp)
target_link_libraries(hello PRIVATE
    fmt
)
target_include_directories(hello PUBLIC 
    external/fmtlib/include
)
target_clangformat_setup(hello)
