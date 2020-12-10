cmake_minimum_required(VERSION 3.0)

add_subdirectory(external/fmtlib)

project(fmt_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(hello src/main.cpp)
target_link_libraries(hello PRIVATE
    fmt
)
target_include_directories(hello PUBLIC 
    external/fmtlib/include
)
