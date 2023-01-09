/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:46:56 by ajimenez          #+#    #+#             */
/*   Updated: 2021/11/07 15:30:37 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmatrix(char **s, size_t lines)
{
	size_t	aux;

	aux = 0;
	while (aux < lines)
	{
		ft_putstr_fd(s[aux], 1);
		aux++;
		write (1, "\n", 1);
	}
}
