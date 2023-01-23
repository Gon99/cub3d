/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:16:48 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/23 13:59:39 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_mlx(t_mdata *mlx, char *msg)
{
	printf("%s\n", msg);
	mlx_destroy_window(mlx->ptr, mlx->win);
	//TODO -> Liberar
	exit(0);
	return (0);
}

static int	key_hooks(int keycode, t_gdata *gdata)
{
	if (keycode == 13 || keycode == 119)
		move_up(gdata);
	else if (keycode == 1 || keycode == 97)
		move_down(gdata);
	else if (keycode == 0 || keycode == 115)
		move_left(gdata);
	else if (keycode == 2 || keycode == 100)
		move_right(gdata);
	update_player(gdata->mdata, gdata->pdata, gdata);
	return (0);
}

static int	hook_handler(int keycode, t_mdata *mdata)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mdata->ptr, mdata->win);
		exit(1);
	}
	return (0);
}

void	hooks_call(void	*win, t_gdata *gdata, t_mdata *mdata)
{
	mlx_hook(mdata->win, 17, 1L << 1, close_mlx, mdata);
	mlx_key_hook(win, key_hooks, gdata);
	mlx_hook(win, 2, 1L<<0, hook_handler, mdata);
}
