#ifndef TESTING_FRAMEWORK_RECTANGLE_H
#define TESTING_FRAMEWORK_RECTANGLE_H

typedef struct {
    unsigned height, width;
} Rectangle;

unsigned area(const Rectangle *rectangle);
unsigned perimeter(const Rectangle *rectangle);

#endif // TESTING_FRAMEWORK_RECTANGLE_H
