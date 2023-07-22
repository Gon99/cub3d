/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:46:56 by ajimenez          #+#    #+#             */
/*   Updated: 2023/07/22 17:42:23 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmatrix(char **s)
{
	size_t	aux;

	aux = 0;
	while (s[aux])
	{
		ft_putstr_fd(s[aux], 1);
		aux++;
	}
}
