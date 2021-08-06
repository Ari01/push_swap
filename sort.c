/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:35:05 by user42            #+#    #+#             */
/*   Updated: 2021/08/06 05:31:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	    sort_two(t_pile *a)
{
    if (a->head->value > a->head->next->value)
	swap(a);
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
    op = get_op(a->size, &nops);
    while (nops--)
	op(a);
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
    clear(a);
    *a = newpile;
}

void	    sort_hundreds(t_pile *a, t_pile *b)
{
    int	    i;
    int	    j;
    int	    maxbits;
    int	    size;

    i = 0;
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
		rotate(a);
	    else
		push(a, b);
	    j++;
	}
	while (b->head)
	    push(b, a);
	i++;
    }
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
	    sort_hundreds(a, b);
    }
}
