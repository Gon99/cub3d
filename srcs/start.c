/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:16:19 by goliano-          #+#    #+#             */
/*   Updated: 2022/12/13 17:05:18 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	start(t_pdata *pdata)
{
	int	x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	x = 0;
	while (1)
	{
		while (x < 10)
		{
			camera_x = 2 * x / double(10) - 1;
			ray_dir_x = pdata->dir_x + pdata->plane_x * camera_x;
			ray_dir_y = pdata->dir_y + pdata->plane_y * camera_x;
			x++;
		}
	}
}
