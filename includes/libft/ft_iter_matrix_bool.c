/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_matrix_bool.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:43:12 by ajimenez          #+#    #+#             */
/*   Updated: 2021/12/09 16:01:36 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iter_matrix_bool(char **str, int (*f)(int))
{
	int	aux;

	aux = 0;
	while (str[aux] != 0)
	{
		if (ft_iter_str_bool(str[aux], (*f)))
			return (1);
		aux++;
	}
	return (0);
}
