#include "rectangle.h"

unsigned area(const Rectangle *rectangle) {
    return rectangle->height * rectangle->width;
}

unsigned perimeter(const Rectangle *rectangle) {
    return (rectangle->height + rectangle->width) * 2;
}
