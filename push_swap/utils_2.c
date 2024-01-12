/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:30:21 by kaan              #+#    #+#             */
/*   Updated: 2024/01/12 17:48:05 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotat(t_list **stack)
{
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		last = ft_lstlast(*stack);
		last->prev->next = NULL;
		last->next = *stack;
		last->prev = NULL;
		*stack = last;
		last->next->prev = last;
	}
}

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

t_list	*get_min(t_list **stack)
{
	t_list	*min;
	t_list	*min_node;
	int		min_nbr;

	min = *stack;
	min_node = *stack;
	min_nbr = min->content;
	while (min)
	{
		if (min_nbr > min->content)
			min_nbr = min->content;
		min = min->next;
	}
	while (min_node)
	{
		if (min_node->content == min_nbr)
			return (min_node);
		else
			min_node = min_node->next;
	}
	return (0);
}

void	sort_thr(t_list **stack_a)
{
	t_list	*max_node;

	max_node = get_max(stack_a);
	if (*stack_a == max_node)
		ra(stack_a);
	else if ((*stack_a)->next == max_node)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}
