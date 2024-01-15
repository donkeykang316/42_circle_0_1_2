/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:41:32 by kaan              #+#    #+#             */
/*   Updated: 2024/01/15 23:18:27 by kaan             ###   ########.fr       */
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
	t_list	*new;

	new = ft_lstnew((*node)->content);
	ft_lstadd_front(stack, new);
	if (*node && (*node)->next)
		*node = (*node)->next;
}

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	*stack = second;
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
