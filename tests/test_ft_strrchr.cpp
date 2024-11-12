#include "test_libft.hpp"

struct FtStrrchrTestParams {
	const char *s;
	int c;
};

class FtStrrchrTest : public ::testing::TestWithParam<FtStrrchrTestParams>{};

TEST_P(FtStrrchrTest, HandleVariousInputs) {
	FtStrrchrTestParams params = GetParam();
	const char* got = ft_strrchr(params.s, params.c);
	const char* want = strrchr(params.s, params.c);
	EXPECT_STREQ(got, want);
}

INSTANTIATE_TEST_SUITE_P(
	FtStrrchrTests,
	FtStrrchrTest,
	::testing::Values(
		FtStrrchrTestParams{"helloXworld", 'X'},
		FtStrrchrTestParams{"helloXXXwld", 'X'},
		FtStrrchrTestParams{"", 'X'},
		FtStrrchrTestParams{"XXX", 'X'}
		)
	);
