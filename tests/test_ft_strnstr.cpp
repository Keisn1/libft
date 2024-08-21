#include "gtest/gtest.h"
#include <cstddef>
#include <gtest/gtest.h>
#include "libft.h"
#include <bsd/string.h>


TEST(FtStrnstrDeathTest, HandleNullInputs) {
    EXPECT_DEATH(strnstr(NULL, NULL, 0), "");
    EXPECT_DEATH(ft_strnstr(NULL, NULL, 0), "");

	const char* death_str = "hello death";
    EXPECT_DEATH(strnstr(death_str, NULL, 0), "");
    EXPECT_DEATH(ft_strnstr(death_str, NULL, 0), "");

    EXPECT_EQ(strnstr(NULL, death_str, 0),  nullptr);
    EXPECT_EQ(ft_strnstr(NULL, death_str, 0),  nullptr);

    EXPECT_EQ(strnstr(NULL, "", 0),  nullptr);
    EXPECT_EQ(ft_strnstr(NULL, "", 0),  nullptr);
    // EXPECT_DEATH(ft_strnstr( NULL,death_str, 0), "");
}

struct FtStrnstrTestParams {
	const char *big;
	const char *little;
	size_t len;
};

class FtStrnstrTest : public :: testing::TestWithParam<FtStrnstrTestParams>{};

TEST_P(FtStrnstrTest, HandleVariousInputs) {
	FtStrnstrTestParams params = GetParam();
	char *got =  ft_strnstr(params.big, params.little, params.len);
	char* want = strnstr(params.big, params.little, params.len);
	EXPECT_STREQ(got, want);
}

INSTANTIATE_TEST_SUITE_P(
	FtStrnstrTests,
	FtStrnstrTest,
	::testing::Values(
		FtStrnstrTestParams{"lorem ipsum dolor sit amet", "dolor", 0},
		FtStrnstrTestParams{"", "", 0},
		FtStrnstrTestParams{"", "", 20},
		FtStrnstrTestParams{"OuterInnerString", "Inner", 20},
		FtStrnstrTestParams{"OuterInnerString", "", 20},
		FtStrnstrTestParams{"OuterInnerString", "notFound", 20},
		FtStrnstrTestParams{"", "notFound", 20}
		)
	);

