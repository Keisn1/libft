/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:15/17 by kfreyer           #+#    #+#             */
/*   Updated: 2024/11/11 12:15:17 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char const *nptr)
{
	int	res;
	int	sign;

	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += (*nptr - '0');
		nptr++;
	}
	return (sign * res);
}
