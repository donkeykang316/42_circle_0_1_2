/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:30:37 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:36:46 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_list **stack, t_list **node)
{
	t_list	*push_node;

	if (!node)
		return ;
	push_node = ft_lstnew((*node)->content);
	ft_lstadd_front(stack, push_node);
	if (ft_lstsize(*node) == 1)
		ft_free(node);
	else
	{
		*node = (*node)->next;
		free((*node)->prev);
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

void	ft_free(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->content = 0;
		free(*lst);
		*lst = tmp;
	}
}

int	error_check(char *nbr)
{
	if (!(*nbr == '+'
			|| *nbr == '-'
			|| (*nbr >= '0' && *nbr <= '9')))
		return (1);
	if ((*nbr == '+'
			|| *nbr == '-')
		&& !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (1);
	while (*++nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (1);
	}
	return (0);
}

int	error_dup_check(t_list *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->content == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}
