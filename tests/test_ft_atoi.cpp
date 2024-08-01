#include <gtest/gtest.h>
#include "libft.h"

TEST(AdditionTest, HandlesPositiveValues) {
    EXPECT_EQ(ft_atoi("  42adf"), 42);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
