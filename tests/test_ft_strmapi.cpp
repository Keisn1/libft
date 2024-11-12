#include "test_libft.hpp"

struct FtStrmapiTestParams {
	const char *s;
	char (*f)(unsigned int, char);
	const char *want;
};

class FtStrmapiTest : public :: testing::TestWithParam<FtStrmapiTestParams>{};

TEST_P(FtStrmapiTest, HandleVariousInputs) {
	FtStrmapiTestParams params = GetParam();
	char* got = ft_strmapi(params.s, params.f);
	EXPECT_STREQ(got, params.want);
	free(got);
}

// Function to increment character by 1
char plus_1(unsigned int /*i*/, char c) {
	return c + 1;
}

// Function to increment character by its index value
char plus_i(unsigned int i, char c) {
	return c + i;
}

INSTANTIATE_TEST_SUITE_P(
    FtStrmapiTests,
	FtStrmapiTest,
	::testing::Values(
		FtStrmapiTestParams{"123", NULL, "123"},    // Test case where function pointer is NULL
		FtStrmapiTestParams{"123", plus_1, "234"},  // Test case where function adds 1 to each character
		FtStrmapiTestParams{"123", plus_i, "135"}   // Test case where function adds index to each character
	)
);


