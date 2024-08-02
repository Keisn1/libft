#include "gtest/gtest.h"
#include <cstddef>
#include <gtest/gtest.h>
#include "libft.h"
#include <bsd/string.h>

struct FtStrnstrTestParams {
	const char *big;
	const char *little;
	size_t len;
};

class FtStrnstrTest : public :: testing::TestWithParam<FtStrnstrTestParams>{};

TEST_P(FtStrnstrTest, HandleVariousInputs) {
	FtStrnstrTestParams params = GetParam();
	char* got = ft_strnstr(params.big, params.little, params.len);
	char* want = strnstr(params.big, params.little, params.len);
	EXPECT_STREQ(got, want);
}

INSTANTIATE_TEST_SUITE_P(
	FtStrnstrTests,
	FtStrnstrTest,
	::testing::Values(
		FtStrnstrTestParams{"OuterInnerString", "Inner", 20},
		FtStrnstrTestParams{"OuterInnerString", "", 20},
		FtStrnstrTestParams{"OuterInnerString", "notFound", 20},
		FtStrnstrTestParams{"", "notFound", 20}
		)
	);
