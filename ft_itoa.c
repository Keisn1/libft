/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:07/15 by kfreyer           #+#    #+#             */
/*   Updated: 2024/08/04 21:07:15 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int	get_length(int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_rev_char_tab(char *tab, int size)
{
	char	tmp;
	int		count;

	count = 0;
	while (count < size / 2)
	{
		tmp = tab[count];
		tab[count] = tab[size - count - 1];
		tab[size - count - 1] = tmp;
		count++;
	}
}

char	*ft_itoa(int n)
{
	int		sign;
	int		length;
	char	*ret;
	int		idx;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
		sign = 1;
	length = get_length(ft_abs(n));
	ret = (char *)malloc(sizeof(char) * (length + sign + 1));
	idx = 0;
	if (sign)
		ret[idx++] = '-';
	ret[idx++] = ft_abs(n) % 10 + '0';
	n = ft_abs(n) / 10;
	while (n > 0)
	{
		ret[idx++] = n % 10 + '0';
		n = n / 10;
	}
	ret[idx] = '\0';
	ft_rev_char_tab(ret + sign, length);
	return (ret);
}