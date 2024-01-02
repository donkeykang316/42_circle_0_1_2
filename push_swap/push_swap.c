/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/02 13:07:44 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bool(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp && (temp)->next != NULL)
	{
		if (ft_atoi((temp)->content) <= ft_atoi((temp)->next->content))
			temp = (temp)->next;
		else
			return (0);
	}
	return (1);
}

int	get_min(t_list **stack_a)
{
	int		min;
	int		position;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack_a;
	temp2 = *stack_a;
	position = 0;
	if (ft_bool(stack_a) == 0)
	{
		min = ft_atoi(temp1->content);
		while (temp1)
		{
			if (min >= ft_atoi(temp1->content))
				min = ft_atoi(temp1->content);
			temp1 = temp1->next;
		}
	}
	while (ft_atoi(temp2->content) != min)
	{
		temp2 = temp2->next;
		position++;
	}
	return (position);
}

void	ft_ra(t_list **stack_a, int position)
{
	// look for the list index and ra
	while (position >= 0)
	{
		position--;
	}
}

void	stacking(t_list **stack_a, int ac, char **av, int i)
{
	t_list		*new;
	int			position;

	if (ac >= 2)
	{
		while (av[i])
		{
			new = ft_lstnew(av[i]);
			ft_lstadd_back(stack_a, new);
			i++;
		}
		position = get_min(stack_a);
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
