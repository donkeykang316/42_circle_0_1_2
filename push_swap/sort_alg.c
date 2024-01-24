/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:42:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/24 22:58:54 by kaan             ###   ########.fr       */
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
	t_list	*first;
	t_list	*last;
	t_list	*max;
	t_list	*min;

	first = stack_a;
	last = ft_lstlast(stack_a);
	max = get_max(stack_a);
	min = get_min(stack_a);
	if (stack_b->content > max->content)
		return (min);
	else if (stack_b->content < min->content)
		return (min);
	else
	{
		if (min == first)
		{
			ft_printf("1_error\n");
			while (min)
			{
				if (stack_b->content < min->content)
					return (min);
				min = min->next;
			}
			return (min);
		}
		else if (max == first)
		{
			ft_printf("2_error\n");
			while (min)
			{
				if (stack_b->content < min->content)
					return (min);
				min = min->prev;
			}
			return (min);
		}
		else if (min == last)
		{
			ft_printf("3_error\n");
			while (first)
			{
				if (stack_b->content < first->content)
					return (first);
				first = first->next;
			}
			return (first);
		}
		else if (min != last && max != first)
		{
			ft_printf("4_error\n");
			while (min && min != last)
			{
				if (stack_b->content < min->content)
					break ;
				min = min->next;
			}
			while (max && max != first)
			{
				if (max->content < stack_b->content)
					break ;
				max = max->prev;
			}
			ft_printf("b_s:%d\n", stack_b->content);
			ft_printf("min:%d\n", min->content);
			ft_printf("max:%d\n", max->content);
			if (min_diff(min, stack_b) < max_diff(max, stack_b))
				return (min);
			else
				return (max);
		}
	}
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
