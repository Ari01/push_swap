/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:35:05 by user42            #+#    #+#             */
/*   Updated: 2021/08/08 11:03:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_pile *a)
{
	if (a->head->value > a->head->next->value)
		swap(a);
}

void	sort_three(t_pile *a)
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

void	sort_five(t_pile *a, t_pile *b)
{
	int		nops;
	void	(*op)(t_pile *);

	while (a->size > 3)
		push(a, b);
	sort_three(a);
	while (b->head)
		insert(b, a);
	get_minmax(*a, &nops);
	op = get_op(a->size, &nops);
	while (nops--)
		op(a);
}

void	sort_hundreds(t_pile *a, t_pile *b)
{
	int		i;
	int		j;
	int		maxbits;
	int		size;

	i = -1;
	maxbits = 0;
	size = a->size;
	convert_values(a);
	while (((size - 1) >> maxbits) != 0)
		maxbits++;
	while (++i < maxbits)
	{
		j = 0;
		while (j < size)
		{
			if ((a->head->value >> i) & 1)
				rotate(a);
			else
				push(a, b);
			j++;
		}
		while (b->head)
			push(b, a);
	}
}

void	sort(t_pile *a, t_pile *b)
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
			sort_hundreds(a, b);
	}
}
