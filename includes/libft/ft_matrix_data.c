/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:04:29 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/23 15:26:20 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static ssize_t	*ft_length(char **matrix)
{
	ssize_t	aux;
	ssize_t	*length_str;

	aux = 0;
	length_str = malloc(sizeof(size_t) * (ft_matrixlen(matrix)));
	if (!length_str)
		return (0);
	while (matrix[aux] != NULL)
	{
		length_str[aux] = ft_strlen(matrix[aux]);
		aux++;
	}
	return (length_str);
}

static size_t ft_matrixheight(char **matrix)
{
	ssize_t	height;

	height = 0;
	while (matrix[height])
		height++;
	return (height);
}

static	size_t	ft_matrixwidth(char **matrix)
{
	ssize_t	width;
	int	x;
	int	j;

	width = 0;
	x = 0;
	while (matrix[x])
	{
		j = 0;
		while (matrix[x][j])
			j++;
		if (width < j)
			width = j;
		x++;
	}
	return (width);
}

t_matrix_data	ft_matrix_data(char **matrix)
{
	t_matrix_data	data;

	if (!matrix)
		return ((t_matrix_data){0, 0, 0, 0, 0, 0});
	data.line_count = ft_matrixlen(matrix);
	data.lenght_str = ft_length(matrix);
	data.height = ft_matrixheight(matrix);
	data.width = ft_matrixwidth(matrix);
	data.max = ft_max_int(data.lenght_str, data.line_count);
	data.min = ft_min_int(data.lenght_str, data.line_count);
	return (data);
}
