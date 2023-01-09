/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:04:37 by ajimenez          #+#    #+#             */
/*   Updated: 2022/06/15 15:06:26 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelone(t_dlist *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->next && lst->prev)
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
	}
	else if (lst->prev && !lst->next)
	{
		lst->prev->next = NULL;
		lst->next->prev = lst->prev;
	}
	else if (lst->prev && !lst->next)
	{
		lst->prev->next = lst->next;
		lst->next->prev = NULL;
	}
	del(lst->content);
	free(lst);
}
