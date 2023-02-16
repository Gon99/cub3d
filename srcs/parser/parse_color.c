/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:45:03 by ajimenez          #+#    #+#             */
/*   Updated: 2023/02/16 10:53:02 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int check_bounds(char **sp)
{
	int	i;
	int	aux;

	aux = 0;
	while (sp[aux])
	{
		i = ft_atoi(sp[aux]);
		if (i < 0 || i > 255)
			return (false);
		aux++;
	}

	return (true);
}

static int check_digit(char *s)
{
	int	aux;

	aux = 0;
	while (s[aux])
	{
		if (!ft_isdigit(s[aux]) && s[aux] != ',' && s[aux] != '\n')
				return (false);
		aux++;
	}
	return (true);
}

int check_color(char *str)
{
	char	**sp;
	int 	ret;

	ret = true;
	sp = ft_split(str, ',');
	ft_putmatrix(sp);
	if (ft_matrixlen(sp) != 3)
	{
		printf("SPLIT\n");
		ret = false;
	}
//	if (ft_iter_matrix_bool(sp, ft_isdigit))
	if (!check_digit(str))
	{
		printf("digit\n");
		ret = false;
	}
	if (!check_bounds(sp))
	{
		printf("BOUNDS\n");
		ret = false;
	}
	ft_free_matrix(sp);
	return (ret);
}
