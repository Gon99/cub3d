/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:30:32 by ajimenez          #+#    #+#             */
/*   Updated: 2023/02/04 11:16:44 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	init_angle(char pv)
{
	double	angle;

	angle = 0;
	if (pv == 'N')
		angle = 3 * M_PI / 2;
	else if (pv == 'S')
		angle = M_PI / 2;
	else if (pv == 'W')
		angle = M_PI;
	return (angle);
}

void	init_pdata(t_gdata *gdata)
{
	int	x;
	int	z;

	x = 0;
	gdata->h_prop = MAP_HEIGHT / gdata->height;
	gdata->w_prop = MAP_WIDTH / gdata->width;
	while(gdata->map[x])
	{
		z = 0;
		while (gdata->map[x][z])
		{
			if (is_player_letter(gdata->map[x][z]))
			{
				gdata->pdata->x = z;
				gdata->pdata->y = x;
				gdata->pdata->p = gdata->map[x][z];
			}
			z++;
		}
		x++;
	}
	gdata->pdata->move = 0;
	gdata->pdata->spin = 0;
	gdata->pdata->vel = 1;
	gdata->pdata->vel_spin = 1 * (M_PI / 180);
	gdata->pdata->angle = init_angle(gdata->pdata->p);
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
