/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:17:05 by ajimenez          #+#    #+#             */
/*   Updated: 2021/08/04 17:25:52 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	res;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		res = (unsigned int)(nb * -1);
	}
	else
		res = (unsigned int)nb;
	if (res >= 10)
		ft_putnbr_fd(res / 10, fd);
	ft_putchar_fd((char)(res % 10 + 48), fd);
}
