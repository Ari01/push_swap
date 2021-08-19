/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:36:11 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 17:16:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	get_nwords(char const *s, char *charset)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		while (ft_strchr(charset, s[i]))
			i++;
		while (s[i] && !ft_strchr(charset, s[i]))
			i++;
		ret++;
	}
	return (ret);
}

char	**ft_split(char const *s, char *charset)
{
	int		i;
	int		j;
	int		start;
	int		nwords;
	char	**split;

	i = 0;
	j = 0;
	nwords = get_nwords(s, charset);
	split = malloc(sizeof(*split) * (nwords + 1));
	while (j < nwords)
	{
		while (ft_strchr(charset, s[i]))
			i++;
		start = i;
		while (!ft_strchr(charset, s[i]))
			i++;
		if (i > start)
			split[j] = ft_substr(s, start, i - start);
		j++;
	}
	split[j] = 0;
	return (split);
}
