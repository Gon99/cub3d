/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_have_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:08:27 by ajimenez          #+#    #+#             */
/*   Updated: 2021/11/24 17:10:55 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_have_space(char *av)
{
	int	aux;

	aux = 0;
	while (av[aux] != 0)
	{
		if (ft_isspace(av[aux]))
			return (1);
		aux++;
	}
	return (0);
}
