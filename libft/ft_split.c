/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:07:17 by user42            #+#    #+#             */
/*   Updated: 2021/08/11 13:22:33 by user42           ###   ########.fr       */
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
	size_t	end;

	end = start;
	while (s[end] && s[end] != c)
		end++;
	return (end - start);
}

static size_t	get_nwords(char const *s, char c)
{
	size_t	start;
	size_t	len;
	size_t	nwords;

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

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	size_t	start;
	size_t	len;

	i = 0;
	start = 0;
	len = 0;
	split = malloc(sizeof(*split) * (get_nwords(s, start) + 1));
	if (!split)
		return (NULL);
	if (s)
	{
		while (s[start])
		{
			start = get_word_start(s, start, c);
			len = get_word_start(s, start, c);
			if (len)
				split[i++] = ft_substr(s, start, len);
			start += len;
		}
	}
	split[i] = 0;
	return (split);
}
