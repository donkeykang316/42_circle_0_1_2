/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:17:25 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:35:18 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*first;

	first = *lst;
	if (lst)
	{
		if (first)
		{
			new->next = first;
			first->prev = new;
		}
		new->prev = NULL;
		*lst = new;
	}
}
