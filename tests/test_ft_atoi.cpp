#include "libft.h"
#include <gtest/gtest.h>

TEST(FtAtoiTest, ErrorInputs) {
    EXPECT_EQ(ft_atoi("-"), atoi("-"));
    EXPECT_EQ(ft_atoi("+"), atoi("-"));
    EXPECT_EQ(ft_atoi(" asdf "), atoi(" asdf "));
    EXPECT_EQ(ft_atoi("  "), atoi("  "));
    EXPECT_EQ(ft_atoi(""), atoi(""));
}

TEST(FtAtoiTest, HandlesSigns) {
    EXPECT_EQ(ft_atoi("-42"), atoi("-42"));
    EXPECT_EQ(ft_atoi("+42"), atoi("+42"));
}

TEST(FtAtoiTest, HandlesWhiteSpaces) {
    EXPECT_EQ(ft_atoi(" \t \r \n \v \f  42"), atoi(" \t \r \n \v \f  42"));
    EXPECT_EQ(ft_atoi(" \t \r \n \v \f  -42"), atoi(" \t \r \n \v \f  -42"));
}
