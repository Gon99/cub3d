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

void	init_mlx(t_mdata *mdata)
{
	mdata->ptr = mlx_init();
	mdata->win = mlx_new_window(mdata->ptr, MAP_WIDTH, MAP_HEIGHT, "Cub3d");
//	mdata->img = mlx_new_image(mdata->mlx, gdata->height, gdata->width);
//	mdata->addr = mlx_get_data_addr(mdata->img, &mdata->bpp, &mdata->line_length, &mdata->endian);
}
