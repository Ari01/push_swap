/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:54:36 by user42            #+#    #+#             */
/*   Updated: 2021/07/06 16:47:48 by user42           ###   ########.fr       */
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
    }
}

void	    print_pile(t_pile pile)
{
    printf("head = %d\n", pile.head->value);
    printf("tail = %d\n", pile.tail->value);
    while (pile.head)
    {
	printf("%d ", pile.head->value);
	pile.head = pile.head->next;
    }
/*    while (pile.tail)
    {
	printf("%d ", pile.tail->value);
	pile.tail = pile.tail->prev;
    }*/
    printf("\n");
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
