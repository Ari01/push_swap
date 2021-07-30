/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:35:05 by user42            #+#    #+#             */
/*   Updated: 2021/07/30 20:01:08 by user42           ###   ########.fr       */
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

void	    sort_three(t_pile *a)
{
    if (a->head->value > a->head->next->value
	&& a->head->value > a->tail->value)
    {
	rotate(a);
	if (a->head->value > a->head->next->value)
	    swap(a);
    }
    else if (a->head->value > a->head->next->value)
	swap(a);
    else if (a->head->value > a->tail->value)
	reverse_rotate(a);
    else if (a->head->next->value > a->tail->value)
    {
	swap(a);
	rotate(a);
    }
}


t_elem	    *get_max(t_pile p, int *maxpos)
{
    int	    i;
    t_elem  *max;

    i = 0;
    *maxpos = 0;
    max = p.head;
    while (p.head && p.head->next)
    {
	i++;
	p.head = p.head->next;
	if (p.head->value > max->value)
	{
	    max = p.head;
	    *maxpos = i;
	}
    }
    return (max);
}

int	    get_nops(int value, t_pile b)
{
    t_elem  *ite;
    t_elem  *max;
    int	    nops;

    max = get_max(b, &nops);
    ite = max;
    while (value < ite->value)
    {
	ite = ite->next;
	nops++;
	if (!ite)
	{
	    ite = b.head;
	    nops = 0;
	}
	if (ite == max)
	    break;
    }
    return (nops);
}

void	    set_head(t_pile *p, int nops)
{
    void    (*op)(t_pile *);

    if (nops <= p->size / 2)
	op = &rotate;
    else
    {
	nops = p->size - nops;
	op = &reverse_rotate;
    }
    while (nops--)
	op(p);
}

void	    sort_in_b(t_pile *a, t_pile *b)
{
    int	    count;
    int	    nops;
    t_elem  *max;

    count = 0;
    while (a->head)
    {
	if (b->size >= 2)
	{
	    nops = get_nops(a->head->value, *b);
	    set_head(b, nops);
	    count += nops;
	}
	push(a, b);
	count++;
    }
    max = get_max(*b, &nops);
    set_head(b, nops);
    count += nops;
    while (b->head)
    {
	push(b, a);
	count++;
    }
    printf("count = %d\n", count);
}

void	    sort(t_pile *a, t_pile *b)
{
    if (!is_sorted(*a, *b))
    {
	if (a->size == 2)
	    sort_two(a);
	else if (a->size == 3)
	    sort_three(a);
	else
	{
	    sort_in_b(a, b);
	    print_pile(*a);
	    print_pile(*b);
	}
    }
}
