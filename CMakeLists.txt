cmake_minimum_required(VERSION 3.0)

project(fmt_test)

# For fmtlib
add_subdirectory(external/fmtlib)

# For clang-format support
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ClangFormat)

# Modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Warning flags
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror -Wmissing-declarations)
endif()

# Optimization flags
if(NOT MSVC)
    add_compile_options(-O2)
endif()

# Setup executable
add_executable(hello src/main.cpp)
target_link_libraries(hello PRIVATE
    fmt
)
target_include_directories(hello PUBLIC 
    external/fmtlib/include
    external/boost_ut
)
target_clangformat_setup(hello)
