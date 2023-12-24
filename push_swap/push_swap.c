/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2023/12/24 14:13:17 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
typedef struct s_stack
{
    int n;
    struct  s_stack *next;
}   t_stack;

int main(int ac, char **av)
{
    int i;
    t_stack *current;
    
    i = 1;
    current = NULL;
    if(ac >= 2)
    {
        while(av[i])
        {
            current = malloc(sizeof(t_stack));
            if (!current)
                return (0);
            current->n = atoi(av[i]);
            ft_printf("%d\n", current->n);
            free(current);
            i++;
        }
    }
}