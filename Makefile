##
#libft
#
#@file
#@version 0.1

#Compiler and flags
CC := cc
CXX := g++
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -Iincludes
CXXFLAGS := -Wall -Wextra
CXXFLAGS += -Iincludes
LDFLAGS := -lgtest -lgtest_main -pthread
BSD := -lbsd

# Test Flags
FSANITIZE = -fsanitize=address

#Directories and extensions
SRC_DIR = ./src
SRC_DIR_BONUS = ./src_bonus

OBJ_DIR := ./obj
BIN_DIR := ./bin
TESTS_DIR := ./tests

#Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
SRC_FILES_BONUS := $(wildcard $(SRC_DIR_BONUS)/*.c)

OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_FILES_BONUS := $(SRC_FILES_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR)/%.o)

TEST_FILES := $(wildcard $(TESTS_DIR)/*.cpp)
TEST_OBJ_FILES := $(TEST_FILES:$(TESTS_DIR)/%.cpp=$(OBJ_DIR)/%.o)

#Library name
NAME := $(BIN_DIR)/libft.a

# Executable names
TEST_TARGET := $(BIN_DIR)/run_tests
.DEFAULT_GOAL := all

############ Rules ##################
#Mandatory targets
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	ar rc $@ $^

bonus: $(OBJ_FILES_BONUS)
	ar r $(NAME) $^

# Compile C source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile C++ test files to object files
$(OBJ_DIR)/%.o: $(TESTS_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(BSD) $(LDFLAGS)

# Build the tests executable
$(TEST_TARGET)-FSANITIZE: $(OBJ_FILES) $(TEST_OBJ_FILES) $(OBJ_FILES_BONUS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(FSANITIZE) -o $@ $^ $(BSD)  $(LDFLAGS)

############ PHONY ##################
clean:
	rm -f $(OBJ_FILES) $(TEST_OBJ_FILES)

fclean: clean
	rm -f $(BIN_DIR)/*

re: fclean all

bear: $(OBJ_FILES) $(TEST_OBJ_FILES)

test-fsanitize: $(TEST_TARGET)-FSANITIZE
	- $(TEST_TARGET)-FSANITIZE
test:
	- cmake -S . -B build
	- cmake --build build
	- cd build && ctest -V

norminette:
	norminette -R CheckForbiddenSourceHeader -R CheckDefine src

############ PRINTING ##################
#Phony targets
.PHONY: all bonus clean fclean re bear test-fsanitize norminette

#Printing
print_srcs:
	@echo $(SRC_FILES)

print_srcs_bonus:
	@echo $(SRC_FILES_BONUS)

print_objs:
	@echo $(OBJ_FILES)

print_objs_bonus:
	@echo $(OBJ_FILES_BONUS)

print_test_files:
	@echo $(TEST_FILES)

print_test_objs:
	@echo $(TEST_OBJ_FILES)

print_test_target:
	@echo $(TEST_TARGET)
#end
