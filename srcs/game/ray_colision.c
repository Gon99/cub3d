/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:17:41 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/16 20:56:50 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	wall_hit_x_hor(t_gdata *gdata)
{
	int		col;
	double	y_intercept;
	double	x_intercept;
	double	x_step;
	double	y_step;

	col = 0;
	y_intercept = gdata->pdata->y;
	if (is_down(gdata->pdata->angle))
		y_intercept += TILE_SIZE;
	x_intercept = (y_intercept - gdata->pdata->y) / tan(gdata->pdata->angle)\
				  + gdata->pdata->x;
	y_step = get_y_step(gdata->pdata->angle);
	x_step = get_x_step(y_step, gdata->pdata->angle);
	while (!col)
	{
		if (player_colision(y_intercept, x_intercept, gdata))
		{
			col = 1;
			gdata->rdata->h_hit = 1;
		}
		else
		{
			x_intercept += x_step;
			y_intercept += y_step;
		}
	}
	return (x_intercept);
}

int	wall_hit_y_hor(t_gdata *gdata)
{
	int	col;
	double	x_intercept;
	double	y_intercept;
	double	y_step;
	double	x_step;

	col = 0;
	y_step = get_y_step(gdata->pdata->angle);
	y_intercept = gdata->pdata->y;
	if (is_down(gdata->pdata->angle))
		y_intercept += TILE_SIZE;
	x_intercept = (y_intercept - gdata->pdata->y) / tan(gdata->pdata->angle)\
				  + gdata->pdata->x;
	x_step = get_x_step(y_step, gdata->pdata->angle);
	while(!col)
	{
		if (player_colision(y_intercept, x_intercept, gdata))
		{
			gdata->rdata->h_hit = 1;
			col = 1;
		}
		else
		{
			x_intercept += x_step;
			y_intercept += y_step;
		}
	}
	return (y_intercept);
}
