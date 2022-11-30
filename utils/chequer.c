/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chequer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:00:50 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/30 13:41:06 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
					|| map[i][z] == 'E' || map[i][z] == 'W')
				c++;
			z++;
		}
		i++;
	}
	if (c == 1)
		return (0);
	return (1);
}

int	map_name_chequer(char *map)
{
	int	l;
	int	r;

	map = ft_strtrim(map, " ");
	l = ft_strlen(map) - 4;
	r = -1;
	if (l > 0)
		r = ft_strcmp(&map[l], ".cub");
	return (r);
}

int	map_data_chequer(t_gdata *gdata)
{
	int	r;

	r = 1;
	if (gdata->no == 0 || gdata->so == 0 || gdata->ea == 0)
		r = 0;
	if (gdata->we == 0 || gdata->f == 0 || gdata->c == 0)
		r = 0;
	return (r);
}

int	is_map_line(char *line)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	if (!line || is_empty_line(line))
		return (0);
	while (line[i] && r)
	{
		if (!ft_isspace(line[i]) && line[i] != '0' && line[i] != '1' \
				&& line[i] != 'N' && line[i] != 'S' \
				&& line[i] != 'W' && line[i] != 'E')
			r = 0;
		i++;
	}
	return (r);
}

int	is_empty_line(char *line)
{
	int	i;
	int	r;

	r = 1;
	i = 0;
	while (line[i] && r)
	{
		if (!ft_isspace(line[i]))
			r = 0;
		i++;
	}
	return (r);
}
