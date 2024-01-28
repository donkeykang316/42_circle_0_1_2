/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:33:41 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:34:44 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rb(t_list **stack_b)
{
	rotat(stack_b);
	ft_printf("rb\n");
}

void	rra(t_list **stack_a)
{
	rev_rotat(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rev_rotat(stack_b);
	ft_printf("rrb\n");
}
