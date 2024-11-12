#include "test_libft.hpp"

struct FtItoaTestParam {
	int n;
	const char* want;
};

class FtItoaTest : public ::testing::TestWithParam<FtItoaTestParam> {};

TEST_P(FtItoaTest, HandleVariousInputs) {
	FtItoaTestParam param = GetParam();
	char* got = ft_itoa(param.n);
	EXPECT_STREQ(param.want, got);
	free(got);
}

INSTANTIATE_TEST_SUITE_P(FtItoaTests, FtItoaTest,
                         ::testing::Values(
							 FtItoaTestParam{42, "42"},
                                           FtItoaTestParam{-1, "-1"},
                                           FtItoaTestParam{-42, "-42"},
                                           FtItoaTestParam{-2147483648, "-2147483648"},
                                           FtItoaTestParam{-8976, "-8976"},
                                           FtItoaTestParam{-10, "-10"},
                                           FtItoaTestParam{24, "24"},
                                           FtItoaTestParam{497245, "497245"},
                                           FtItoaTestParam{1, "1"},
                                           FtItoaTestParam{0, "0"})
	);


// TEST(FtItoaTest, HandleVariousInputs) {
// 	EXPECT_STREQ("42", ft_itoa(42));

// 	char* res = ft_itoa(0);
// 	EXPECT_STREQ("0", res);
// 	free(res);
// 	res = ft_itoa(1);
// 	EXPECT_STREQ("1", res);
// 	free(res);
// }
