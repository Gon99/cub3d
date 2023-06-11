/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:58:30 by goliano-          #+#    #+#             */
/*   Updated: 2023/05/16 18:12:17 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 ** Draw half bottom part of window.
 **
 ** @param t_gdata *gdata Main struct;
 ** @param t_mdata *mdata Mlx struct;
 **
*/
void	draw_floor(t_gdata *gdata, t_mdata *mdata)
{
	int 	i;
	int	limit;
	int	color;

	i = 0;
	limit = MAP_WIDTH * MAP_HEIGHT / 2;
	color = parse_color(gdata->f);
	while (i < limit)
	{
		mdata->win_addr[i] = color;
		i++;
	}
}
/*
 ** Draw half top part of window.
 **
 ** @param t_gdata *gdata Main struct;
 ** @param t_mdata *mdata Mlx struct;
*/
void	draw_ceiling(t_gdata *gdata, t_mdata *mdata)
{
	int	start;
	int	limit;
	int	color;

	start = MAP_WIDTH * MAP_HEIGHT / 2;
	limit = MAP_WIDTH * MAP_HEIGHT;
	color = parse_color(gdata->c);
	while (start < limit)
	{
		mdata->win_addr[start] = color;
		start++;
	}
}

/*
 ** Returns the value where the wall was hit.
 ** We use it later to calculate the x value of the texture.
 **
 ** @param t_pdata *pdata Player struct;
 ** @param float perp Perp distance to wall;
 ** @return float Position where the wall is hit;
*/
float	get_wall_hit_x(t_pdata *pdata, float perp)
{
	float	wall;
	int	side;

	side = pdata->side;
	if (side == 1 || side == 2)
		wall = pdata->x + perp * pdata->ray_dir_x;
	else
		wall = pdata->y + perp * pdata->ray_dir_y;
	wall -= floor(wall);
	return (wall);
}

/*
 ** Returns the position in the array_texture depending on the side hit;
 ** 0 -> N, 1 -> S, 2 -> E, 3 -> W.
 **
 ** @param t_pdata *pdata Player struct;
 ** @return int The idx of the texture in the array;
*/
int	get_tex_idx(t_pdata *pdata)
{
	int	side;
	int	idx;

	side = pdata->side;
	idx = 3;
	if (side == 1)
		idx = 0;
	else if (side == 2)
		idx = 1;
	else if (side == 3)
		idx = 2;
	return (idx);
}

void	draw_img(t_mdata *mdata, int x, int y, unsigned int color)
{
	mdata->win_addr[MAP_WIDTH * y + x] = color;
}

/*
 ** Second main draw function.
 ** Needed calculations and draw textured wall in window.
 **
 ** @param t_gdata *gdata Main struct;
 ** @param int start Integer value to start the wall draw;
 ** @param int end Integer value to end the dall draw;
 ** @param int x Vertical stripe;
*/
void	do_draw_textured(t_gdata *gdata, int start, int end, int x)
{
	int	tex_x;
	int	tex_y;
	int	y;
	float	step;
	float	texpos;

	int half = MAP_HEIGHT / 2;
	float perp = gdata->pdata->perp;
	gdata->tdata->tex_num = get_tex_idx(gdata->pdata);
	tex_x = get_wall_hit_x(gdata->pdata, perp) * (float)TEX_WIDTH;
	step = (float)TEX_HEIGHT / ((int)(MAP_HEIGHT / perp));
	texpos = ((start - half + ((int)(MAP_HEIGHT / perp)) / 2)) * step;
	y = start;
	while (y < end)
	{
		tex_y = (int)texpos & (TEX_HEIGHT - 1);
		texpos += step;
		draw_img(gdata->mdata, x, y, gdata->tdata->tex_arr[gdata->tdata->tex_num][TEX_HEIGHT * tex_y + tex_x]);
		y++;
	}
}

/*
 ** Main draw function.
 ** Calculates the size of the wall to draw, line_height.
 ** Calculates the limits of the wall to draw.
 **
 ** @param t_gdata *gdata Main struct;
 ** @param int x Vertical stripe;
 **
*/
void	draw_wall(t_gdata *gdata, int x)
{
	int	line_height;
	int	start;
	int	end;
	int	half;
	float	perp;

	perp = gdata->pdata->perp;
	half = MAP_HEIGHT / 2;
	line_height = (int)(MAP_HEIGHT / perp);
	start = half - (line_height / 2);
	end = half + (line_height / 2);
	if (start < 0)
		start = 0;
	if (end > MAP_HEIGHT - 1)
		end = MAP_HEIGHT - 1;
	do_draw_textured(gdata, start, end, x);
}
