/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/16 17:59:25 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack_a, t_list *stack_b)
{
	ft_printf("a_%d:\t", ft_lstsize(stack_a));
	while (stack_a)
	{
		ft_printf("%d\t", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	if (ft_lstsize(stack_b) != 0)
	{
		ft_printf("b_%d:\t", ft_lstsize(stack_b));
		while (stack_b)
		{
			ft_printf("%d\t", stack_b->content);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}

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

int	case_rb(t_list *stack_b, int content)
{
	t_list	*temp;
	int		i;

	temp = stack_b;
	i = index_start_to_node(temp, content);
	return (i);
}

int	case_rrb(t_list *stack_b, int content)
{
	t_list	*temp;
	int		i;

	temp = stack_b;
	i = index_node_to_last(temp, content);
	return (i);
}

void	apply_rb(t_list **stack_b, int rb_i)
{
	while (rb_i != 0)
	{
		rb(stack_b);
		rb_i--;
	}
}

void	apply_rrb(t_list **stack_b, int rrb_i)
{
	while (rrb_i != 0)
	{
		rrb(stack_b);
		rrb_i--;
	}
}

void	stack_check(t_list **stack_a)
{
	int value;

	value = (*stack_a)->content;
	if (value > (*stack_a)->next->content)
	{
		//error line, need fix
		while ((get_max(*stack_a)->content != ft_lstlast(*stack_a)->content))
			ra(stack_a);
	}
}

void	push_b_thr_a(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 1 && order_check(stack_b) == 1)
		rb(stack_b);
	while (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
	{
		pb(stack_b, stack_a);
		print_stack(*stack_a, *stack_b);
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
		stack_check(stack_a);
		pa(stack_a, stack_b);
		print_stack(*stack_a, *stack_b);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		pb(stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		pb(stack_b, stack_a);
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
