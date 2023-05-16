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

//inline static void	my_mlx_pixel_put(t_mdata *mdata, int x, int y, int color)
//{
//	*(unsigned int *)(mdata->win_addr + \
//	(y * mdata->ll_win + x * (mdata->bpp_win / 8))) = color;
//}

void	draw_ceiling(t_mdata *mdata)
{
	int 	i;
	int	limit;

	i = 0;
	limit = MAP_WIDTH * MAP_HEIGHT / 2;
	while (i < limit)
	{
		mdata->win_addr[i] = 0xFF0000;
		i++;
	}
}

void	draw_floor(t_mdata *mdata)
{
	int	start;
	int	limit;

	start = MAP_WIDTH * MAP_HEIGHT / 2;
	limit = MAP_WIDTH * MAP_HEIGHT;
	while (start < limit)
	{
		mdata->win_addr[start] = 0xFFA500;
		start++;
	}
}

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
//	mdata->win_addr[MAP_WIDTH * y + x] = 0x000000;
	mdata->win_addr[MAP_WIDTH * y + x] = color;
}

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
//	printf("SIDE: %d\n", gdata->pdata->side);
//	printf("TEXNUM: %d\n", gdata->tdata->tex_num);
//	printf("TEX_X: %d\n", tex_x);
//	printf("STEP: %f\n", step);
//	printf("TEXPOS: %f\n", texpos);
//	printf("--------------\n");
//	printf("Y: %d\n", y);
//	printf("END: %d\n", end);
	while (y < end)
	{
		tex_y = (int)texpos & (TEX_HEIGHT - 1);
		texpos += step;
//		printf("X: %d\n", x);
//		printf("Y: %d\n", y);
//		printf("TEX_Y: %d\n", tex_y);
//		printf("TEX_POS: %f\n", texpos);
//		break ;
		draw_img(gdata->mdata, x, y, gdata->tdata->tex_arr[gdata->tdata->tex_num][TEX_HEIGHT * tex_y + tex_x]);
		y++;
	}
}

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
