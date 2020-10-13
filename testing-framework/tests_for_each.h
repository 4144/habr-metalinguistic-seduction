#ifndef TESTING_FRAMEWORK_TESTS_AUX_H
#define TESTING_FRAMEWORK_TESTS_AUX_H

#include "aux.h"

#define TESTS_FOR_EACH(op, ...) TESTS_FOR_EACH_0(op, __VA_ARGS__, end(), end())

#define TESTS_FOR_EACH_0(op, head, ...)                                                            \
    IF(TESTS_FOR_EACH_IS_END(head), CONSUME, TESTS_FOR_EACH_0_PROGRESS)(op, head, __VA_ARGS__)
#define TESTS_FOR_EACH_1(op, head, ...)                                                            \
    IF(TESTS_FOR_EACH_IS_END(head), CONSUME, TESTS_FOR_EACH_1_PROGRESS)(op, head, __VA_ARGS__)
#define TESTS_FOR_EACH_2(op, head, ...)                                                            \
    IF(TESTS_FOR_EACH_IS_END(head), CONSUME, TESTS_FOR_EACH_2_PROGRESS)(op, head, __VA_ARGS__)
#define TESTS_FOR_EACH_3(op, head, ...)                                                            \
    IF(TESTS_FOR_EACH_IS_END(head), CONSUME, TESTS_FOR_EACH_3_PROGRESS)(op, head, __VA_ARGS__)

#define TESTS_FOR_EACH_0_PROGRESS(op, head, ...)                                                   \
    op(TEST_NAME(head), TEST_BODY(head)) TESTS_FOR_EACH_1(op, __VA_ARGS__)
#define TESTS_FOR_EACH_1_PROGRESS(op, head, ...)                                                   \
    op(TEST_NAME(head), TEST_BODY(head)) TESTS_FOR_EACH_2(op, __VA_ARGS__)
#define TESTS_FOR_EACH_2_PROGRESS(op, head, ...)                                                   \
    op(TEST_NAME(head), TEST_BODY(head)) TESTS_FOR_EACH_3(op, __VA_ARGS__)
#define TESTS_FOR_EACH_3_PROGRESS(op, head, ...)                                                   \
    op(TEST_NAME(head), TEST_BODY(head)) TESTS_FOR_EACH_4(op, __VA_ARGS__)

#define TEST_NAME(test)                    MATCH(TEST_NAME_AUX_, test)
#define TEST_NAME_AUX_test(test_name, ...) test_name

#define TEST_BODY(test)                     MATCH(TEST_BODY_AUX_, test)
#define TEST_BODY_AUX_test(_test_name, ...) __VA_ARGS__

#define TESTS_FOR_EACH_IS_END(test)                 MATCH(TESTS_FOR_EACH_IS_END_, test)
#define TESTS_FOR_EACH_IS_END_test(_test_name, ...) 0
#define TESTS_FOR_EACH_IS_END_end()                 1

#endif // TESTING_FRAMEWORK_TESTS_AUX_H
