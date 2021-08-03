/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:13:39 by user42            #+#    #+#             */
/*   Updated: 2021/08/03 17:49:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "push_swap.h"

void	print_op(char *op, char id)
{
    char    s[4];
    int	    len;

    len = ft_strlen(op);
    ft_strlcpy(s, op, len + 1);
    if (id)
    {
	s[len] = id;
	s[++len] = '\n';
    }
    else
	s[len] = '\n';
    write(1, s, len + 1);
}

int	pilechr(t_pile pile, int n)
{
    while (pile.head)
    {
	if (pile.head->value == n)
	    return (1);
	pile.head = pile.head->next;
    }
    return (0);
}

int	get_args(char **av, t_pile *p)
{
    int	    i;
    int	    n;

    i = 1;
    while (av[i])
    {
	if (!ft_atoi(av[i], &n) || pilechr(*p, n))
	    return (0);
	push_back(p, n);
	i++;
    }
    return (1);
}

int	main(int ac, char **av)
{
    t_pile  a;
    t_pile  b;

    a = init_pile('a');
    b = init_pile('b');
    if (ac > 1)
    {
	if (!get_args(av, &a))
	    write(STDERR_FILENO, "Error\n", 6);
	else
	    sort(&a, &b);
    }
    clear(&a);
    clear(&b);
    return (0);
}
