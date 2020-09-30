#ifndef TESTING_FRAMEWORK_AUX_H
#define TESTING_FRAMEWORK_AUX_H

#include <assert.h>
#include <stdbool.h>

#define IF(cond, x, y) MATCH(IF, cond)((x), (y))
#define IF_0(_x, y)    UNPARENTHESISE(y)
#define IF_1(x, _y)    UNPARENTHESISE(x)

#define EXPAND(...) __VA_ARGS__
#define EMPTY()
#define UNPARENTHESISE(x)  EXPAND(EXPAND x)
#define MATCH(op, pattern) CAT(CAT(op, _), pattern)

#define CAT(x, y)           PRIMITIVE_CAT(x, y)
#define PRIMITIVE_CAT(x, y) x##y

#define STRINGIFY(x)           PRIMITIVE_STRINGIFY(x)
#define PRIMITIVE_STRINGIFY(x) #x

#define FORCE_SEMICOLON static_assert(true, "")

#endif // TESTING_FRAMEWORK_AUX_H
