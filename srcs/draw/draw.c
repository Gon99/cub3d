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
	while (i < limit)
	{
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
	while (start < limit)
	{
		((unsigned int*)mdata->win_addr)[start] = 0xFFA500;
		start++;
	}
}

void	draw_wall(t_mdata *mdata, float perp, int x)
{
	int	line_height;
	int	start;
	int	end;
	int	half;

	half = MAP_HEIGHT / 2;
	line_height = (int)(MAP_HEIGHT / perp);
	start = half - (line_height / 2);
	end = half + (line_height / 2);
	if (start < 0)
		start = 0;
	if (end > MAP_HEIGHT - 1)
		end = MAP_HEIGHT - 1;
	while (start < end)
	{
		my_mlx_pixel_put(mdata, x, start, parse_color("0, 0, 0"));
		start++;
	}
}
