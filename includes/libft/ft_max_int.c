/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:00:29 by ajimenez          #+#    #+#             */
/*   Updated: 2021/12/13 12:12:48 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/_types/_size_t.h>

ssize_t	ft_max_int(ssize_t *str, ssize_t len)
{
	ssize_t	max;
	int		aux;

	aux = 0;
	max = str[aux];
	while (aux > len)
	{
		if (max <= str[aux])
			max = str[aux];
		aux++;
	}
	return (max);
}
