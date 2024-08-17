/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:15/37 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/31 21:57:50 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifdef __cplusplus
extern "C"
{
# endif
	int ft_tolower(int c);
	int ft_toupper(int c);
	int ft_isalpha(char c);
	int ft_isalnum(int c);
	int ft_isdigit(char c);
	int ft_isascii(int c);
	int ft_isprint(int c);
	size_t ft_strlen(const char *s);
	size_t ft_strlcpy(char *dst, const char *src, size_t size);
	size_t ft_strlcat(char *dst, const char *src, size_t size);
	int ft_strncmp(const char *s1, const char *s2, size_t n);
	char *ft_strnstr(const char *big, const char *little, size_t len);
	char *ft_strchr(const char *s, int c);
	char *ft_strrchr(const char *s, int c);
	int ft_atoi(const char *nptr);
	void ft_bzero(void *s, size_t n);
	void *ft_memset(void *s, int c, size_t n);
	void *ft_memchr(const void *s, int c, size_t n);
	void *ft_memcpy(void *dest, const void *src, size_t n);
	void *ft_memmove(void *dest, const void *src, size_t n);
	char *ft_substr(char const *s, unsigned int start, size_t len);
	char **ft_split(char *str, char *charset);
	void ft_putchar_fd(char c, int fd);
	void ft_putstr_fd(char *s, int fd);
	void ft_putendl_fd(char *s, int fd);
	void ft_putnbr_fd(int nb, int fd);
	char *ft_strdup(const char *s);
	void *ft_calloc(size_t nmemb, size_t size);
	char *ft_itoa(int n);
	char	*ft_strtrim(char const *s1, char const *set);
	char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
	void ft_striteri(char *s, void (*f)(unsigned int, char*));

	char *ft_get_empty_str(void);
	int	ft_abs(int x);
# ifdef __cplusplus
}
# endif

#endif // LIBFT_H
