/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:56:57 by ajimenez          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*back;

	if (!new)
		return ;
	if (!*dlst)
	{
		*dlst = new;
		return ;
	}
	back = ft_dlstlast(*dlst);
	back->next = new;
	new->prev = back;
}
