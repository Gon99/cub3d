/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:16:19 by goliano-          #+#    #+#             */
/*   Updated: 2023/07/21 22:17:36 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 ** Initialization of variables.
 ** camera_x   -> Value in the x-axis of the camera_plane.
 ** ray_dir    -> Ray direction vector.
 ** map        -> Square of map where the ray is.
 ** delta_dist -> First step of ray move.
 **
 ** @param t_pdata *pdata Player struct;
 ** @param int x Vertical stripe;
 **
*/

static void	init_raycast(t_pdata *pdata, int x)
{
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;

	camera_x = 2 * x / (float)MAP_WIDTH - 1;
	ray_dir_x = pdata->dir_x + pdata->plane_x * camera_x;
	ray_dir_y = pdata->dir_y + pdata->plane_y * camera_x;
	pdata->map_x = (int)pdata->x;
	pdata->map_y = (int)pdata->y;
	pdata->delta_dist_x = fabs(1 / ray_dir_x);
	pdata->delta_dist_y = fabs(1 / ray_dir_y);
	pdata->camera_x = camera_x;
	pdata->ray_dir_x = ray_dir_x;
	pdata->ray_dir_y = ray_dir_y;
}

/*
 ** Calculate the initial distance of ray (side_dist).
 ** Indicates the step direction of ray (step).
 **
 ** t_pdata *pdata Player struct.
 **
*/

static void	get_ray_dir(t_pdata *pdata)
{
	if (pdata->ray_dir_x < 0)
	{	
		pdata->step_x = -1;
		pdata->side_dist_x = (pdata->x - pdata->map_x) * pdata->delta_dist_x;
	}
	else
	{
		pdata->step_x = 1;
		pdata->side_dist_x = (pdata->map_x + 1.0 - pdata->x) \
							* pdata->delta_dist_x;
	}
	if (pdata->ray_dir_y < 0)
	{
		pdata->step_y = -1;
		pdata->side_dist_y = (pdata->y - pdata->map_y) \
							* pdata->delta_dist_y;
	}
	else
	{
		pdata->step_y = 1;
		pdata->side_dist_y = (pdata->map_y + 1.0 - pdata->y) \
							* pdata->delta_dist_y;
	}
}

/*
 ** Perform DDA algorithm.
 ** Depends on the direction increments the ray 1 square until collision.
 ** Store the colision side of the ray 1 - N, 2 - S, 3 - E, 4 - W.
 **
 ** t_gdata *gdata Main struct;
 **
*/

//static void	do_dda(t_gdata *gdata)
//{
//	int		hit;
//	int		map_x;
//	int		map_y;
//	t_pdata	*pdata;
//
//	hit = 0;
//	pdata = gdata->pdata;
//	map_x = pdata->map_x;
//	map_y = pdata->map_y;
//	while (hit == 0)
//	{
//		if (pdata->side_dist_y > pdata->side_dist_x)
//		{
//			pdata->side_dist_x += pdata->delta_dist_x;
//			map_x += (pdata->step_x);
//			pdata->side = 4;
//			if (pdata->ray_dir_x > 0)
//				pdata->side = 3;
//		}
//		else
//		{
//			pdata->side_dist_y += pdata->delta_dist_y;
//			map_y += (pdata->step_y);
//			pdata->side = 2;
//			if (pdata->ray_dir_y > 0)
//				pdata->side = 1;
//		}
//		if (gdata->map[map_y][map_x] == '1')
//			hit = 1;
//	}
//	pdata->map_x = map_x;
//	pdata->map_y = map_y;
//}

/*
 ** Calculates the distance between the player and the wall.
 ** Depends on the side of the colision to calculate.
 **
 ** t_pdata *pdata Player struct;
 **
*/

static void	get_perp_wall_dist(t_pdata *pdata)
{
	int		x_weight;
	int		y_weight;
	float	perp;

	perp = pdata->perp;
	x_weight = (1 - pdata->step_x) / 2;
	y_weight = (1 - pdata->step_y) / 2;
	if (pdata->side == 3 || pdata->side == 4)
		perp = (pdata->map_x - (pdata->x) + x_weight) \
			/ pdata->ray_dir_x;
	else if (pdata->side == 1 || pdata->side == 2)
		perp = (pdata->map_y - (pdata->y) \
			+ y_weight) / pdata->ray_dir_y;
	pdata->perp = perp;
}

/*
 ** Main core function.
 ** Draw floor and ceiling and main algorithm.
 **
 ** t_gdata *gdata Main struct;
 **
 */

void	raycasting(t_gdata *gdata)
{
	int		x;
	t_pdata	*pdata;
	t_mdata	*mdata;

	x = 0;
	pdata = gdata->pdata;
	mdata = gdata->mdata;
	draw_floor(gdata, mdata);
	draw_ceiling(gdata, mdata);
	while (++x < MAP_WIDTH)
	{
		init_raycast(pdata, x);
		get_ray_dir(pdata);
		do_dda(gdata);
		get_perp_wall_dist(pdata);
		draw_wall(gdata, x);
	}
	mlx_put_image_to_window(mdata->ptr, mdata->win, mdata->win_img, 0, 0);
}
