/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:13:39 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 17:47:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "push_swap.h"

/*void	print_pile(t_pile a)
{
	while (a.head)
	{
		printf("%d ", a.head->value);
		a.head = a.head->next;
	}
	printf("\n");
}*/

void	print_op(char *op, char id)
{
	char	s[4];
	int		len;

	len = ft_strlen(op);
	ft_strlcpy(s, op, len + 1);
	if (id)
	{
		s[len] = id;
		s[++len] = '\n';
	}
	else
		s[len] = '\n';
	write(1, s, len + 1);
}

int	main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;

	a = init_pile('a');
	b = init_pile('b');
	if (ac > 1)
	{
		if (!get_args(av, &a))
			write(STDERR_FILENO, "Error\n", 6);
		else
			sort(&a, &b);
	}
	clear(&a);
	clear(&b);
	return (0);
}
