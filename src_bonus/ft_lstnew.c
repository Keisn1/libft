/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:07/50 by kfreyer           #+#    #+#             */
/*   Updated: 2024/08/20 18:07:50 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content) {
	t_list* new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return NULL;

	if (!content) {
	}
	new->content = NULL;
	new->next = NULL;
	return new;
}
