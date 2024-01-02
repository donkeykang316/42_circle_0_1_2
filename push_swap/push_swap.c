/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/02 22:34:22 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bool(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp && (temp)->next != NULL)
	{
		if (temp->content <= temp->next->content)
			temp = (temp)->next;
		else
			return (0);
	}
	return (1);
}

int	get_min(t_list **stack_a)
{
	int		min;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack_a;
	temp2 = *stack_a;
	if (ft_bool(stack_a) == 0)
	{
		min = temp1->content;
		while (temp1)
		{
			if (min >= temp1->content)
				min = temp1->content;
			temp1 = temp1->next;
		}
	}
	while (temp2)
	{
		if (min == temp2->content)
			break ;
		temp2 = temp2->next;
	}
	return (temp2->index);
}

void	ft_rot(t_list **stack_a, int position)
{
	t_list	*temp;

	temp = *stack_a;
	ft_printf("%d\n", temp->content);
	while (*stack_a)
	{
		if ((*stack_a)->index != position)
			*stack_a = (*stack_a)->next;
		else
		{
			*stack_a = temp;
			break ;
		}
	}
/* 	while (*stack_a)
	{
		ft_printf("%d\n", (*stack_a)->content);
		*stack_a = (*stack_a)->next;
	}*/
}

void	stacking(t_list **stack_a, int ac, char **av, int i)
{
	t_list		*new;
	int			position;

	if (ac >= 2)
	{
		while (av[i])
		{
			new = ft_lstnew(ft_atoi(av[i]));
			ft_lstadd_back(stack_a, new);
			new->index = i;
			i++;
		}
		position = get_min(stack_a);
		ft_rot(stack_a, position);
	}
	free(new);
}

int	main(int ac, char **av)
{
	int			i;
	t_list		**stack_a;

	i = 1;
	stack_a = malloc(ac * sizeof (t_list));
	*stack_a = NULL;
	stacking(stack_a, ac, av, i);
	free(stack_a);
}
