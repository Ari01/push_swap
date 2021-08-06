/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:02:01 by user42            #+#    #+#             */
/*   Updated: 2021/08/06 05:02:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	    inf(int a, int b)
{
    return (a < b);
}

int	    sup(int a, int b)
{
    return (a > b);
}

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
