/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:13:39 by user42            #+#    #+#             */
/*   Updated: 2021/07/06 17:25:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int ac, char **av)
{
    t_pile  a;
    t_pile  b;

    a.head = NULL;
    a.tail = NULL;
    b.head = NULL;
    b.tail = NULL;
    if (ac > 1)
    {
	if (!get_args(av, &a))
	    write(STDERR_FILENO, "Error\n", 6);
	else
	{
	    push(&a, &b);
	    print_pile(a);
	    print_pile(b);
	    printf("\n");
	    push(&a, &b);
	    print_pile(a);
	    print_pile(b);
	    printf("\n");
	    push(&a, &b);
	    print_pile(a);
	    print_pile(b);
	    printf("\n");
	    push(&a, &b);
	    print_pile(a);
	    print_pile(b);
	    printf("\n");
	    ss(&a, &b);
	    print_pile(a);
	    print_pile(b);
	    printf("\n");
	    rr(&a, &b);
	    print_pile(a);
	    print_pile(b);
	    printf("\n");
	    rrr(&a, &b);
	    print_pile(a);
	    print_pile(b);
	    printf("\n");
	}
	clear(&a);
	clear(&b);
    }
    return (0);
}
