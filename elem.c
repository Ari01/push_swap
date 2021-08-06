/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:54:36 by user42            #+#    #+#             */
/*   Updated: 2021/08/06 05:27:10 by user42           ###   ########.fr       */
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

t_pile	    init_pile(char id)
{
    t_pile  pile;

    pile.size = 0;
    pile.id = id;
    pile.head = NULL;
    pile.tail = NULL;
    return (pile);
}

void	    push_back(t_pile *pile, int value)
{
    t_elem  *tmp;

    if (!pile->tail)
    {
	pile->head = new_elem(value);
	pile->tail = pile->head;
	pile->size++;
    }
    else
    {
	tmp = new_elem(value);
	tmp->prev = pile->tail;
	tmp->prev->next = tmp;
	pile->tail = tmp;
	pile->size++;
    }
}

void	    clear(t_pile *pile)
{
    t_elem  *next;

    while (pile->head)
    {
	next = pile->head->next;
	free(pile->head);
	pile->head = next;
    }
}
