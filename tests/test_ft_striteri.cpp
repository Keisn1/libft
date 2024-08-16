#include <gtest/gtest.h>
#include "libft.h"

struct FtStriteriTestParams {
	const char *s;
	void (*f)(unsigned int, char*);
	const char *want;
};

class FtStriteriTest : public :: testing::TestWithParam<FtStriteriTestParams>{};

TEST_P(FtStriteriTest, HandleVariousInputs) {
	FtStriteriTestParams params = GetParam();
	char* got = ft_strdup(params.s);
	ft_striteri(got, params.f);
	EXPECT_STREQ(got, params.want);
	free(got);
}

// Function to increment character by 1
void plus_1(unsigned int /*i*/, char *c) {
	*c += 1;
}

// Function to increment character by its index value
void plus_i(unsigned int i, char *c) {
	*c += i;
}

INSTANTIATE_TEST_SUITE_P(
    FtStriteriTests,
	FtStriteriTest,
	::testing::Values(
		FtStriteriTestParams{"123", NULL, "123"},
		FtStriteriTestParams{"123", plus_1, "234"},
		FtStriteriTestParams{"123", plus_i, "135"}
	)
);
