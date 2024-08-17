#include <gtest/gtest.h>
#include <string.h>
#include <libft.h>

struct FtStrncmpTestParams {
	const char *s1;
	const char *s2;
	size_t n;
};

class FtStrncmpTest : public :: testing::TestWithParam<FtStrncmpTestParams>{};

TEST_P(FtStrncmpTest, HandleVariousInputs) {
	FtStrncmpTestParams params = GetParam();
	int got = ft_strncmp(params.s1, params.s2, params.n);
	int want = strncmp(params.s1, params.s2, params.n);
	EXPECT_TRUE((got < 0 && want < 0) || (got > 0 && want > 0) || (got == 0 && want == 0));
}

INSTANTIATE_TEST_SUITE_P(
	FtStrncmpTests,
	FtStrncmpTest,
	::testing::Values(
		FtStrncmpTestParams{"test\200", "test\0", 6}
		)
	);
