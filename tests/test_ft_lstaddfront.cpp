#include "test_libft.hpp"
#include <gtest/gtest.h>

struct FtLstaddFrontParams {
	std::vector<int> lst_entries;
	std::vector<int> new_entries;
};

class FtLstaddFrontTest : public testing::TestWithParam<FtLstaddFrontParams> {};

INSTANTIATE_TEST_SUITE_P(
	FtLstaddFrontTests, FtLstaddFrontTest,
	::testing::Values(
		FtLstaddFrontParams{{1, 2, 3}, {4}},
		FtLstaddFrontParams{{1, 2, 3}, {4, 5}},
		FtLstaddFrontParams{{}, {4, 5}}
		)
	);


TEST_P(FtLstaddFrontTest, FtTestLstaddFront) {
	FtLstaddFrontParams params = GetParam();

	std::vector<int> lst_entries = params.lst_entries;
	t_list* lst = NULL;
	for (int i = 0; i < lst_entries.size() ; i++ ) {
		ft_lstadd_back(&lst, ft_lstnew(&lst_entries[i]));
    }

	std::vector<int> new_entries = params.new_entries;
	for (int i = 0; i < new_entries.size() ; i++ ) {
		ft_lstadd_front(&lst, ft_lstnew(&new_entries[i]));
		EXPECT_EQ(new_entries[i], *(int*)lst->content);
	}

	t_list* head = lst;
	while (head) {
		lst = head;
		head = head->next;
		free(lst);
	}
}
