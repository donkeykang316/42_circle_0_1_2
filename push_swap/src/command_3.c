/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:33:41 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:34:52 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotat(stack_a);
	rotat(stack_b);
	ft_printf("rr\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotat(stack_a);
	rev_rotat(stack_b);
	ft_printf("rrr\n");
}
