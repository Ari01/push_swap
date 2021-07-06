/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:22:18 by user42            #+#    #+#             */
/*   Updated: 2020/11/22 16:22:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst)
	{
		if (*lst && del)
		{
			if (!(*lst)->next)
				ft_lstdelone(*lst, del);
			else
			{
				ft_lstclear(&(*lst)->next, del);
				ft_lstdelone(*lst, del);
			}
			*lst = NULL;
		}
	}
}
