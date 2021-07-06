/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:49:24 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 20:27:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t destlen;
	size_t srclen;

	i = 0;
	j = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= destlen)
		return (size + srclen);
	while (dst[i])
		i++;
	while (src[j] && j < size - destlen - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (destlen + srclen);
}
