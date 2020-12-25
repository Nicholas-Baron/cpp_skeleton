#include <fmt/core.h>

#include <ut.hpp>

int main() {
    using namespace boost::ut;
    "print"_test = [] { fmt::print("Hello, World\n"); };
}
