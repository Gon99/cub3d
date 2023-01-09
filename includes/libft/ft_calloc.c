/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:48:38 by ajimenez          #+#    #+#             */
/*   Updated: 2021/09/07 10:50:50 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ft_calloc(size_t num, size_t size)
{
	void	*stack;

	stack = (void *)malloc(num * size);
	if (!stack)
		return (0);
	ft_bzero (stack, (num * size));
	return (stack);
}*/

void	*ft_calloc(size_t num, size_t size)
{
	void	*stack;
	size_t	i;

	stack = (void *)malloc(num * size);
	if (!stack)
		return (0);
	i = 0;
	while (i < (num * size))
	{
		((unsigned char *)stack)[i] = '\0';
		i++;
	}
	return (stack);
}
