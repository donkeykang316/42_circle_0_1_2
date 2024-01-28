/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:42:04 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:36:01 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	apply_index_1(t_list *stack, int i, int median, int temp)
{
	while (median--)
	{
		stack->index = i;
		stack->m_po = 1;
		i++;
		stack = stack->next;
	}
	while (temp)
	{
		stack->index = temp;
		stack->m_po = 2;
		temp--;
		stack = stack->next;
	}
}

void	apply_index_2(t_list *stack, int i, int median)
{
	median = ft_lstsize(stack);
	while (median--)
	{
		stack->index = i;
		stack->m_po = 0;
		i++;
		stack = stack->next;
	}
}

void	index_init(t_list *stack)
{
	int	i;
	int	median;
	int	temp;

	i = 0;
	if (ft_lstsize(stack) > 3)
	{
		median = ft_lstsize(stack) / 2;
		if (ft_lstsize(stack) % 2 != 0)
			temp = median + 1;
		else
			temp = median;
		apply_index_1(stack, i, median, temp);
	}
	else
	{
		median = ft_lstsize(stack);
		apply_index_2(stack, i, median);
	}
}

t_list	*target_node_else(t_list *stack_b, t_list *temp, t_list *first)
{
	while (first->content > stack_b->content
		|| temp->content < stack_b->content)
	{
		first = first->next;
		temp = first->next;
	}
	return (temp);
}

t_list	*target_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*first;
	t_list	*last;
	t_list	*max;
	t_list	*min;
	t_list	*temp;

	first = stack_a;
	last = ft_lstlast(stack_a);
	max = get_max(stack_a);
	min = get_min(stack_a);
	if (stack_b->content < first->content && stack_b->content > last->content)
		return (first);
	else if (stack_b->content > max->content || stack_b->content < min->content)
		return (min);
	else
	{
		temp = stack_a->next;
		return (target_node_else(stack_b, temp, first));
	}
	return (NULL);
}
