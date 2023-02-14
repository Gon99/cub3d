/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:46:56 by ajimenez          #+#    #+#             */
/*   Updated: 2023/02/14 15:00:54 by ajimenez         ###   ########.fr       */
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
		ft_putchar_fd('\n', 1);
		aux++;
	}
}
