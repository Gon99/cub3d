/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:09:27 by ajimenez          #+#    #+#             */
/*   Updated: 2021/12/13 13:40:44 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/_types/_size_t.h>

ssize_t	ft_min_int(ssize_t *str, ssize_t len)
{
	ssize_t	min;
	int		aux;

	aux = 0;
	min = str[aux];
	while (aux < len)
	{
		if (min >= str[aux])
			min = str[aux];
		aux++;
	}
	return (min);
}
