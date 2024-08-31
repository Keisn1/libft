#include "libft.h"
#include <cstdio>
#include <gtest/gtest.h>


t_list *create_list_2(int length) {
	if (length <= 0) {
		return NULL;
	}
	t_list *lst = new t_list{.content = (void*)1, .next = nullptr};
	t_list *head = lst;
	while (length > 1) {
		head->next = new t_list{.content = (void*)1, .next = nullptr};
		head = head->next;
		length--;
	}

	const char* last = "last";
	head->content = (void*)last;
	return lst;
}

void clear_list_2(t_list *lst) {
    while (lst) {
        t_list *tmp = lst;
        lst = lst->next;
		delete tmp;
	}
}

struct FtLstaddBackParams {
	t_list* lst;
	t_list* new_node;
};


class FtLstaddBackTest : public testing::TestWithParam<FtLstaddBackParams> {};


TEST_P(FtLstaddBackTest, HandleVariousInputs) {
	FtLstaddBackParams params = GetParam();
	t_list *lst = params.lst;
	t_list *new_node = params.new_node;
	ft_lstadd_back(&lst, new_node);

	t_list *head = lst;
	while (head->next) {
		head = head->next;
	}
	EXPECT_STREQ((char*)(head->content), "new");
	clear_list_2(lst);
}

INSTANTIATE_TEST_SUITE_P(
    FtLstaddBackTests,
	FtLstaddBackTest,
	::testing::Values(
		// FtLstlastParams{create_list_last_element_eq_length(0)},
		// FtLstlastParams{create_list_last_element_eq_length(1)},
		// FtLstlastParams{create_list_last_element_eq_length(5)},
		FtLstaddBackParams{create_list_2(0), new t_list{.content = (void *)"new", .next=nullptr}},
		FtLstaddBackParams{create_list_2(1), new t_list{.content = (void *)"new", .next=nullptr}},
		FtLstaddBackParams{create_list_2(3), new t_list{.content = (void *)"new", .next=nullptr}}
		)
	);
