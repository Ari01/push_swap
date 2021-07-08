/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:13:39 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 17:04:59 by user42           ###   ########.fr       */
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
    t_pile  *src;
    t_pile  *dst;
    char    cmd[4];
    int	    count;

    count = 0;
    a = init_pile();
    b = init_pile();
    if (ac > 1)
    {
	if (!get_args(av, &a))
	    write(STDERR_FILENO, "Error\n", 6);
	else
	{
	    while (!is_sorted(a, b))
	    {
		print_pile(a);
		print_pile(b);
		scanf("%s", cmd);
		printf("\n %s\n", cmd);
		if (ft_strchr(cmd, 'a'))
		{
		    src = &b;
		    dst = &a;
		}
		else if (ft_strchr(cmd, 'b'))
		{
		    src = &a;
		    dst = &b;
		}
		if (cmd[0] == 'p')
		    push(src, dst);
		else if (cmd[0] == 's')
		    swap(dst);
		else if (cmd[0] == 'r' && cmd[1] == 'r')
		    reverse_rotate(dst);
		else
		    rotate(dst);
		count++;
	    }
	    printf("\n moves : %d\n", count);
	    /*print_pile(a);
	    sort(&a);
	    print_pile(a);*/
	}
	clear(&a);
	clear(&b);
    }
    return (0);
}
