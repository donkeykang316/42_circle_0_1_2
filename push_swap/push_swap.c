#include "ft_printf.h"
#include <stdlib.h>
typedef struct s_number
{
    char *n;
    struct  s_number *next;
}   t_number;

int main(int ac, char **av)
{
    int i;
    t_number *current;
    
    i = 1;
    current = NULL;
    if(ac >= 2)
    {
        while(av[i])
        {
            current = malloc(sizeof(t_number));
            if (!current)
                return (0);
            current->n = av[i];
            ft_printf("%s\n", current->n);
            free(current);
            i++;
        }
    }
}