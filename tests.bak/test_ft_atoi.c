#include "../include/unity.h"
#include "../src/libft.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_should_return_42(void) {
	int got = ft_atoi("  42 abs");
	TEST_ASSERT_EQUAL(42, got);
}
