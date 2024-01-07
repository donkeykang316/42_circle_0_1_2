/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:30:21 by kaan              #+#    #+#             */
/*   Updated: 2024/01/07 15:01:59 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_max(t_list **stack)
{
	t_list	*max;
	t_list	*max_node;
	int		max_nbr;

	max = *stack;
	max_node = *stack;
	max_nbr = max->content;
	while (max)
	{
		if (max_nbr < max->content)
			max_nbr = max->content;
		max = max->next;
	}
	while (max_node)
	{
		if (max_node->content == max_nbr)
			return (max_node);
		else
			max_node = max_node->next;
	}
	return (0);
}

void	sort_thr(t_list **stack_a, t_list **stack_b)
{
	t_list	*max_node;

	(void)stack_b;
	max_node = get_max(stack_a);
	if (*stack_a == max_node)
		ra(stack_a);
}
