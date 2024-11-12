#include "test_libft.hpp"

struct FtPutnbrfdTestParam {
	int nbr;
	const char* want;
};

class FtPutnbrfdTest : public ::testing::TestWithParam<FtPutnbrfdTestParam> {};

TEST_P(FtPutnbrfdTest, HandleVariousInputs) {
	FtPutnbrfdTestParam param = GetParam();

	FILE* temp_file = tmpfile(); // part of stdio
	if (temp_file == NULL) {
		perror("tmpfile");
		exit(1);
	}

	int fd = fileno(temp_file);
	if (fd == -1) {
		perror("fileno");
		fclose(temp_file);
		exit(1);
	}

	ft_putnbr_fd(param.nbr, fd);

	char buffer[256];
	fseek(temp_file, 0, SEEK_SET);
	fgets(buffer, sizeof(buffer), temp_file);
	fclose(temp_file);

	ASSERT_STREQ(buffer, param.want);
}

INSTANTIATE_TEST_SUITE_P(FtItoaTests, FtPutnbrfdTest,
						 ::testing::Values(
							 FtPutnbrfdTestParam{-1000, "-1000"},
							 FtPutnbrfdTestParam{10, "10"},
							 FtPutnbrfdTestParam{-10, "-10"},
							 FtPutnbrfdTestParam{1, "1"},
							 FtPutnbrfdTestParam{-1, "-1"},
							 FtPutnbrfdTestParam{INT_MIN, "-2147483648"},
							 FtPutnbrfdTestParam{INT_MIN+1, "-2147483647"},
							 FtPutnbrfdTestParam{INT_MAX, "2147483647"},
							 FtPutnbrfdTestParam{0, "0"},
							 FtPutnbrfdTestParam{42, "42"})
	);



// TEST_P(FtPutnbrfdTest, HandleVariousInputs) {
// 	FtPutnbrfdTestParam param = GetParam();
// 	char* got = ft_strtrim(param.s1, param.set);
// 	EXPECT_STREQ(param.want, got);
// 	free(got);
// }

