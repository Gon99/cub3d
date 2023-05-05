/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:26:05 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/23 16:54:13 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx(t_gdata *gdata)
{
	t_mdata *mdata;

	mdata = gdata->mdata;
	mdata->ptr = mlx_init();
	mdata->win = mlx_new_window(mdata->ptr, MAP_WIDTH, MAP_HEIGHT, "Cub3d");
	mdata->win_img = mlx_new_image(mdata->ptr, MAP_WIDTH, MAP_HEIGHT);
	mdata->win_addr = (int *)mlx_get_data_addr(mdata->win_img, \
		&mdata->bpp_win, &mdata->ll_win, &mdata->end_win);
	//gdata->mdata->map_img = mlx_new_image(gdata->mdata->ptr, gdata->width * TILE_SIZE, gdata->height * TILE_SIZE);
	//gdata->mdata->map_addr = mlx_get_data_addr(gdata->mdata->map_img, &gdata->mdata->bpp_map, &gdata->mdata->ll_map, &gdata->mdata->end_map);
//	mdata->img = mlx_new_image(mdata->mlx, gdata->height, gdata->width);
//	mdata->addr = mlx_get_data_addr(mdata->img, &mdata->bpp, &mdata->line_length, &mdata->endian);
}
