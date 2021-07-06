/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:43:30 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 15:57:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1cpy;
	const unsigned char *s2cpy;
	size_t				i;

	s1cpy = (const unsigned char *)s1;
	s2cpy = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1cpy[i] - s2cpy[i])
			return (s1cpy[i] - s2cpy[i]);
		i++;
	}
	return (0);
}
