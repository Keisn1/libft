/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:53:44 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/31 21:45:13 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*advance_until_sep(char *str, char c)
{
	while (*str && (*str != c))
		str++;
	return (str);
}

char	*advance_after_sep(char *str, char c)
{
	str = advance_until_sep(str, c);
	while (*str && (*str == c))
		str++;
	return (str);
}

int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	if (!*str)
		return (0);
	if (*str != c)
		count++;
	str = advance_after_sep(str, c);
	while (*str && (*str == c))
		str++;
	while (*str)
	{
		count++;
		str = advance_after_sep(str, c);
	}
	return (count);
}

void	free_strs(char **strs, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
		free(strs[idx++]);
	free(strs);
}

char	*extract_string(char *str, char *end_word)
{
	char	*ret;
	size_t	idx;

	ret = (char *)malloc(((end_word - str) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	idx = 0;
	while (str != end_word)
		ret[idx++] = *str++;
	ret[idx] = '\0';
	return (ret);
}

char	**ft_split(char *str, char c)
{
	char	**strs;
	char	*end_word;
	int		nbr_of_words;
	int		count;

	nbr_of_words = count_words(str, c);
	strs = (char **)malloc((nbr_of_words + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	while (*str && *str == c)
		str++;
	count = 0;
	while (nbr_of_words-- > 0)
	{
		end_word = advance_until_sep(str, c);
		strs[count] = extract_string(str, end_word);
		if (strs[count] == NULL)
		{
			free_strs(strs, count);
			return (NULL);
		}
		count++;
		str = advance_after_sep(str, c);
	}
	strs[count] = NULL;
	return (strs);
}
