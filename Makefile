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

#Source files
SRC_FILES := ft_atoi.c \
  ft_bzero.c \
  ft_calloc.c \
  ft_isalnum.c \
  ft_isalpha.c \
  ft_isascii.c \
  ft_isdigit.c \
  ft_isprint.c \
  ft_itoa.c \
  ft_memchr.c \
  ft_memcmp.c \
  ft_memcpy.c \
  ft_memmove.c \
  ft_memset.c \
  ft_putchar_fd.c \
  ft_putendl_fd.c \
  ft_putnbr_fd.c \
  ft_putstr_fd.c \
  ft_split.c \
  ft_strchr.c \
  ft_strdup.c \
  ft_striteri.c \
  ft_strjoin.c \
  ft_strlcat.c \
  ft_strlcpy.c \
  ft_strlen.c \
  ft_strmapi.c \
  ft_strncmp.c \
  ft_strnstr.c \
  ft_strrchr.c \
  ft_strtrim.c \
  ft_substr.c \
  ft_tolower.c \
  ft_toupper.c

BONUS_SRC_FILES := ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \

OBJ_FILES := ft_atoi.o \
  ft_bzero.o \
  ft_calloc.o \
  ft_isalnum.o \
  ft_isalpha.o \
  ft_isascii.o \
  ft_isdigit.o \
  ft_isprint.o \
  ft_itoa.o \
  ft_memchr.o \
  ft_memcmp.o \
  ft_memcpy.o \
  ft_memmove.o \
  ft_memset.o \
  ft_putchar_fd.o \
  ft_putendl_fd.o \
  ft_putnbr_fd.o \
  ft_putstr_fd.o \
  ft_split.o \
  ft_strchr.o \
  ft_strdup.o \
  ft_striteri.o \
  ft_strjoin.o \
  ft_strlcat.o \
  ft_strlcpy.o \
  ft_strlen.o \
  ft_strmapi.o \
  ft_strncmp.o \
  ft_strnstr.o \
  ft_strrchr.o \
  ft_strtrim.o \
  ft_substr.o \
  ft_tolower.o \
  ft_toupper.o

BONUS_OBJ_FILES := ft_lstadd_back.o \
	ft_lstadd_front.o \
	ft_lstclear.o \
	ft_lstdelone.o \
	ft_lstiter.o \
	ft_lstlast.o \
	ft_lstmap.o \
	ft_lstnew.o \
	ft_lstsize.o \

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
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

norminette:
	norminette -R CheckForbiddenSourceHeader -R CheckDefine

############ PRINTING ##################
#Phony targets
.PHONY: all bonus clean fclean re bear  norminette print_bonus_objs print_srcs print_objs print_bonus_srcs

#Printing
print_srcs:
	@echo $(SRC_FILES)

print_objs:
	@echo $(OBJ_FILES)

print_bonus_srcs:
	@echo $(BONUS_SRC_FILES)

print_bonus_objs:
	@echo $(BONUS_OBJ_FILES)

#end
