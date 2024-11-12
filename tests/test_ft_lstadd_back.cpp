#include "test_libft.hpp"

struct FtLstaddBackParams {
	std::vector<int> lst_entries;
};

class FtLstaddBackTest : public testing::TestWithParam<FtLstaddBackParams> {};

TEST_P(FtLstaddBackTest, HandleVariousInputs) {
	FtLstaddBackParams params = GetParam();

	std::vector<int> lst_entries = params.lst_entries;
	t_list* lst = NULL;
	for (int i = 0; i < lst_entries.size() ; i++ ) {
		ft_lstadd_back(&lst, ft_lstnew(&lst_entries[i]));
    }

	t_list* head = lst;
	int i = 0;
	while (head) {
		EXPECT_EQ(lst_entries[i++], *(int*)(head->content));
		head = head->next;
	}

	head = lst;
	while (head) {
		lst = head;
		head = head->next;
		free(lst);
	}
}

INSTANTIATE_TEST_SUITE_P(
    FtLstaddBackTests,
	FtLstaddBackTest,
	::testing::Values(
		FtLstaddBackParams{{1, 2, 3}},
		FtLstaddBackParams{{}}
		)
	);
