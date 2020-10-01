#include "rectangle.h"
#include "test.h"

// clang-format off
TESTING(
    TEST(test_area is {
        Rectangle rectangle = {.height = 15, .width = 8};
        ASSERT(area(&rectangle) == 15 * 8);
    })

    TEST(test_perimeter is {
        Rectangle rectangle = {.height = 61, .width = 7};
        ASSERT(perimeter(&rectangle) == (61 + 7) * 2);
    })
)
// clang-format on