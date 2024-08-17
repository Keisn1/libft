#include <cstddef>
#include <gtest/gtest.h>
#include <string.h>
#include "libft.h"

struct FtMemchrTestParams {
	const void *s;
	int c;
	size_t n;
};

class FtMemchrTest : public ::testing::TestWithParam<FtMemchrTestParams>{};

TEST_P(FtMemchrTest, HandleVariousInputs) {
	FtMemchrTestParams params = GetParam();
	const void* got = ft_memchr(params.s, params.c, params.n);
	const void* want = memchr(params.s, params.c, params.n);
	EXPECT_EQ(got, want);
}

INSTANTIATE_TEST_SUITE_P(
	FtMemchrTests,
	FtMemchrTest,
	::testing::Values(
		FtMemchrTestParams{"bonjour", 'b', 4}
		)
	);
