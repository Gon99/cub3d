/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:58:30 by goliano-          #+#    #+#             */
/*   Updated: 2023/03/01 18:48:52 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

inline static void	my_mlx_pixel_put(t_mdata *mdata, int x, int y, int color)
{
	*(unsigned int *)(mdata->win_addr + \
	(y * mdata->ll_win + x * (mdata->bpp_win / 8))) = color;
}

void	draw_ceiling(t_mdata *mdata)
{
	int 	i;
	int	limit;

	i = 0;
	limit = MAP_WIDTH * MAP_HEIGHT / 2;
	printf("LIM: %d\n", limit);
	while (i < limit)
	{
		printf("I: %d\n", i);
		((unsigned int*)mdata->win_addr)[i] = 0xFF0000;
		i++;
	}
}

void	draw_floor(t_mdata *mdata)
{
	int	start;
	int	limit;

	start = MAP_WIDTH * MAP_HEIGHT / 2;
	limit = MAP_WIDTH * MAP_HEIGHT;
	printf("IMG: %p\n", mdata->win_addr);
	while (start < limit)
	{
		printf("ST: %d\n", start);
		((unsigned int*)mdata->win_addr)[start] = 0xFFA500;
		start++;
	}
}

int	get_wall_hit_x(t_pdata *pdata, float perp)
{
	float	wall;
	int	side;

	side = pdata->side;
	if (side == 1 || side == 2)
		wall = pdata->x + perp * pdata->ray_dir_x;
	else
		wall = pdata->y + perp * pdata->ray_dir_y;
	wall -= (int)wall;
	return (wall);
}

int	get_texture_idx(t_pdata *pdata)
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
	mdata->win_addr[MAP_WIDTH * x + y] = color;
}

void	draw_wall(t_gdata *gdata, float perp, int x)
{
	int	line_height;
	int	start;
	int	end;
	int	half;
	int	tex_x;
	int	tex_y;
	float	step;
	float	tex_idx;
	int	tex_num;
	t_pdata *pdata;
	t_mdata *mdata;
	t_tdata *tdata;

	pdata = gdata->pdata;
	mdata = gdata->mdata;
	tdata = gdata->tdata;
	half = MAP_HEIGHT / 2;
	line_height = (int)(MAP_HEIGHT / perp);
	start = half - (line_height / 2);
	end = half + (line_height / 2);
	if (start < 0)
		start = 0;
	if (end > MAP_HEIGHT - 1)
		end = MAP_HEIGHT - 1;
	tex_x = get_wall_hit_x(pdata, perp);
	step = (float)TEX_HEIGHT / ((int)(MAP_HEIGHT / perp));
	tex_idx = ((start - half + ((int)(MAP_HEIGHT / perp)) / 2)) * step;
	tex_num = get_texture_idx(pdata);
	while (start < end)
	{
		tex_y = (int)tex_idx & (TEX_HEIGHT - 1);
		tex_idx += step;
	//	my_mlx_pixel_put(mdata, x, start, parse_color("0, 0, 0"));
		draw_img(mdata, x, start, tdata->tex_arr[tex_num][TEX_HEIGHT * tex_y + tex_x]);
		start++;
	}
}
