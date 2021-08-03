/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:35:05 by user42            #+#    #+#             */
/*   Updated: 2021/08/03 20:41:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	    sort_five(t_pile *a, t_pile *b)
{
    int	    nops;
    void    (*op)(t_pile *);

    while (a->size > 3)
	push(a, b);
    sort_three(a);
    while (b->head)
	insert(b, a);
    get_minmax(*a, &nops);
    if (nops == 1)
	swap(a);
    else
    {
	op = get_op(a->size, &nops);
	while (nops--)
	    op(a);
    }
}

void	    convert_values(t_pile *a)
{
    t_elem  *i;
    t_elem  *j;
    t_pile  newpile;
    int	    count;

    count = 0;
    i = a->head;
    newpile = init_pile('a');
    while (i)
    {
	j = a->head;
	while (j)
	{
	    if (i->value > j->value)
		count++;
	    j = j->next;
	}
	push_back(&newpile, count);
	count = 0;
	i = i->next;
    }
    *a = newpile;
    print_pile(*a);
}

void	    sort_hundreds(t_pile *a, t_pile *b)
{
    int	    count;
    int	    i;
    int	    j;
    int	    maxbits;
    int	    size;

    i = 0;
    count = 0;
    maxbits = 0;
    size = a->size;
    convert_values(a);
    while (((size - 1) >> maxbits) != 0)
	maxbits++;
    while (i < maxbits)
    {
	j = 0;
	while (j < size)
	{
	    if ((a->head->value >> i)&1)
	    {
		rotate(a);
		count++;
	    }
	    else
	    {
		push(a, b);
		count++;
	    }
	    j++;
	}
	while (b->head)
	{
	    push(b, a);
	    count++;
	}
	i++;
    }
    printf("count = %d\n", count);
}
/*
void	    fusion(t_pile *a, t_pile *b)
{
    t_elem	(*get_minmax)(t_pile, int *);
    int		pos;

    if (a->id == 'a')
	minmax = &min;
    else
	minmax = &max;
    while (b->head)
    {
	min = get_minmax(*a, &pos);
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

void	    sort_fusion(t_pile *a, t_pile *b)
{

}*/

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
	    sort_hundreds(a, b);
    }
    print_pile(*a);
    print_pile(*b);
}
