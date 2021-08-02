/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:13:39 by user42            #+#    #+#             */
/*   Updated: 2021/08/02 19:59:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    t_pile  *src;
    t_pile  *dst;
    char    cmd[4];
    int	    count;

    count = 0;
    a = init_pile('a');
    b = init_pile('b');
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
		else if (cmd[0] == 's' && cmd[1] == 's')
		{
		    swap(&a);
		    swap(&b);
		}
		else if (cmd[0] == 's')
		    swap(dst);
		else if (cmd[0] == 'r' && cmd[1] == 'r' && (cmd[2] == 'a' || cmd[2] == 'b'))
		    reverse_rotate(dst);
		else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'r')
		{
		    reverse_rotate(&a);
		    reverse_rotate(&b);
		}
		else if (cmd[0] == 'r' && cmd[1] == 'r')
		{
		    rotate(&a);
		    rotate(&b);
		}
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
