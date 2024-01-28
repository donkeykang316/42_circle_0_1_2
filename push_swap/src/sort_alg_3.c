/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:20:38 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:36:14 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
