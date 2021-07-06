/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:27:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 15:37:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scpy;
	unsigned char	ccpy;
	size_t			i;

	scpy = (unsigned char *)s;
	ccpy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (scpy[i] == ccpy)
			return (&scpy[i]);
		i++;
	}
	return (NULL);
}
