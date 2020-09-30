#ifndef TESTING_FRAMEWORK_TEST_H
#define TESTING_FRAMEWORK_TEST_H

#include "aux.h"
#include "tests_for_each.h"

#include <assert.h>
#include <stdio.h>

#define ASSERT(...)                                                                                \
    if ((__VA_ARGS__) == 0) {                                                                      \
        fprintf(stderr, "Assertion failed: " #__VA_ARGS__ "\nLine %d\n", __LINE__);                \
        res++;                                                                                     \
        goto fail;                                                                                 \
    }                                                                                              \
                                                                                                   \
    FORCE_SEMICOLON

#define is ,

#define TEST(...)                TEST_AUX(__VA_ARGS__)
#define TEST_AUX(test_name, ...) test(test_name, __VA_ARGS__)

#define TESTING(tests)                                                                             \
    GEN_TESTS(tests)                                                                               \
                                                                                                   \
    int main(void) {                                                                               \
        int res = 0;                                                                               \
        GEN_TEST_CALLS(tests)                                                                      \
                                                                                                   \
        printf("Testing %s!\n", TEST_STATUS());                                                    \
        return res;                                                                                \
    }

#define GEN_TESTS(tests) TESTS_FOR_EACH(GEN_TESTS_VISIT_ONE, tests)
#define GEN_TESTS_VISIT_ONE(test_name, ...)                                                        \
    static int test_name(void) {                                                                   \
        int res = 0;                                                                               \
        __VA_ARGS__                                                                                \
        printf(STRINGIFY(test_name) " %s!\n", TEST_STATUS());                                      \
    fail:                                                                                          \
        return res;                                                                                \
    }

#define GEN_TEST_CALLS(tests)                    TESTS_FOR_EACH(GEN_TEST_CALLS_VISIT_ONE, tests)
#define GEN_TEST_CALLS_VISIT_ONE(test_name, ...) res += test_name();

#define TEST_STATUS() (res == 0 ? "passed" : "failed")

#endif // TESTING_FRAMEWORK_TEST_H
