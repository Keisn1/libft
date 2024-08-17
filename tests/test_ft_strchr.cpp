#include <gtest/gtest.h>
#include <string.h>
#include "libft.h"

struct FtStrchrTestParams {
	const char *s;
	int c;
};

class FtStrchrTest : public ::testing::TestWithParam<FtStrchrTestParams>{};

TEST_P(FtStrchrTest, HandleVariousInputs) {
	FtStrchrTestParams params = GetParam();
	const char* got = ft_strchr(params.s, params.c);
	const char* want = strchr(params.s, params.c);
	EXPECT_STREQ(got, want);
}

INSTANTIATE_TEST_SUITE_P(
	FtStrchrTests,
	FtStrchrTest,
	::testing::Values(
		FtStrchrTestParams{"teste", 1024},
		FtStrchrTestParams{"helloXworld", 'X'},
		FtStrchrTestParams{"helloXXXwld", 'X'},
		FtStrchrTestParams{"", 'X'},
		FtStrchrTestParams{"XXX", 'X'}
		)
	);
