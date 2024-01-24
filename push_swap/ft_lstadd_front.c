/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:17:25 by kaan              #+#    #+#             */
/*   Updated: 2024/01/24 21:25:46 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
