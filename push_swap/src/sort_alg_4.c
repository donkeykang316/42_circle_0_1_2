/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:21:36 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:36:20 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	apply_rrr(t_list **stack_a, t_list **stack_b, int i)
{
	while (i--)
		rrr(stack_a, stack_b);
}

void	do_rarb(t_list **stack_a, t_list **stack_b, int ra_i, int rb_i)
{
	if (ra_i == rb_i)
		apply_rr(stack_a, stack_b, ra_i);
	else
	{
		apply_ra(stack_a, ra_i);
		apply_rb(stack_b, rb_i);
	}
	pa(stack_a, stack_b);
}

void	do_rrarb(t_list **stack_a, t_list **stack_b, int ra_i, int rb_i)
{
	apply_rra(stack_a, ra_i);
	apply_rb(stack_b, rb_i);
	pa(stack_a, stack_b);
}

void	do_rarrb(t_list **stack_a, t_list **stack_b, int ra_i, int rb_i)
{
	apply_ra(stack_a, ra_i);
	apply_rrb(stack_b, rb_i);
	pa(stack_a, stack_b);
}

void	do_rrarrb(t_list **stack_a, t_list **stack_b, int ra_i, int rb_i)
{
	if (ra_i == rb_i)
		apply_rrr(stack_a, stack_b, ra_i);
	else
	{
		apply_rra(stack_a, ra_i);
		apply_rrb(stack_b, rb_i);
	}
	pa(stack_a, stack_b);
}
