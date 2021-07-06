/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:00:20 by user42            #+#    #+#             */
/*   Updated: 2020/11/22 19:58:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*destcpy;
	unsigned char	*srccpy;
	unsigned char	ccpy;

	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	ccpy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		if (destcpy[i] == ccpy)
			return (&destcpy[i + 1]);
		i++;
	}
	return (NULL);
}
