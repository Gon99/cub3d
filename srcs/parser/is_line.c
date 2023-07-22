/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:05:24 by ajimenez          #+#    #+#             */
/*   Updated: 2023/07/22 17:37:04 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		if (line[i] != '0' && line[i] != '1' \
				&& line[i] != 'N' && line[i] != 'S' \
				&& line[i] != 'W' && line[i] != 'E' \
				&& line[i] != '\n' && line[i] != ' ')
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

int	is_whole_spaces(char *line)
{
	int	i;
	int	it_is;

	i = 0;
	it_is = 1;
	if (!line)
		it_is = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			it_is = 0;
		i++;
	}
	return (it_is);
}

int	is_player_letter(char c)
{
	int	r;

	r = 0;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		r = 1;
	return (r);
}
