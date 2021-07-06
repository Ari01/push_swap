/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:13:29 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 12:14:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

static int	convert_atoi(const char *s, int start, int end, int sign)
{
	int	res;
	int pow;

	res = 0;
	pow = 1;
	while (end >= start)
	{
		res += (s[end] - '0') * pow;
		pow *= 10;
		end--;
	}
	if (sign)
		res *= sign;
	return (res);
}

int			ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		start;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = ft_issign(nptr[i]);
	if (sign)
		i++;
	start = i;
	while (ft_isdigit(nptr[i]))
		i++;
	i--;
	if (i >= start)
		return (convert_atoi(nptr, start, i, sign));
	return (0);
}
