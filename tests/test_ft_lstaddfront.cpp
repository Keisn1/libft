#include <gtest/gtest.h>
#include "libft.h"

struct FtLstaddFrontParams {
};

class FtLstaddFrontTest : public ::testing::TestWithParam<FtLstaddFrontParams> {};

TEST_P(FtLstaddFrontTest, HandlesVariousContents) {
	// FtLstaddFrontParams params = GetParam();

	t_list *n = ft_lstnew(NULL);

	ft_lstadd_front(&n, ft_lstnew(NULL));
	EXPECT_EQ(n->next, (void*)0);
	EXPECT_EQ(n->content, (void*)0);
	free(n);
}

INSTANTIATE_TEST_SUITE_P(FtLstaddFrontTests, FtLstaddFrontTest,
                         ::testing::Values(
							 FtLstaddFrontParams{}
							 )
	);
