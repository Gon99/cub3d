/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:59:21 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/08 14:26:14 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atob(const char *s)
{
	int		decimal;
	long	binary;
	long	mod;
	long	f;

	decimal = ft_atoi(s);
	binary = 0;
	mod = 0;
	f = 1;
	while (decimal)
	{
		mod = decimal % 2;		
		binary = binary + mod * f;
		f = f * 10;
		decimal = decimal / 2;
	}
	return (binary);
}
