#include <gtest/gtest.h>
#include "libft.h"

struct FtSubstrTestParam {
	const char* s;
	unsigned int start;
	size_t len;
	const char* want;
};

class FtSubstrTest : public ::testing::TestWithParam<FtSubstrTestParam> {};

TEST_P(FtSubstrTest, HandlesVariousInputs) {
	FtSubstrTestParam param = GetParam();
	char* got = ft_substr(param.s, param.start, param.len);

	EXPECT_STREQ(got, param.want);
	free(got);
}

INSTANTIATE_TEST_SUITE_P(
	FtSubstrTests,
	FtSubstrTest,
	::testing::Values(
		FtSubstrTestParam{"hola", 0, 18446744073709, "hola"},
		FtSubstrTestParam{"lorem ipsum dolor sit amet", 7, 10, "psum dolor"}
		)
	);
