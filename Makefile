##
# libft
#
# @file
# @version 0.1

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS_DIR = ./
SOURCE_FILES = 	ft_isalpha.c	\
		ft_isalpha.c	\
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
		ft_strchr.c	\
		ft_strrchr.c	\
		ft_atoi.c	\
		ft_bzero.c	\
		ft_memset.c	\
		ft_memchr.c	\
		ft_memcpy.c	\
		ft_memcmp.c	\
		ft_memmove.c	\
		ft_strdup.c	\
		ft_calloc.c


SRCS = $(addprefix $(SRCS_DIR), $(SOURCE_FILES))
OBJS = $(SRCS:.c=.o)

NAME = libft.a
.DEFAULT_GOAL := all

############ Rules ##################
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
# end
