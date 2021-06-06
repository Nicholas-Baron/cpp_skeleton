cmake_minimum_required(VERSION 3.0)

# Modern C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Change the name of the project to start
project(fmt_test)

# For fmtlib
add_subdirectory(external/fmtlib)

# For clang-format support
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)

clangformat_setup(fmt_test)

# includes
include_directories(
    external/fmtlib/include
    external/boost_ut
)

# libraries
link_libraries(
    fmt
)

# Warning flags
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(
        -Wall -Wextra -Werror -Wredundant-decls
        -Wmissing-declarations -Wpedantic -Wimplicit-fallthrough -Walloc-zero
        -Wsuggest-override -Wsuggest-final-types -Wsuggest-final-methods
        )
endif()

# Optimization flags
if(NOT MSVC)
    add_compile_options(-O2)
endif()

# Setup executable
add_executable(hello src/main.cpp)

# Setup test executable
add_executable(hello_test src/test.cpp)
