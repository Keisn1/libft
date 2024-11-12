#include "test_libft.hpp"


// t_list *create_list(int length) {
// 	if (length <= 0) {
// 		return NULL;
// 	}
// 	t_list *lst = new t_list{.content = (void*)1, .next = nullptr};
// 	t_list *head = lst;
// 	while (length > 1) {
// 		head->next = new t_list{.content = (void*)1, .next = nullptr};
// 		head = head->next;
// 		length--;
// 	}
// 	return lst;
// }

// void clear_list(t_list *lst) {
//     while (lst) {
//         t_list *tmp = lst;
//         lst = lst->next;
// 		delete tmp;
// 	}
// }

struct FtLstsizeParams {
	std::vector<int> lst_entries;
	int want;
};


class FtLstsizeTest : public testing::TestWithParam<FtLstsizeParams> {};


TEST_P(FtLstsizeTest, HandleVariousInputs) {
	FtLstsizeParams params = GetParam();

	std::vector<int> lst_entries = params.lst_entries;

	t_list* lst = NULL;
	for (int i = 0; i < lst_entries.size() ; i++ ) {
		ft_lstadd_back(&lst, ft_lstnew(&lst_entries[i]));
    }

	int got = ft_lstsize(lst);
	EXPECT_EQ(got, params.want);

	t_list* head = lst;
	while (head) {
		lst = head;
		head = head->next;
		free(lst);
	}
}

INSTANTIATE_TEST_SUITE_P(
    FtLstsizeTests,
	FtLstsizeTest,
	::testing::Values(
		FtLstsizeParams{{}, 0},
		FtLstsizeParams{{1, 2, 3}, 3},
		FtLstsizeParams{{1, 2, 3, 4, 5}, 5}
		)
	);
