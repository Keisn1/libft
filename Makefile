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
BIN_DIR := ./bin
TESTS_DIR := ./tests

#Source files
#
C_FILES := $(wildcard *.c)
BONUS_SRC_FILES := ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \

SRC_FILES := $(filter-out $(BONUS_SRC_FILES), $(C_FILES))

OBJ_FILES := $(SRC_FILES:%.c=%.o)
BONUS_OBJ_FILES := $(BONUS_SRC_FILES:%.c=%.o)

#Library name
NAME := libft.a

# Executable names
.DEFAULT_GOAL := all

############ Rules ##################
#Mandatory targets
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^

bonus: $(BONUS_OBJ_FILES)
	ar r $(NAME) $^

# Compile C source files to object files
$%.o: %.c
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
.PHONY: all bonus clean fclean re bear test-fsanitize norminette print_bonus_objs print_srcs print_objs print_bonus_srcs

#Printing
print_srcs:
	@echo $(SRC_FILES)

print_objs:
	@echo $(OBJ_FILES)

print_bonus_srcs:
	@echo $(BONUS_SRC_FILES)

print_bonus_objs:
	@echo $(BONUS_OBJ_FILES)

print_test_files:
	@echo $(TEST_FILES)

print_test_objs:
	@echo $(TEST_OBJ_FILES)

print_test_target:
	@echo $(TEST_TARGET)
#end
