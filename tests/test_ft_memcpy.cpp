#include <string.h>
#include <gtest/gtest.h>
#include "libft.h"

struct FtMemcpyTestParam {
	const void* src;
	size_t n;
};

class FtMemcpyTest : public ::testing::TestWithParam<FtMemcpyTestParam> {};

TEST_P(FtMemcpyTest, HandlesVariousinputs) {

    FtMemcpyTestParam param = GetParam();
    char got[100], want[100];

    // Test regular memcpy with non-null inputs
    ft_memcpy(got, param.src, param.n);
    memcpy(want, param.src, param.n);
    EXPECT_EQ(memcmp(got, want, param.n), 0);

    // Test behavior for null pointers
    char death_ptr[100];
    EXPECT_DEATH({
			ft_memcpy(nullptr, death_ptr, param.n); // This should cause a segmentation fault
		}, "");

    EXPECT_DEATH({
			ft_memcpy(death_ptr, nullptr, param.n); // This should cause a segmentation fault
		}, "");

    EXPECT_EQ(ft_memcpy(nullptr, nullptr, param.n), nullptr);
}

INSTANTIATE_TEST_SUITE_P(
    FtMemcpyTests,
    FtMemcpyTest,
    ::testing::Values(
        // Non-overlapping
        FtMemcpyTestParam{"hello world", 5},
        // Additional tests can be added to ensure comprehensive coverage
        FtMemcpyTestParam{"test case", 9}, // Exact size
        FtMemcpyTestParam{"complex string with more characters", 29}
		)
	);
