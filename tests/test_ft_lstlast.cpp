// #include "test_libft.hpp"


// t_list *create_list_last_element_eq_length(int length) {
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

// 	const char* last = "last";
// 	head->content = (void*)last;
// 	return lst;
// }

// void clear_list_3(t_list *lst) {
//     while (lst) {
//         t_list *tmp = lst;
//         lst = lst->next;
// 		delete tmp;
// 	}
// }

// struct FtLstlastParams {
// 	t_list* lst;
// };


// class FtLstlastTest : public testing::TestWithParam<FtLstlastParams> {
// public:
// 	~FtLstlastTest() {
// 		FtLstlastParams params = GetParam();
// 		clear_list_3(params.lst);
// 	}
// };


// TEST_P(FtLstlastTest, HandleVariousInputs) {
// 	FtLstlastParams params = GetParam();
// 	t_list *lst = params.lst;
// 	t_list *got = ft_lstlast(lst);
// 	if (lst) {
// 		EXPECT_STREQ((char*)(got->content), "last");
// 	} else {
// 		EXPECT_EQ(got, nullptr);
// 	}
// }

// INSTANTIATE_TEST_SUITE_P(
//     FtLstlastTests,
// 	FtLstlastTest,
// 	::testing::Values(
// 		FtLstlastParams{create_list_last_element_eq_length(0)},
// 		FtLstlastParams{create_list_last_element_eq_length(1)},
// 		FtLstlastParams{create_list_last_element_eq_length(5)},
// 		FtLstlastParams{create_list_last_element_eq_length(3)}
// 		)
// 	);
