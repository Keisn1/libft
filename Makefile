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
CXXFLAGS := -Wall -Wextra -std=c++14
CXXFLAGS += -Iincludes
LDFLAGS := -lgtest -lgtest_main -pthread
BSD := -lbsd

# Debug
DEBUG = -g

# Test Flags
FSANITIZE = -fsanitize=address
# VALGRIND = valgrind
# VALGRIND_FLAGS = --leak-check=full

#Directories and extensions
SRC_DIR = ./src
OBJ_DIR := ./obj
BIN_DIR := ./bin
TESTS_DIR := ./tests
SRC_EXT := .c
OBJ_EXT := .o

#Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
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

# Compile C source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile C++ test files to object files
$(OBJ_DIR)/%.o: $(TESTS_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the tests executable
$(TEST_TARGET)-FSANITIZE: $(OBJ_FILES) $(TEST_OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(FSANITIZE) -o $@ $^ $(LDFLAGS) $(BSD)

# $(TEST_TARGET)-VALGRIND: CFLAGS += $(DEBUG)
# $(TEST_TARGET)-VALGRIND: $(OBJ_FILES) $(TEST_OBJ_FILES)
# 	$(CXX) -o $@ $^ $(LDFLAGS) $(BSD)

############ PHONY ##################
clean:
	rm -f $(OBJ_FILES) $(TEST_OBJ_FILES)

fclean: clean
	rm -f $(BIN_DIR)/*

re: fclean all

bear: $(OBJ_FILES) $(TEST_OBJ_FILES)

test-fsanitize: $(TEST_TARGET)-FSANITIZE
	- $(TEST_TARGET)-FSANITIZE

# test-valgrind: $(TEST_TARGET)-VALGRIND
# 	$(VALGRIND) $(VALGRIND_FLAGS) $(TEST_TARGET)-VALGRIND

############ PRINTING ##################
#Phony targets
.PHONY: all clean fclean re bear test-fsanitize

#Printing
print_srcs:
	@echo $(SRC_FILES)

print_objs:
	@echo $(OBJ_FILES)

print_test_files:
	@echo $(TEST_FILES)

print_test_objs:
	@echo $(TEST_OBJ_FILES)

print_test_target:
	@echo $(TEST_TARGET)
#end
