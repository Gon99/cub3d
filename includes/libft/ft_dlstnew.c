/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:59:29 by ajimenez          #+#    #+#             */
/*   Updated: 2023/07/22 13:49:50 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (!lstnew)
		return (0);
	lstnew->content = content;
	lstnew->next = NULL;
	lstnew->prev = NULL;
	return (lstnew);
}
