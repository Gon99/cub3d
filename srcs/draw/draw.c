/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:58:30 by goliano-          #+#    #+#             */
/*   Updated: 2023/07/22 13:20:55 by ajimenez         ###   ########.fr       */
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
	int	i;
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
	int		side;

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
