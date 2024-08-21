#include <cstdio>
#include <cstdlib>
#include <gtest/gtest.h>
#include <tuple>
#include "libft.h"

struct FtLstaddFrontParams {
	t_list **lst;
	t_list *new_node;
};

class FtLstaddFrontTest : public testing::TestWithParam<std::tuple<t_list*, t_list*>> {
public:
	~FtLstaddFrontTest() {
		// Deallocate the t_list instances after the test
		delete std::get<0>(GetParam());
		delete std::get<1>(GetParam());
	}
};

INSTANTIATE_TEST_SUITE_P(
	FtLstaddFrontTests, FtLstaddFrontTest,
	::testing::Values(
		std::make_tuple(new t_list{.content = (void *)1, .next = nullptr},
						new t_list{.content = (void *)2, .next = nullptr}),
		std::make_tuple(new t_list{.content=(void*)3, .next=nullptr},
						new t_list{.content=(void*)4, .next=nullptr})
		)
	);

TEST_P(FtLstaddFrontTest, FtTestLstaddFront) {
	t_list* lst = std::get<0>(GetParam());
	t_list* newElem = std::get<1>(GetParam());
	t_list* old_lst = lst;

	ft_lstadd_front(&lst, newElem);

	EXPECT_EQ(lst, newElem);
	EXPECT_EQ(newElem->next, old_lst);
}
