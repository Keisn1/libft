#include "test_libft.hpp"

struct FtStrtrimTestParam {
	const char* s1;
	const char* set;
	const char* want;
};

class FtStrtrimTest : public ::testing::TestWithParam<FtStrtrimTestParam> {};

TEST_P(FtStrtrimTest, HandleVariousInputs) {
	FtStrtrimTestParam param = GetParam();
	char* got = ft_strtrim(param.s1, param.set);
	EXPECT_STREQ(param.want, got);
	free(got);
}

INSTANTIATE_TEST_SUITE_P(FtItoaTests, FtStrtrimTest,
						 ::testing::Values(
							 FtStrtrimTestParam{"-*string-string-(-","-*(","string-string"},
							 FtStrtrimTestParam{"-*string string-(-","-*(","string string"},
							 FtStrtrimTestParam{"--string string---","-","string string"},
							 FtStrtrimTestParam{"  string string   ", " ", "string string"},
							 FtStrtrimTestParam{"  string   ", " ", "string"})
	);
