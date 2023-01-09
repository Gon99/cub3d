/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:30:11 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/08 15:46:14 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

int	ft_boti(long binary)
{
	int	decimal;
	int	mod;
	int	i;

	decimal = 0;
	mod = 0;
	i = 0;
	while (binary)
	{
		mod = binary % 10;		
		binary /= 10;
		decimal += mod * pow(2, i);
		i++;
	}
	return (decimal);
}
