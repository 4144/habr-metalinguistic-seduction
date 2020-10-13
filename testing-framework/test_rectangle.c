#include "rectangle.h"
#include "test.h"

TESTING(
    // clang-format off
TEST(test_area) {
    Rectangle rectangle = {.height = 15, .width = 8};
    ASSERT(area(&rectangle) == 15 * 8);
}

TEST(test_perimeter) {
    Rectangle rectangle = {.height = 61, .width = 7};
    ASSERT(perimeter(&rectangle) == (61 + 7) * 2);
}
    // clang-format on
)
