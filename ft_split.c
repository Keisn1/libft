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

void	free_strs(char **strs);

int	is_sep(char c, char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

char	*advance_until_sep(char *str, char *charset)
{
	while (*str && !is_sep(*str, charset))
		str++;
	return (str);
}

char	*advance_after_sep(char *str, char *charset)
{
	str = advance_until_sep(str, charset);
	while (*str && is_sep(*str, charset))
		str++;
	return (str);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	if (!*str)
		return (0);
	if (!is_sep(*str, charset))
		count++;
	str = advance_after_sep(str, charset);
	while (*str && is_sep(*str, charset))
		str++;
	while (*str)
	{
		count++;
		str = advance_after_sep(str, charset);
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	char	*end_word;
	int		nbr_of_words;
	int		idx;
	int		count;

	nbr_of_words = count_words(str, charset);
	strs = (char **)malloc((nbr_of_words + 1) * sizeof(char *));
	while (*str && is_sep(*str, charset))
		str++;
	count = 0;
	while (count < nbr_of_words)
	{
		end_word = advance_until_sep(str, charset);
		strs[count] = (char *)malloc(((end_word - str) + 1) * sizeof(char));
		if (strs[count] == NULL)
			return (NULL);
		idx = 0;
		while (str != end_word)
			strs[count][idx++] = *str++;
		strs[count++][idx] = '\0';
		str = advance_after_sep(str, charset);
	}
	strs[count] = NULL;
	return (strs);
}
