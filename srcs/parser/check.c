/* ************************************************************************** */
/*      false                                                                     */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:24:09 by ajimenez          #+#    #+#             */
/*   Updated: 2023/02/21 10:48:02 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	extension_check(char *map)
{
	char	*aux;
	size_t	i;

	i = 0;
	aux = ft_strrchr(map, '.');
	if (!aux)
		return (false);
	if (aux[i] == '.' && aux[i + 1] == 'c' && aux[i + 2] == 'u'
		&& aux[i + 3] == 'b' && aux[i + 4] == '\0')
		return (true);
	return (false);
}

int	map_data_check(t_gdata *gdata)
{
	int	r;

	r = 1;
	if (gdata->no == 0 || gdata->so == 0 || gdata->ea == 0)
		r = 0;
	if (gdata->we == 0 || gdata->f == 0 || gdata->c == 0)
		r = 0;
	return (r);
}


int	repeated_chars_check(char **map)
{
	int	i;
	int	c;
	int	z;

	c = 0;
	i = 0;
	while (map[i])
	{
		z = 0;
		while (map[i][z])
		{
			if (map[i][z] == 'S' || map[i][z] == 'N' \
					|| map[i][z] == 'E' || map[i][z] == 'W' || map[i][z] == '\n')
				c++;
			z++;
		}
		i++;
	}
	if (c == 1)
		return (0);
	return (1);
}
