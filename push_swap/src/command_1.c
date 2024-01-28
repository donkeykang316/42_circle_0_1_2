/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:33:41 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:31:18 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

void	ra(t_list **stack_a)
{
	rotat(stack_a);
	ft_printf("ra\n");
}
