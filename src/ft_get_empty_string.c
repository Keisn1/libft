/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_empty_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:22/24 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/31 19:22:24 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_get_empty_str(void)
{
	char	*empty_str;

	empty_str = (char *)malloc(sizeof(char));
	if (!empty_str)
		return (NULL);
	*empty_str = '\0';
	return (empty_str);
}
