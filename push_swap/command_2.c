/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:33:41 by kaan              #+#    #+#             */
/*   Updated: 2024/01/14 13:54:38 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
