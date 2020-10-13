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
    FORCE_SEMICOLON()

#define OPEN_BRACE() (

#define TEST(name) ), test OPEN_BRACE() name,

#define TESTING(...) TESTING_AUX((__VA_ARGS__)) FORCE_SEMICOLON()
#define TESTING_AUX(_empty, ...)                                                                   \
    GEN_TESTS(__VA_ARGS__)                                                                         \
                                                                                                   \
    int main(void) {                                                                               \
        int res = 0;                                                                               \
        GEN_TEST_CALLS(__VA_ARGS__)                                                                \
                                                                                                   \
        printf("Testing %s!\n", TEST_STATUS());                                                    \
        return res;                                                                                \
    }

#define GEN_TESTS(...) TESTS_FOR_EACH(GEN_TESTS_VISIT_ONE, __VA_ARGS__)
#define GEN_TESTS_VISIT_ONE(test_name, ...)                                                        \
    static int test_name(void) {                                                                   \
        int res = 0;                                                                               \
        __VA_ARGS__                                                                                \
        printf(STRINGIFY(test_name) " %s!\n", TEST_STATUS());                                      \
    fail:                                                                                          \
        return res;                                                                                \
    }

#define GEN_TEST_CALLS(...)                      TESTS_FOR_EACH(GEN_TEST_CALLS_VISIT_ONE, __VA_ARGS__)
#define GEN_TEST_CALLS_VISIT_ONE(test_name, ...) res += test_name();

#define TEST_STATUS() (res == 0 ? "passed" : "failed")

#endif // TESTING_FRAMEWORK_TEST_H
