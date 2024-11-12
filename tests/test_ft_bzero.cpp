#include "test_libft.hpp"

struct FtBzeroTestParam {
	size_t size;
};

class FtBzeroTest : public ::testing::TestWithParam<FtBzeroTestParam> {};

TEST_P(FtBzeroTest, HandlesVariousinputs) {
	FtBzeroTestParam param = GetParam();
	char got[100];
	char want[100];

	ft_bzero(got, param.size);
	bzero(want, param.size);
	EXPECT_EQ(memcmp(got, want, param.size), 0);
}

INSTANTIATE_TEST_SUITE_P(
	FtBzeroTests,
	FtBzeroTest,
	::testing::Values(
		FtBzeroTestParam{0 },
		FtBzeroTestParam{ 5},
		FtBzeroTestParam{ 10}
		)
	);
