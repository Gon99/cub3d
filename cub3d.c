/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/02 12:07:21 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

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

int	open_map_chequer(char *map)
{
	int	r;

	r = open(map, O_RDONLY);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (!map_name_chequer(argv[1]))
			return (0);
	if (!open_map_chequer(argv[1]))
		return (0);
	return (1);
}
