/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:35:05 by user42            #+#    #+#             */
/*   Updated: 2021/08/01 19:01:38 by user42           ###   ########.fr       */
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

int	    sort_two(t_pile *a)
{
    if (a->head->value > a->head->next->value)
    {
	swap(a);
	return (1);
    }
    return (0);
}

int	    sort_three(t_pile *a)
{
    if (a->head->value > a->head->next->value
	&& a->head->value > a->tail->value)
    {
	rotate(a);
	if (a->head->value > a->head->next->value)
	{
	    swap(a);
	    return (2);
	}
	return (1);
    }
    else if (a->head->value > a->head->next->value)
    {
	swap(a);
	return (1);
    }
    else if (a->head->value > a->tail->value)
    {
	reverse_rotate(a);
	return (1);
    }
    else if (a->head->next->value > a->tail->value)
    {
	swap(a);
	rotate(a);
	return (2);
    }
    return (0);
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

void	    sort_five(t_pile *a, t_pile *b)
{
    int	    nops;
    int	    minpos;
    t_elem  *min;

    while (a->size > 3)
	push(a, b);
    sort_three(a);
    while (b->head)
    {
	min = get_min(*a, &minpos);
	nops = get_nops(b->head->value, *a, min, minpos);
	if (!minpos && nops == 1)
	{
	    push(b, a);
	    swap(a);
	}
	else
	{
	    set_head(a, nops);
	    push(b, a);
	}
    }
    get_min(*a, &nops);
    set_head(a, nops);
}

void	    sort(t_pile *a, t_pile *b)
{
    if (!is_sorted(*a, *b))
    {
	if (a->size == 2)
	    sort_two(a);
	else if (a->size == 3)
	    sort_three(a);
	else if (a->size <= 5)
	    sort_five(a, b);
	else
	    sort_min(a, b);
    }
    print_pile(*a);
    print_pile(*b);
}
