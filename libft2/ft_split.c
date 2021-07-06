/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:07:17 by user42            #+#    #+#             */
/*   Updated: 2020/11/22 19:40:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_word_start(char const *s, int start, char c)
{
	while (s[start] && s[start] == c)
		start++;
	return (start);
}

static size_t	get_word_len(char const *s, int start, char c)
{
	size_t end;

	end = start;
	while (s[end] && s[end] != c)
		end++;
	return (end - start);
}

static size_t	get_nwords(char const *s, char c)
{
	size_t start;
	size_t len;
	size_t nwords;

	start = 0;
	len = 0;
	nwords = 0;
	if (!s || !*s)
		return (0);
	while (s[start])
	{
		start = get_word_start(s, start, c);
		len = get_word_len(s, start, c);
		if (len)
			nwords++;
		start += len;
	}
	return (nwords);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	size_t	start;
	size_t	len;

	i = 0;
	start = 0;
	len = 0;
	if (!(split = malloc(sizeof(*split) * (get_nwords(s, c) + 1))))
		return (NULL);
	if (s)
	{
		while (s[start])
		{
			start = get_word_start(s, start, c);
			if ((len = get_word_len(s, start, c)))
			{
				split[i] = ft_substr(s, start, len);
				i++;
			}
			start += len;
		}
	}
	split[i] = 0;
	return (split);
}
