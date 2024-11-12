#include "test_libft.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    // ::testing::GTEST_FLAG(filter) = "FtLstaddBackTests/FtLstaddBackTest*";
    // ::testing::GTEST_FLAG(filter) = "FtLstaddFrontTest*";

    return RUN_ALL_TESTS();
}
