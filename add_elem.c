/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:11:53 by user42            #+#    #+#             */
/*   Updated: 2021/07/07 13:14:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	    *new_elem(int value)
{
    t_elem  *elem;

    elem = malloc(sizeof(*elem));
    elem->value = value;
    elem->next = NULL;
    elem->prev = NULL;
    return (elem);
}

t_pile	    new_pile(int value)
{
    t_pile  pile;

    pile.size = 1;
    pile.head = new_elem(value);
    pile.tail = pile.head;
    return (pile);
}

void	    push_back(t_pile *pile, int value)
{
    t_elem  *tmp;

    if (!pile->tail)
	*pile = new_pile(value);
    else
    {
	tmp = new_elem(value);
	tmp->prev = pile->tail;
	tmp->prev->next = tmp;
	pile->tail = tmp;
	pile->size++;
    }
}
