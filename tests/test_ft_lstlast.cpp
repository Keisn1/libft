#include "test_libft.hpp"

struct FtLstlastParams {
	std::vector<int> lst_entries;
};


class FtLstlastTest : public testing::TestWithParam<FtLstlastParams> {};

TEST_P(FtLstlastTest, HandleVariousInputs) {
	FtLstlastParams params = GetParam();

	std::vector<int> lst_entries = params.lst_entries;
	t_list* lst = NULL;
	for (int i = 0; i < lst_entries.size() ; i++ ) {
		ft_lstadd_back(&lst, ft_lstnew(&lst_entries[i]));
    }

	if (lst_entries.size()) {
		EXPECT_EQ(lst_entries[lst_entries.size() - 1], *(int*)ft_lstlast(lst)->content);
	} else {
		EXPECT_EQ(nullptr, ft_lstlast(lst));
	}

	t_list* head = lst;
	while (head) {
		lst = head;
		head = head->next;
		free(lst);
	}
}

INSTANTIATE_TEST_SUITE_P(
    FtLstlastTests,
	FtLstlastTest,
	::testing::Values(
		FtLstlastParams{{1, 2, 3}},
		FtLstlastParams{{}}
		)
	);
