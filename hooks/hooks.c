/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:19:17 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/09 16:53:12 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	key_hooks(int keycode, t_gdata *gdata)
{
	if (keycode == 13)
		move_up(gdata);
	else if (keycode == 1)
		move_down(gdata);
	else if (keycode == 0)
		move_left(gdata);
	else if (keycode == 2)
		move_right(gdata);
	return (0);
}

static int	hook_handler(int keycode, t_mdata *mdata)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mdata->mlx, mdata->win);
		exit(1);
	}
	return (0);
}

void	hooks_call(void	*win, t_gdata *gdata, t_mdata *mdata)
{
	mlx_key_hook(win, key_hooks, gdata);
	mlx_hook(win, 2, 1L<<0, hook_handler, &mdata);
}
