/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:19:09 by ajimenez          #+#    #+#             */
/*   Updated: 2022/03/04 14:22:04 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_lstnew_struct(void *newcontent, size_t size)
{
	t_dlist	*new;
	void	*content;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	content = malloc(size);
	if (!content)
	{
		free(new);
		return (0);
	}
	ft_memcpy(content, newcontent, size);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
