/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:02:01 by user42            #+#    #+#             */
/*   Updated: 2021/08/02 20:06:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	    is_sorted(t_pile a, t_pile b)
{
    t_elem  *ite;

    if (b.head)
	return (0);
    while (a.head)
    {
	ite = a.head->next;
	while (ite)
	{
	    if (a.head->value > ite->value)
		return (0);
	    ite = ite->next;
	}
	a.head = a.head->next;
    }
    return (1);
}


t_elem	    *get_min(t_pile p, int *minpos)
{
    int	    i;
    t_elem  *min;

    i = 0;
    *minpos = 0;
    min = p.head;
    while (p.head && p.head->next)
    {
	i++;
	p.head = p.head->next;
	if (p.head->value < min->value)
	{
	    min = p.head;
	    *minpos = i;
	}
    }
    return (min);
}

int	    get_nops(int value, t_pile p, t_elem *min, int nops)
{
    t_elem  *ite;

    ite = min;
    while (value > ite->value)
    {
	ite = ite->next;
	nops++;
	if (!ite)
	{
	    ite = p.head;
	    nops = 0;
	}
	if (ite == min)
	    break;
    }
    return (nops);
}

int	    set_head(t_pile *p, int nops)
{
    void    (*op)(t_pile *);
    int	    i;

    i = 0;
    if (nops <= p->size / 2)
	op = &rotate;
    else
    {
	nops = p->size - nops;
	op = &reverse_rotate;
    }
    while (i < nops)
    {
	op(p);
	i++;
    }
    return (nops);
}
