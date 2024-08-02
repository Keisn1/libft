#include "libft.h"
#include <gtest/gtest.h>

struct FtStrlcpyTestParam {
	const char* src;
	size_t dstsize;
};


class FtStrlcpyTest : public ::testing::TestWithParam<FtStrlcpyTestParam> {};

TEST_P(FtStrlcpyTest, HandlesVariousInputs) {
	FtStrlcpyTestParam param = GetParam();
	char got_buffer[100];
	char want_buffer[100];
	size_t got = ft_strlcpy(got_buffer, param.src, param.dstsize);
	size_t want = strlcpy(want_buffer, param.src, param.dstsize);
	EXPECT_EQ(got, want);
	if (param.dstsize > 0) {
		EXPECT_STREQ(got_buffer, want_buffer);
	}
}

INSTANTIATE_TEST_SUITE_P(
	FtStrlcpyTests,
	FtStrlcpyTest,
	::testing::Values(
		FtStrlcpyTestParam{"hello", 10},
		FtStrlcpyTestParam{"hello", 0},
		FtStrlcpyTestParam{"hello, world!", 5},
		FtStrlcpyTestParam{"", 10},
		FtStrlcpyTestParam{"abcd", 3}
		)
	);

