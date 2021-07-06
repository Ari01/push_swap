/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:01:19 by user42            #+#    #+#             */
/*   Updated: 2020/11/22 16:22:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ite;

	ite = *alst;
	if (!(*alst))
		*alst = new;
	else
	{
		while (ite->next)
			ite = ite->next;
		ite->next = new;
	}
}
