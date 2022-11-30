/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:58:51 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/30 13:34:22 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player_data(char **map, t_pdata *pdata)
{
	int	x;
	int	z;

	x = 0;
	while (map[x])
	{
		z = 0;
		while (map[x][z])
		{
			if (map[x][z] == 'S' || map[x][z] == 'N' \
					|| map[x][z] == 'W' || map[x][z] == 'E')
			{
				pdata->x = x;
				pdata->y = z;
				pdata->p = map[x][z];
			}
			z++;
		}
		x++;
	}
}
