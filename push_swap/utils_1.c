/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:41:32 by kaan              #+#    #+#             */
/*   Updated: 2024/01/24 22:23:05 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_check(t_list **stack)
{
	t_list	*count;

	count = *stack;
	while ((count)->next)
	{
		if (count->content <= count->next->content)
			count = count->next;
		else
			return (0);
	}
	return (1);
}

void	stacking(t_list **stack_a, int ac, char **av)
{
	t_list	*new;
	int		i;

	i = 1;
	if (ac >= 2)
	{
		new = NULL;
		while (av[i])
		{
			new = ft_lstnew(ft_atoi(av[i]));
			ft_lstadd_back(stack_a, new);
			i++;
		}
	}
}

void	push(t_list **stack, t_list **node)
{
	t_list	*push_node;

	push_node = ft_lstnew((*node)->content);
	ft_lstadd_front(stack, push_node);
	if (ft_lstsize(*node) == 1)
		*node = NULL;
	else
	{
		*node = (*node)->next;
		(*node)->prev = NULL;
	}
}

void	swap(t_list **stack)
{
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

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
