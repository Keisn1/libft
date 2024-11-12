#include "test_libft.hpp"

struct FtStrlcatTestParam {
	const char* dst;
	const char* src;
	size_t dstsize;
};

class FtStrlcatTest : public ::testing::TestWithParam<FtStrlcatTestParam> {};

TEST_P(FtStrlcatTest, HandlesVariousInputs) {
	FtStrlcatTestParam param = GetParam();
	char got_buffer[100];
	char want_buffer[100];
	strlcpy(got_buffer, param.dst, sizeof(got_buffer));
	strlcpy(want_buffer, param.dst, sizeof(want_buffer));

	size_t got = ft_strlcat(got_buffer, param.src, param.dstsize);
	size_t want = ft_strlcat(want_buffer, param.src, param.dstsize);
	EXPECT_EQ(got, want);
	if (param.dstsize > 0) {
		EXPECT_STREQ(got_buffer, want_buffer);
	}
}

INSTANTIATE_TEST_SUITE_P(
	FtStrlcatTests,
	FtStrlcatTest,
	::testing::Values(
		FtStrlcatTestParam{"string1", "string2", 10},
		FtStrlcatTestParam{"string1", "string2", 5},
		FtStrlcatTestParam{"", "string2", 10},
		FtStrlcatTestParam{"string1", "", 10},
		FtStrlcatTestParam{"string1", "", 3}
		)
	);
