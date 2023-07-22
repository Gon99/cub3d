/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:04:16 by ajimenez          #+#    #+#             */
/*   Updated: 2023/07/22 13:22:04 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

typedef struct do_draw_textured
{
	int	tex_x;
	int	tex_y;
	int	y;
}	t_do_draw_textured;

static void	draw_img(t_mdata *mdata, int x, int y, unsigned int color)
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

static void	do_draw_textured(t_gdata *gdata, int start, int end, int x)
{
	t_do_draw_textured	do_dda;
	float				step;
	float				texpos;
	float				perp;

	perp = gdata->pdata->perp;
	gdata->tdata->tex_num = get_tex_idx(gdata->pdata);
	do_dda.tex_x = get_wall_hit_x(gdata->pdata, perp) * (float)TEX_WIDTH;
	step = (float)TEX_HEIGHT / ((int)(MAP_HEIGHT / perp));
	texpos = ((start - (MAP_HEIGHT / 2) \
				+ ((int)(MAP_HEIGHT / perp)) / 2)) * step;
	do_dda.y = start;
	while (do_dda.y < end)
	{
		do_dda.tex_y = (int)texpos & (TEX_HEIGHT - 1);
		texpos += step;
		draw_img(gdata->mdata, x, do_dda.y, \
				gdata->tdata->tex_arr[gdata->tdata->tex_num][TEX_HEIGHT \
				* do_dda.tex_y + do_dda.tex_x]);
		do_dda.y++;
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
	int		line_height;
	int		start;
	int		end;
	float	perp;

	perp = gdata->pdata->perp;
	line_height = (int)(MAP_HEIGHT / perp);
	start = (MAP_HEIGHT / 2) - (line_height / 2);
	end = (MAP_HEIGHT / 2) + (line_height / 2);
	if (start < 0)
		start = 0;
	if (end > MAP_HEIGHT - 1)
		end = MAP_HEIGHT - 1;
	do_draw_textured(gdata, start, end, x);
}
