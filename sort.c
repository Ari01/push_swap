/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:35:05 by user42            #+#    #+#             */
/*   Updated: 2021/07/31 21:15:08 by user42           ###   ########.fr       */
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

void	    sort_five(t_pile *a, t_pile *b)
{
    t_elem  *ite;
    void    *(op)(t_pile *)
    int	    i;

    i = 0;
    while (a->size > 3)
	push(a, b);
    sort_three(a);
    while (b->head)
	push(b, a);
    ite = a->head->next;
    while (ite && a->head->value > ite->value)
    {
	i++;
	ite = ite->next;
    }
    if (i == 1)
	swap(a);
    else
    {
	op = &rotate;
	if (i > a->size / 2)
	{
	    i = a->size - i;
	    op = &reverse_rotate;
	}
	while (i--)
	    op(a);
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
	{
	    sort_min(a, b);
	    print_pile(*a);
	    print_pile(*b);
	}
    }
}
