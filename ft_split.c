/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:14/04 by kfreyer           #+#    #+#             */
/*   Updated: 2024/11/11 12:14:04 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*jump_sep(char const *str, char sep)
{
	while (*str && *str == sep)
		str++;
	return (str);
}

static const char	*jump_non_sep(char const *str, char sep)
{
	while (*str && (*str != sep))
		str++;
	return (str);
}

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	if (!*str)
		return (0);
	if (*str != c)
		count++;
	str = jump_non_sep(str, c);
	str = jump_sep(str, c);
	while (*str && (*str == c))
		str++;
	while (*str)
	{
		count++;
		str = jump_non_sep(str, c);
		str = jump_sep(str, c);
	}
	return (count);
}

static char	*extract_string(char const *str, char const *end_word, char **strs,
		size_t count)
{
	size_t	idx;

	strs[count] = (char *)malloc(((end_word - str) + 1) * sizeof(char));
	if (strs[count] == NULL)
	{
		idx = 0;
		while (idx < count)
			free(strs[idx++]);
		free(strs);
		return (NULL);
	}
	idx = 0;
	while (str != end_word)
		strs[count][idx++] = *str++;
	strs[count][idx] = '\0';
	return (strs[count]);
}

char	**ft_split(char const *str, char c)
{
	char		**strs;
	char const	*end_word;
	int			nbr_of_words;
	size_t		count;

	nbr_of_words = count_words(str, c);
	strs = (char **)malloc((nbr_of_words + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	str = jump_sep(str, c);
	count = 0;
	while (nbr_of_words-- > 0)
	{
		end_word = jump_non_sep(str, c);
		if (extract_string(str, end_word, strs, count) == NULL)
			return (NULL);
		str = jump_non_sep(str, c);
		str = jump_sep(str, c);
		count++;
	}
	strs[count] = NULL;
	return (strs);
}
