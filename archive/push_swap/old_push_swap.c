/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/14 15:03:08 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_start_to_node(t_list *stack, int content)
{
	int		i;

	i = 0;
	while (stack->content != content)
	{
		stack = stack->next;
		i++;
	}
	stack->index = 0;
	return (i);
}

int	index_node_to_last(t_list *stack, int content)
{
	int		i;

	i = index_start_to_node(stack, content);
	i = ft_lstsize(stack) - i;
	return (i);
}

int	case_ra(t_list **stack_a)
{
	int		i;

	i = 1;
	i = index_start_to_node(*stack_a, get_min(stack_a)->content);
	return (i);
}

int	case_rra(t_list **stack_a)
{
	int	i;

	i = index_node_to_last(*stack_a, get_min(stack_a)->content);
	return (i);
}

void	apply_ra(t_list **stack_a)
{
	while ((*stack_a)->content != get_min(stack_a)->content)
		ra(stack_a);
}

void	apply_rra(t_list **stack_a)
{
	while ((*stack_a)->content != get_min(stack_a)->content)
		rra(stack_a);
}

void	stack_check(t_list **stack_a)
{
	int	ra_i;
	int	rra_i;

	ra_i = case_ra(stack_a);
	rra_i = case_rra(stack_a);
	if (ra_i < rra_i)
		apply_ra(stack_a);
	else if (ra_i >= rra_i)
		apply_rra(stack_a);
}

void	push_b_thr_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
	{
		stack_check(stack_a);
		pb(stack_b, stack_a);
	}
	if (order_check(stack_a) == 0)
		sort_thr(stack_a);
	while (*stack_b)
	{
		if (ft_lstsize(*stack_b) == 1)
		{
			pa(stack_a, stack_b);
			*stack_b = NULL;
			break ;
		}
		pa(stack_a, stack_b);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		push_b_thr_a(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_thr(stack_a);
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = malloc(sizeof (t_list));
	stack_b = malloc(sizeof (t_list));
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		stacking(&stack_a, ac, av);
	if (order_check(&stack_a) == 0)
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_thr(&stack_a);
		else
		{
			sort_stack(&stack_a, &stack_b);
		}
	}
	else
		ft_printf("numbers are in ascending order");

	ft_printf("size_a:%d\n", ft_lstsize(stack_a));
	ft_printf("size_b:%d\n", ft_lstsize(stack_b));
	ft_printf("a:\t");
	while (stack_a)
	{
		ft_printf("%d\t", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	if (ft_lstsize(stack_b) != 0)
	{
		ft_printf("b:\t");
		while (stack_b)
		{
			ft_printf("%d\t", stack_b->content);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}
