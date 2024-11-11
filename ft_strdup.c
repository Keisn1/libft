/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:13/52 by kfreyer           #+#    #+#             */
/*   Updated: 2024/11/11 12:13:52 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char	*res_o;
	char	*res;
	int		len;

	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (res == (void *)0)
	{
		return (res);
	}
	res_o = res;
	while (*s)
		*res++ = *s++;
	*res = '\0';
	return (res_o);
}
