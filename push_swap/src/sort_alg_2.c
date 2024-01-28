/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:56:06 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:36:08 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_cost(t_list *stack_a, t_list *stack_b)
{
	while (stack_b)
	{
		stack_b->cost = stack_b->index + target_node(stack_a, stack_b)->index;
		stack_b = stack_b->next;
	}
}

t_list	*get_min_cost(t_list *stack)
{
	t_list	*min;
	t_list	*min_node;
	int		min_cost;

	min = stack;
	min_node = stack;
	min_cost = min->cost;
	while (min)
	{
		if (min_cost > min->cost)
			min_cost = min->cost;
		min = min->next;
	}
	while (min_node)
	{
		if (min_node->cost == min_cost)
			return (min_node);
		else
			min_node = min_node->next;
	}
	return (0);
}

void	stack_init(t_list *stack_a, t_list *stack_b)
{
	index_init(stack_a);
	index_init(stack_b);
	push_cost(stack_a, stack_b);
}

int	case_br(t_list *stack_b)
{
	int	i;

	i = get_min_cost(stack_b)->index;
	return (i);
}

int	case_ar(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = target_node(stack_a, get_min_cost(stack_b))->index;
	return (i);
}
