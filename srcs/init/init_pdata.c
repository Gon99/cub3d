/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:30:32 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/23 12:24:07 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_pdata(char **map, t_pdata *pdata)
{
	int	x;
	int	z;

	x = 0;
	while(map[x])
	{
		z = 0;
		while (map[x][z])
		{
			if (is_player_letter(map[x][z]))
			{
				pdata->x = x;
				pdata->y = z;
				pdata->p = map[x][z];
			}
			z++;
		}
		x++;
	}
	pdata->move = 0;
	pdata->spin = 0;
	pdata->angle = 0;
	pdata->vel = 3;
	pdata->vel_spin = 3 * (M_PI / 180);
	/*
	//initial direction of vector
	pdata->dir_x = -1;
	pdata->dir_y = 0;
	//the 2d raycaster version of camera plane
	pdata->plane_x = 0;
	pdata->plane_y = 0.66;
	//time of current frame
	pdata->time = 300;
	//time of previous frame
	pdata->old_time = 1;
	*/
}
