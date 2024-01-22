/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:42:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/22 17:43:18 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else
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
}

t_list	*target_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = stack_a;
	temp_b = stack_b;
	while ((temp_b->content > temp_a->content) && temp_a)
	{
		if (temp_a == ft_lstlast(temp_a))
			return (temp_a);
		temp_a = temp_a->next;
	}
	return (temp_a);
}

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

int	case_rb(t_list *stack_b)
{
	int	i;

	i = get_min_cost(stack_b)->index;
	return (i);
}

int	case_rrb(t_list *stack_b)
{
	int	i;

	i = get_min_cost(stack_b)->index;
	return (i);
}

int	case_ra(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = target_node(stack_a, get_min_cost(stack_b))->index;
	return (i);
}

int	case_rra(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = target_node(stack_a, get_min_cost(stack_b))->index;
	return (i);
}

void	apply_ra(t_list **stack_a, int i)
{
	while (i--)
		ra(stack_a);
}

void	apply_rb(t_list **stack_b, int i)
{
	while (i--)
		rb(stack_b);
}

void	apply_rra(t_list **stack_a, int i)
{
	while (i--)
		rra(stack_a);
}

void	apply_rrb(t_list **stack_b, int i)
{
	while (i--)
		rrb(stack_b);
}

void	apply_rr(t_list **stack_a, t_list **stack_b, int i)
{
	while (i--)
		rr(stack_a, stack_b);
}

void	apply_rrr(t_list **stack_a, t_list **stack_b, int i)
{
	while (i--)
		rrr(stack_a, stack_b);
}
