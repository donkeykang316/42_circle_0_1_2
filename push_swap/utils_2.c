/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:30:21 by kaan              #+#    #+#             */
/*   Updated: 2024/01/27 12:41:03 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotat(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = *stack;
	second = (*stack)->next;
	last = ft_lstlast(*stack);
	ft_lstadd_back(&second, first);
	if (second && second->next)
	{
		second->prev = NULL;
		first->prev = last;
		first->next = NULL;
		*stack = second;
	}
}

void	rev_rotat(t_list **stack)
{
	t_list	*last;
	t_list	*first;
	t_list	*second_last;

	first = *stack;
	last = ft_lstlast(*stack);
	second_last = last->prev;
	ft_lstadd_front(stack, last);
	(*stack)->next = first;
	second_last->next = NULL;
}

t_list	*get_max(t_list *stack)
{
	t_list	*max;
	t_list	*max_node;
	int		max_nbr;

	max = stack;
	max_node = stack;
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

t_list	*get_min(t_list *stack)
{
	t_list	*min;
	t_list	*min_node;
	int		min_nbr;

	min = stack;
	min_node = stack;
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

	max_node = get_max(*stack_a);
	if (*stack_a == max_node)
		ra(stack_a);
	else if ((*stack_a)->next == max_node)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}
