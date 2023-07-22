/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:53:39 by ajimenez          #+#    #+#             */
/*   Updated: 2023/07/21 22:14:18 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dda_ymayor(t_pdata *pdata, int *map_x)
{
	pdata->side_dist_x += pdata->delta_dist_x;
	*map_x += (pdata->step_x);
	pdata->side = 4;
	if (pdata->ray_dir_x > 0)
		pdata->side = 3;
}

void	update_side(t_pdata *pdata)
{
	pdata->side = 2;
	if (pdata->ray_dir_y > 0)
		pdata->side = 1;
}

void	do_dda(t_gdata *gdata)
{
	int		hit;
	int		map_x;
	int		map_y;
	t_pdata	*pdata;

	hit = 0;
	pdata = gdata->pdata;
	map_x = pdata->map_x;
	map_y = pdata->map_y;
	while (hit == 0)
	{
		if (pdata->side_dist_y > pdata->side_dist_x)
			dda_ymayor(pdata, &map_x);
		else
		{
			pdata->side_dist_y += pdata->delta_dist_y;
			map_y += (pdata->step_y);
			update_side(pdata);
		}
		if (gdata->map[map_y][map_x] == '1')
			hit = 1;
	}
	pdata->map_x = map_x;
	pdata->map_y = map_y;
}
//void	do_dda(t_gdata *gdata)
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
//			dda_ymayor(pdata, &map_x);
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
//
