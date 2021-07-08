/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:35:05 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 20:03:35 by user42           ###   ########.fr       */
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

int	    get_min_pos(t_pile src)
{
    int	    min;
    int	    minpos;
    int	    pos;

    pos = 0;
    minpos = 0;
    if (src.head)
    {
	min = src.head->value;
	while (src.head->next)
	{
	    pos++;
	    src.head = src.head->next;
	    if (src.head->value < min)
	    {
		min = src.head->value;
		minpos = pos;
	    }
	}
    }
    return (minpos);
}

int	    push_min(t_pile *src, t_pile *dst)
{
    int	    minpos;
    int	    ret;
    void    (*f)(t_pile *);

    minpos = get_min_pos(*src);
    if (minpos <= src->size / 2)
	f = &rotate;
    else
    {
	f = &reverse_rotate;
	minpos = src->size - minpos;
    }
    ret = minpos + 1;
    while (minpos--)
	f(src);
    push(src, dst);
    return (ret);
}

void	    sort_min(t_pile *a, t_pile *b)
{
    int	    ret;

    ret = 0;
    while (a->head)
	ret += push_min(a, b);
    while (b->head)
    {
	push(b, a);
	ret++;
    }
    printf("moves = %d\n", ret);
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
	    sort_min(a, b);
	    print_pile(*a);
	    print_pile(*b);
	}
    }
}
