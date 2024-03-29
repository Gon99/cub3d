/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:20:21 by ajimenez          #+#    #+#             */
/*   Updated: 2023/07/22 17:34:55 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_matrixlen(char **matrix)
{
	size_t	len;

	if (!matrix)
		return (0);
	len = 0;
	while (matrix[len] != NULL)
		len++;
	return (len);
}
