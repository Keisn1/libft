##
#libft
#
#@file
#@version 0.1

#Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

#Directories and extensions
SRCS_DIR = ./src/
OBJS_DIR := ./obj/
EXE_DIR := ./bin/
SRC_EXT := .c
OBJ_EXT := .o

#Source files
SOURCE_FILES = 	ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_strlen.c 	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_strncmp.c	\
				ft_strnstr.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_atoi.c		\
				ft_bzero.c		\
				ft_memset.c		\
				ft_memchr.c		\
				ft_memcpy.c		\
				ft_memcmp.c		\
				ft_memmove.c	\
				ft_strdup.c		\
				ft_calloc.c		\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putnbr_fd.c	\
				ft_putendl_fd.c

SRCS := $(addprefix $(SRCS_DIR), $(SOURCE_FILES))
OBJS := $(addprefix $(OBJS_DIR), $(SOURCE_FILES:$(SRC_EXT)=$(OBJ_EXT)))

#Library name
NAME := $(EXE_DIR)libft.a
.DEFAULT_GOAL := all

#Create directories if they don't exist
$(OBJS_DIR):
	mkdir -p $@

$(EXE_DIR):
	mkdir -p $@


############ Rules ##################
#Mandatory targets
all: $(EXE_DIR) $(OBJS_DIR) $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%$(SRC_EXT)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	$(CC) $(CFLAGS) src/ft_atoi.c tests/test_ft_atoi.c tests/unity.c tests/test_runners/TestProductionCode_Runner.c -o test1
	- ./test1

tests/test_runners/TestProductionCode_Runner.c: tests/test_ft_atoi.c
	ruby tests/generate_test_runner.rb tests/test_ft_atoi.c  tests/test_runners/TestProductionCode_Runner.c

#Phony targets
.PHONY: all clean fclean re test

#Printing
print_srcs:
	@echo $(SRCS)

print_objs:
	@echo $(OBJS)

#end
