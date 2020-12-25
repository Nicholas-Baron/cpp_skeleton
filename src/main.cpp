#include <fmt/core.h>
#include <fmt/ranges.h>

#include <vector>

int main() {
    fmt::print("{}\n", std::vector<int>{1, 2, 3, 4, 5});
}
