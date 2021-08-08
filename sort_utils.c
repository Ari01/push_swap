/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:02:01 by user42            #+#    #+#             */
/*   Updated: 2021/08/08 10:44:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	inf(int a, int b)
{
	return (a < b);
}

int	sup(int a, int b)
{
	return (a > b);
}

int	is_sorted(t_pile a, t_pile b)
{
	t_elem	*ite;

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

void	convert_values(t_pile *a)
{
	t_elem	*i;
	t_elem	*j;
	t_pile	newpile;
	int		count;

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
