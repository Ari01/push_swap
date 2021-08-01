/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:07:07 by user42            #+#    #+#             */
/*   Updated: 2021/08/01 17:52:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	    swap_elem(t_elem *e1, t_elem *e2)
{
    int	    tmp;

    tmp = e1->value;
    e1->value = e2->value;
    e2->value = tmp;
}

void	    swap(t_pile *pile)
{
    if (pile->head && pile->head->next)
    {
	swap_elem(pile->head, pile->head->next);
	print_op("s", pile->id);
    }
}

void	    rotate(t_pile *pile)
{
    t_elem  *newhead;

    if (pile->head && pile->head != pile->tail)
    {
	if (pile->head->next == pile->tail)
	    swap_elem(pile->head, pile->tail);
	else
	{
	    newhead = pile->head->next;
	    newhead->prev = NULL;
	    pile->head->next = NULL;
	    pile->tail->next = pile->head;
	    pile->head->prev = pile->tail;
	    pile->tail = pile->head;
	    pile->head = newhead;
	}
	print_op("r", pile->id);
    }
}

void	    reverse_rotate(t_pile *pile)
{
    t_elem  *newtail;

    if (pile->head && pile->head != pile->tail)
    {
	if (pile->head->next == pile->tail)
	    swap_elem(pile->head, pile->tail);
	else
	{
	    newtail = pile->tail->prev;
	    newtail->next = NULL;
	    pile->tail->prev = NULL;
	    pile->head->prev = pile->tail;
	    pile->tail->next = pile->head;
	    pile->head = pile->tail;
	    pile->tail = newtail;
	}
	print_op("rr", pile->id);
    }
}
