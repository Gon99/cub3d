/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:17:41 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/27 17:35:24 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	hor_colision(t_gdata *gdata, float angle, int x)
{
	int		col;
	float	x_step;
	float	y_step;
	float	x_inter;
	float	y_inter;

	col = 0;
	y_step = get_y_step_hor(angle);
	x_step = get_x_step_hor(y_step, angle);
	x_inter = gdata->rdata->x_inter_h;
	y_inter = gdata->rdata->y_inter_h;
	while (!col)
	{
		if (player_colision(floor(y_inter / TILE_SIZE), floor(x_inter / TILE_SIZE), gdata))
		{
			col = 1;
			gdata->rdata->ray[x].h_hit = 1;
		}
		else
		{
			x_inter += x_step;
			y_inter += y_step;
		}
	}
	gdata->rdata->x_inter_h = x_inter;
	gdata->rdata->y_inter_h = y_inter;
}

void	wall_hit_hor(t_gdata *gdata, float angle, int x)
{
	float	y_inter;
	float	x_inter;

	y_inter = floor(gdata->pdata->y / TILE_SIZE) * TILE_SIZE;
	if (is_down(angle))
		y_inter += TILE_SIZE;
	x_inter = (y_inter - gdata->pdata->y) / tan(angle)\
				  + gdata->pdata->x;
	if (!is_down(angle))
		y_inter--;
	gdata->rdata->x_inter_h = x_inter;
	gdata->rdata->y_inter_h = y_inter;
	hor_colision(gdata, angle, x);
}

static	void	ver_colision(t_gdata *gdata, float angle, int x)
{
	int		col;
	float	x_inter;
	float	y_inter;
	float	x_step;
	float	y_step;

	col = 0;
	x_inter = gdata->rdata->x_inter_v;
	y_inter = gdata->rdata->y_inter_v;
	x_step = get_x_step_ver(angle);
	y_step = get_y_step_ver(angle);
	while (!col /*&& (x_inter >= 0 && y_inter >= 0 && x_inter < gdata->width && y_inter < gdata->height)*/)
	{
		if (player_colision(floor(y_inter / TILE_SIZE), floor(x_inter / TILE_SIZE), gdata))
		{
			col = 1;
			gdata->rdata->ray[x].v_hit = 1;
		}
		else
		{
			x_inter += x_step;
			y_inter += y_step;
		}
	}
	gdata->rdata->x_inter_v = x_inter;
	gdata->rdata->y_inter_v = y_inter;
}

void	wall_hit_ver(t_gdata *gdata, float angle, int x)
{
	float	x_inter;
	float	y_inter;

	x_inter = floor(gdata->pdata->x / TILE_SIZE) * TILE_SIZE;
	if (!is_left(angle))
		x_inter += TILE_SIZE;
	y_inter = (x_inter - gdata->pdata->x) \
		* tan(angle) + gdata->pdata->y;
	if (is_left(angle))
		x_inter--;
	gdata->rdata->x_inter_v = x_inter;
	gdata->rdata->y_inter_v = y_inter;
	ver_colision(gdata, angle, x);
}
//
//static	void get_col_dist(t_gdata *gdata, double x_vert, double y_vert)
//{
//	int	hor_dist;
//	int	ver_dist;
//	double	x_hor;
//	double	y_hor;
//
//	x_hor = wall_hit_hor(gdata, 0);
//	y_hor = wall_hit_hor(gdata, 1);
//	hor_dist = 999999999;
//	ver_dist = 999999999;
//	if (gdata->rdata->h_hit)
//		hor_dist = get_distance(gdata->pdata->x, gdata->pdata->y, x_hor, y_hor);
//	if (gdata->rdata->v_hit)
//		ver_dist = get_distance(gdata->pdata->x, gdata->pdata->y, x_vert, y_vert);
//	gdata->rdata->h_dist = ver_dist * gdata->h_prop;
//	if (hor_dist < ver_dist)
//	{
//		gdata->rdata->wall_x = x_hor;
//		gdata->rdata->wall_y = y_hor;
//		gdata->rdata->h_dist = hor_dist * gdata->w_prop;
//	}
//}
//
//void	wall_hit(t_gdata *gdata)
//{
//	double x_vert;
//	double y_vert;
//
//	x_vert = wall_hit_vert(gdata, 0);
//	y_vert = wall_hit_vert(gdata, 1);
//	gdata->rdata->wall_x = x_vert;
//	gdata->rdata->wall_y = y_vert;
//	get_col_dist(gdata, x_vert, y_vert);
//}
