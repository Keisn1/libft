#include <string.h>
#include <gtest/gtest.h>
#include "libft.h"


struct FtMemmoveTestParam {
	size_t offset_dest;
	size_t offset_src;
	size_t n;
	const char* initial_buffer;
};

class FtMemmoveTest : public ::testing::TestWithParam<FtMemmoveTestParam> {};

TEST_P(FtMemmoveTest, HandlesVariousinputs) {
	FtMemmoveTestParam param = GetParam();
	char got[100], want[100];

    strlcpy(got, param.initial_buffer, sizeof(got));
    strlcpy(want, param.initial_buffer, sizeof(want));


    ft_memmove(got + param.offset_dest, got + param.offset_src, param.n);
    memmove(want + param.offset_dest, want + param.offset_src, param.n);
	EXPECT_EQ(memcmp(got, want, param.n), 0);
}

INSTANTIATE_TEST_SUITE_P(
	FtMemmoveTests,
	FtMemmoveTest,
	::testing::Values(
		// Non-overlapping
		FtMemmoveTestParam{0, 5, 5, "hello world"},
		// Overlapping src < dst
		FtMemmoveTestParam{6, 0, 5, "hello world"},
		// Overlapping dst < src
		FtMemmoveTestParam{0, 6, 5, "hello world"}
		)
	);
