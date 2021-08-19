/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:45:55 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 17:55:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strtab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	pilechr(t_pile pile, int n)
{
	while (pile.head)
	{
		if (pile.head->value == n)
			return (1);
		pile.head = pile.head->next;
	}
	return (0);
}

int	push_arg(char **s, t_pile *p)
{
	int	i;
	int	n;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_atoi(s[i], &n) || pilechr(*p, n))
			return (0);
		push_back(p, n);
		i++;
	}
	return (1);
}

int	get_args(char **av, t_pile *p)
{
	int		i;
	int		ret;
	char	**s;

	i = 1;
	while (av[i])
	{
		s = ft_split(av[i], " \f\n\r\t\v");
		ret = push_arg(s, p);
		free_strtab(s);
		if (!ret)
			return (0);
		i++;
	}
	return (1);
}
