/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:04:48 by user42            #+#    #+#             */
/*   Updated: 2021/07/06 17:22:16 by user42           ###   ########.fr       */
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
    }
}

void	    ss(t_pile *p1, t_pile *p2)
{
    swap(p1);
    swap(p2);
}

void	    rr(t_pile *p1, t_pile *p2)
{
    rotate(p1);
    rotate(p2);
}

void	    rrr(t_pile *p1, t_pile *p2)
{
    reverse_rotate(p1);
    reverse_rotate(p2);
}
