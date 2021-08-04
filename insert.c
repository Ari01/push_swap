/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:15:13 by user42            #+#    #+#             */
/*   Updated: 2021/08/04 20:29:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	    inf(int a, int b)
{
    return (a < b);
}

int	    sup(int a, int b)
{
    return (a > b);
}

t_elem	    *get_minmax(t_pile p, int *pos)
{
    int	    i;
    int	    (*comp)(int, int);
    t_elem  *minmax;

    i = 0;
    *pos = 0;
    minmax = p.head;
    comp = &inf;
    if (p.id == 'b')
	comp = &sup;
    while (p.head && p.head->next)
    {
	i++;
	p.head = p.head->next;
	if (comp(p.head->value, minmax->value))
	{
	    minmax = p.head;
	    *pos = i;
	}
    }
    return (minmax);
}

int	    get_newpos(int value, t_pile p, t_elem *start, int newpos)
{
    t_elem  *ite;
    int	    (*comp)(int, int);

    ite = start;
    comp = &inf;
    printf("value = %d, ite->value = %d, newpos = %d, p.id = %c\n", value, ite->value, newpos, p.id);
    if (p.id == 'a')
	comp = &sup;
    while (comp(value, ite->value))
    {
	ite = ite->next;
	newpos++;
	if (!ite)
	{
	    ite = p.head;
	    newpos = 0;
	}
	if (ite == start)
	    return (newpos);
    }
    return (newpos);
}

void	    *get_op(int pilesize, int *nops)
{
    void    (*op)(t_pile *);
    int	    i;

    i = 0;
    if (*nops <= pilesize / 2)
	op = &rotate;
    else
    {
	*nops = pilesize - *nops;
	op = &reverse_rotate;
    }
    return (op);
}

int	    insert(t_pile *a, t_pile *b)
{
    int	    newpos;
    int	    minmax_pos;
    t_elem  *minmax;
    void    (*op)(t_pile *);

    int count;
    count = 0;
    minmax = get_minmax(*b, &minmax_pos);
    newpos = get_newpos(a->head->value, *b, minmax, minmax_pos);
    if (!minmax_pos && newpos == 1)
    {
	push(a, b);
	swap(b);
	count += 2;
    }
    else
    {
	op = get_op(b->size, &newpos);
	printf("newpos = %d, minmaxpos = %d\n", newpos, minmax_pos);
	while (newpos--)
	{
	    op(b);
	    count++;
	}
	push(a, b);
	count++;
    }
    return (count);
}
