/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:07:17 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 16:32:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_word_start(char const *s, int start, char *charset)
{
	while (s[start] && ft_strchr(charset, s[start]))
		start++;
	return (start);
}

static size_t	get_word_len(char const *s, int start, char *charset)
{
	size_t	end;

	end = start;
	while (s[end] && !ft_strchr(charset, s[end]))
		end++;
	return (end - start);
}

static size_t	get_nwords(char const *s, char *charset)
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
		start = get_word_start(s, start, charset);
		len = get_word_len(s, start, charset);
		if (len)
			nwords++;
		start += len;
	}
	return (nwords);
}

char	**ft_split(char const *s, char *charset)
{
	char	**split;
	int		i;
	size_t	start;
	size_t	len;

	i = -1;
	start = 0;
	len = 0;
	split = malloc(sizeof(*split) * (get_nwords(s, charset) + 1));
	if (!split)
		return (NULL);
	if (s)
	{
		while (s[start])
		{
			start = get_word_start(s, start, charset);
			len = get_word_start(s, start, charset);
			if (len)
				split[++i] = ft_substr(s, start, len);
			start += len;
		}
	}
	split[i] = 0;
	return (split);
}
