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

/*
 ** Init the mlx.
 ** Creates the window, image, and image address.
 ** Initializes the MAP_WIDTH and MAP_HEIGHT.
 **
 ** @param t_gdata *gdata The global struct;
 **
*/

void	init_mlx(t_gdata *gdata)
{
	t_mdata *mdata;

	mdata = gdata->mdata;
	mdata->ptr = mlx_init();
	mdata->win = mlx_new_window(mdata->ptr, MAP_WIDTH, MAP_HEIGHT, "Cub3d");
	mdata->win_img = mlx_new_image(mdata->ptr, MAP_WIDTH, MAP_HEIGHT);
	mdata->win_addr = (int *)mlx_get_data_addr(mdata->win_img, \
		&mdata->bpp_win, &mdata->ll_win, &mdata->end_win);
	mdata->img_w = MAP_WIDTH;
	mdata->img_h = MAP_HEIGHT;
}
