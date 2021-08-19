/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:13:39 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 18:00:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include "push_swap.h"

void	    print_pile(t_pile pile)
{
    while (pile.head)
    {
	printf("%d ", pile.head->value);
	pile.head = pile.head->next;
    }
    printf("\n");
}

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

int	main(int ac, char **av)
{
    t_pile  a;
    t_pile  b;
    int	    n;
    int	    i;
    int	    imax;
    int	    size;
    int	    *used;

    (void)ac;
    ft_atoi(av[1], &size);
    ft_atoi(av[2], &imax);
    while (imax--)
    {
	i = 0;
	used = malloc(sizeof(*used) * size);
	srand(time(NULL) + imax * 365);
	n = rand() % size;
	a = init_pile('a');
	b = init_pile('b');
	while (i < size)
	{
	    used[i] = 0;
	    i++;
	}
	while (a.size < size)
	{
	    while (used[n])
		n = rand() % size;
	    used[n] = 1;
	    push_back(&a, n);
	}
	sort(&a, &b);
	free(used);
	used = NULL;
    }
    clear(&a);
    clear(&b);
    return (0);
}
