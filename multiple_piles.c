/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:04:48 by user42            #+#    #+#             */
/*   Updated: 2021/08/01 17:50:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	    push(t_pile *src, t_pile *dst)
{
    t_elem  *tmp;

    if (src->head)
    {
	tmp = src->head;
	src->head = src->head->next;
	if (src->head)
	    src->head->prev = NULL;
	if (!dst->head)
	{
	    tmp->next = NULL;
	    dst->head = tmp;
	    dst->tail = dst->head;
	}
	else
	{
	    dst->head->prev = tmp;
	    tmp->next = dst->head;
	    dst->head = tmp;
	}
	src->size--;
	dst->size++;
	print_op("p", dst->id);
    }
}

void	    ss(t_pile *p1, t_pile *p2)
{
    swap(p1);
    swap(p2);
    print_op("ss", 0);
}

void	    rr(t_pile *p1, t_pile *p2)
{
    rotate(p1);
    rotate(p2);
    print_op("rr", 0);
}

void	    rrr(t_pile *p1, t_pile *p2)
{
    reverse_rotate(p1);
    reverse_rotate(p2);
    print_op("rrr", 0);
}
