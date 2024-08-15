#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include "libft.h"

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

INSTANTIATE_TEST_SUITE_P(
    FtStrmapiTests,
	FtStrmapiTest,
	::testing::Values(
		FtStrmapiTestParams{"123", NULL, "123"}
	)
);
