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

int	wall_hit_hor(t_gdata *gdata, int type)
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
	if (type)
		return (y_intercept);
	return (x_intercept);
}

int	wall_hit_vert(t_gdata *gdata, int type)
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
	int	col;

	col = 0;
	x_intercept = gdata->pdata->x;
	if (!is_left(gdata->pdata->angle))
		x_intercept += TILE_SIZE;
	y_intercept = gdata->pdata->y + (x_intercept - gdata->pdata->x) \
		* tan(gdata->pdata->angle);
	x_step = TILE_SIZE;
	if (is_left(gdata->pdata->angle))
		x_step *= -1;
	y_step = tan(gdata->pdata->angle) * TILE_SIZE;
	if ((y_step > 0 && !is_down(gdata->pdata->angle)) \
		|| (y_step < 0 && is_down(gdata->pdata->angle)))
		y_step *= -1;
	if (is_left(gdata->pdata->angle))
		y_intercept--;
	while (!col && (x_intercept >= 0 && y_intercept >= 0 && x_intercept < gdata->width && y_intercept < gdata->height))
	{
		if (player_colision(y_intercept, x_intercept, gdata))
		{
			col = 1;
			gdata->rdata->v_hit = 1;
		}
		else
		{
			x_intercept += x_step;
			y_intercept += y_step;
		}
	}
	if (type)
		return (y_intercept);
	return (x_intercept);
}

static	void get_col_dist(t_gdata *gdata, double x_vert, double y_vert)
{
	int	hor_dist;
	int	ver_dist;
	double	x_hor;
	double	y_hor;

	x_hor = wall_hit_hor(gdata, 0);
	y_hor = wall_hit_hor(gdata, 1);
	hor_dist = 999999999;
	ver_dist = 999999999;
	if (gdata->rdata->h_hit)
		hor_dist = get_distance(gdata->pdata->x, gdata->pdata->y, \
			x_hor, y_hor);
	if (gdata->rdata->v_hit)
		ver_dist = get_distance(gdata->pdata->x, gdata->pdata->y, \
			x_vert, y_vert);
	printf("HOR_DIST: %d\n", hor_dist);
	printf("VER_DIST: %d\n", ver_dist);
	gdata->rdata->h_dist = ver_dist * gdata->h_prop;
	if (hor_dist < ver_dist)
	{
		gdata->rdata->wall_x = x_hor;
		gdata->rdata->wall_y = y_hor;
		gdata->rdata->h_dist = hor_dist * gdata->w_prop;
	}
}

void	wall_hit(t_gdata *gdata)
{
	double x_vert;
	double y_vert;

	x_vert = wall_hit_vert(gdata, 0);
	y_vert = wall_hit_vert(gdata, 1);
	gdata->rdata->wall_x = x_vert;
	gdata->rdata->wall_y = y_vert;
	get_col_dist(gdata, x_vert, y_vert);
}
