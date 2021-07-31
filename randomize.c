/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:13:39 by user42            #+#    #+#             */
/*   Updated: 2021/07/31 19:55:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "push_swap.h"

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

int	main()
{
    t_pile  a;
    t_pile  b;
    int	    count;
    int	    n;
    int	    i;
    int	    used[100];

    i = 0;
    count = 0;
    srand(time(NULL));
    n = rand() % 100;
    a = init_pile();
    b = init_pile();
    while (i < 100)
    {
	used[i] = 0;
	i++;
    }
    while (a.size < 100)
    {
	while (used[n])
	    n = rand() % 100;
	used[n] = 1;
	push_back(&a, n);
    }
    print_pile(a);
    sort(&a, &b);
    clear(&a);
    clear(&b);
    return (0);
}
