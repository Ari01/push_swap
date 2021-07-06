/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:46:55 by user42            #+#    #+#             */
/*   Updated: 2020/11/18 17:59:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in_set(int c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_substart(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (is_in_set(s1[i], set))
		i++;
	return (i);
}

static int	get_subend(char const *s1, char const *set)
{
	int		i;

	i = ft_strlen(s1) - 1;
	while (is_in_set(s1[i], set) && i)
		i--;
	return (i);
}

static char	*strnew(size_t size)
{
	char *new;

	new = malloc(sizeof(*new) * size);
	if (!new)
		return (NULL);
	*new = 0;
	return (new);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set || !(*set))
		return (ft_strdup(s1));
	start = get_substart(s1, set);
	end = get_subend(s1, set);
	if (start > end)
		return (strnew(1));
	return (ft_substr(s1, start, end - start + 1));
}
