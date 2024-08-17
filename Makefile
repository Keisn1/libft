##
#libft
#
#@file
#@version 0.1

#Compiler and flags
CC := cc
CXX := g++
CFLAGS := -Wall -Wextra -Werror

#Directories and extensions
OBJ_DIR := ./obj
BIN_DIR := ./bin
TESTS_DIR := ./tests
SRC_EXT := .c
OBJ_EXT := .o

#Source files
SRC_FILES := $(wildcard *.c)
OBJ_FILES := $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

#Library name
NAME := libft.a

# Executable names
.DEFAULT_GOAL := all

############ Rules ##################
#Mandatory targets
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^

# Compile C source files to object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

############ PHONY ##################
clean:
	rm -f $(OBJ_FILES) $(TEST_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

norminette:
	norminette -R CheckForbiddenSourceHeader -R CheckDefine

############ PRINTING ##################
#Phony targets
.PHONY: all clean fclean re bear test-fsanitize norminette

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
