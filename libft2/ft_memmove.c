/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:34:54 by user42            #+#    #+#             */
/*   Updated: 2020/11/22 20:59:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destcpy;
	const unsigned char	*srccpy;
	size_t				i;

	if (dest == src)
		return (NULL);
	destcpy = (unsigned char *)dest;
	srccpy = (const unsigned char *)src;
	i = 0;
	if (destcpy < srccpy)
	{
		while (i < n)
		{
			destcpy[i] = srccpy[i];
			i++;
		}
	}
	else
	{
		while (n--)
			destcpy[n] = srccpy[n];
	}
	return (dest);
}
