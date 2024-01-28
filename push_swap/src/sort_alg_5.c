/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:37:41 by kaan              #+#    #+#             */
/*   Updated: 2024/01/28 12:36:25 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_b;
	t_list	*target_a;
	int		rb_i;
	int		ra_i;

	stack_init(*stack_a, *stack_b);
	rb_i = case_br(*stack_b);
	ra_i = case_ar(*stack_a, *stack_b);
	min_b = get_min_cost(*stack_b);
	target_a = target_node(*stack_a, min_b);
	if ((min_b->m_po == 0 && target_a->m_po == 0)
		|| (min_b->m_po == 0 && target_a->m_po == 1)
		|| (min_b->m_po == 1 && target_a->m_po == 0)
		|| (min_b->m_po == 1 && target_a->m_po == 1))
		do_rarb(stack_a, stack_b, ra_i, rb_i);
	else if ((min_b->m_po == 0 && target_a->m_po == 2)
		|| (min_b->m_po == 1 && target_a->m_po == 2))
		do_rrarb(stack_a, stack_b, ra_i, rb_i);
	else if ((min_b->m_po == 2 && target_a->m_po == 0)
		|| (min_b->m_po == 2 && target_a->m_po == 1))
		do_rarrb(stack_a, stack_b, ra_i, rb_i);
	else if (min_b->m_po == 2 && target_a->m_po == 2)
		do_rrarrb(stack_a, stack_b, ra_i, rb_i);
}

void	push_b_thr_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && order_check(*stack_a) == 0)
		pb(stack_b, stack_a);
	if (order_check(*stack_a) == 0)
		sort_thr(stack_a);
	while (*stack_b)
		stack_check(stack_a, stack_b);
	index_init(*stack_a);
	if (get_min(*stack_a)->m_po == 1)
		apply_ra(stack_a, get_min(*stack_a)->index);
	else
		apply_rra(stack_a, get_min(*stack_a)->index);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3 && order_check(*stack_a) == 0)
		push_b_thr_a(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_thr(stack_a);
}
