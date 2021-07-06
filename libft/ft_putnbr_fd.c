/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:52:10 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 11:29:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	unbr;

	unbr = n;
	if (n < 0)
	{
		unbr = -n;
		write(fd, "-", 1);
	}
	if (unbr < 10)
	{
		c = unbr + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(unbr / 10, fd);
		c = unbr % 10 + '0';
		write(fd, &c, 1);
	}
}
