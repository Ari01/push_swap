/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:04:59 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 14:59:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*scpy;
	unsigned char	ccpy;

	scpy = (unsigned char*)s;
	ccpy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		scpy[i] = ccpy;
		i++;
	}
	return (s);
}
