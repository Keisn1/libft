#include "test_libft.hpp"

struct FtLstnewParams {
	void* content;
};

class FtLstnewTest : public ::testing::TestWithParam<FtLstnewParams> {};

TEST_P(FtLstnewTest, HandlesVariousContents) {
	FtLstnewParams params = GetParam();

	t_list *n = ft_lstnew(params.content);
	EXPECT_EQ(n->next, (void*)0);
	EXPECT_EQ(n->content, params.content);
	free(n);
}

INSTANTIATE_TEST_SUITE_P(FtLstnewTests, FtLstnewTest,
                         ::testing::Values(
							 FtLstnewParams{(void*)0},
							 FtLstnewParams{(void*)"Hello"}
							 )
	);
