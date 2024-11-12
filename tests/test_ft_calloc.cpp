#include "test_libft.hpp"

TEST(FtCallocTest, ZeroInitialisation) {
	size_t nmemb = 10;
	size_t size = sizeof(int);
	int* ptr = (int*)ft_calloc(nmemb, size);
	for (size_t i = 0; i < nmemb; ++i) {
        EXPECT_EQ(ptr[i], 0);
	}

	free(ptr);
}

TEST(FtCallocTest, CorrectSize) {
	size_t nmemb = 10;
	size_t size = sizeof(int);
	int* ptr = (int*)ft_calloc(nmemb, size);
	for (size_t i = 0; i < nmemb; ++i) {
		ptr[i] = i * 2;
	}

	// Verify the values
	for (size_t i = 0; i < nmemb; ++i) {
		EXPECT_EQ(ptr[i], i*2);
	}

	free(ptr);
}
