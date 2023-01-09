/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:19:17 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/09 10:21:33 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	hook_handler(int keycode, t_mdata *mdata)
{
	printf("KEYCODE: %d\n", keycode);
	/*if (keycode == 0)
		move_left();
	else if (keycode == 13)
		move_up();
	else if (keycode == 2)
		move_right();
	else if (keycode == 1)
		move_down();
	else if (keycode == 53)
	{
		mlx_destroy_window(mdata->mlx, mdata->win);
		exit(1);
	}*/
	if (keycode == 53)
	{
		mlx_destroy_window(mdata->mlx, mdata->win);
		exit(1);
	}
	return (0);
}
