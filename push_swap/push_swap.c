/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2023/12/29 12:47:09 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacking(t_list **stack_a, int ac, char **av, int i)
{
	t_list		*new;

	if (ac >= 2)
	{
		while (av[i])
		{
			new = ft_lstnew(av[i]);
			ft_lstadd_back(stack_a, new);
			i++;
		}
		ft_printf("%d\n%d\n", ft_atoi((*stack_a)->content), ft_atoi((*stack_a)->next->content));
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
