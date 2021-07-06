/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:29:37 by user42            #+#    #+#             */
/*   Updated: 2020/12/05 14:57:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static char	*get_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	biglen;
	char	*occ;

	i = 0;
	j = 0;
	biglen = ft_strlen(big);
	while (big[i] && i < len && i < biglen)
	{
		while (big[i] && big[i] != little[j] && i < len)
			i++;
		occ = (char *)&big[i];
		while (big[i] && little[j] && big[i] == little[j] && i < len)
		{
			i++;
			j++;
		}
		if (!little[j])
			return (occ);
		i = occ - big + 1;
		j = 0;
	}
	return (NULL);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!little[0])
		return ((char *)big);
	return (get_strnstr(big, little, len));
}
