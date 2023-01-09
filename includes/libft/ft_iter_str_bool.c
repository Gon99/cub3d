/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_str_bool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:08:27 by ajimenez          #+#    #+#             */
/*   Updated: 2021/11/26 12:03:29 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iter_str_bool(char *str, int (*f)(int))
{
	int	aux;

	aux = 0;
	while (str[aux] != 0)
	{
		if (f(str[aux]))
			return (1);
		aux++;
	}
	return (0);
}
