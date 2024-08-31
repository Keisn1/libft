#include "libft.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>


t_list *create_list(int length) {
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
	return lst;
}

void clear_list(t_list *lst) {
    while (lst) {
        t_list *tmp = lst;
        lst = lst->next;
		delete tmp;
	}
}

struct FtLstsizeParams {
	t_list* lst;
    int want;
};


class FtLstsizeTest : public testing::TestWithParam<FtLstsizeParams> {
public:
	~FtLstsizeTest() {
		FtLstsizeParams params = GetParam();
		clear_list(params.lst);
	}
};


TEST_P(FtLstsizeTest, HandleVariousInputs) {
	FtLstsizeParams params = GetParam();
	t_list *lst = params.lst;
	int got = ft_lstsize(lst);
	EXPECT_EQ(got, params.want);
}

INSTANTIATE_TEST_SUITE_P(
    FtLstsizeTests,
	FtLstsizeTest,
	::testing::Values(
		FtLstsizeParams{create_list(10), 10},
		FtLstsizeParams{create_list(1), 1},
		FtLstsizeParams{create_list(0), 0},
		FtLstsizeParams{create_list(3), 3}
		)
	);
