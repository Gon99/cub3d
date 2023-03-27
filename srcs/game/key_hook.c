/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:16:48 by ajimenez          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:57 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	close_mlx(t_mdata *mlx, char *msg)
{
	printf("%s\n", msg);
	mlx_destroy_window(mlx->ptr, mlx->win);
	//TODO -> Liberar
	exit(0);
	return (0);
}

int	key_type(int key)
{
	int	type;

	type = 0;
	if (key == 13 || key == 119)
		type = 1;
	else if (key == 1 || key == 97)
		type = 2;
	else if (key == 0 || key == 115)
		type = 3;
	else if (key == 2 || key == 100)
		type = 4;
	else if (key == 124 || key == 65363)
		type = 5;
	else if (key == 123 || key == 65361)
		type = 6;
	return (type);
}

static int	key_hooks_up(int keycode, t_gdata *gdata)
{
	int	type;

	type = key_type(keycode);
	if (type >= 1 && type <= 4)
		gdata->pdata->move = 0;
	else if (type == 5 || type == 6)
		gdata->pdata->spin = 0;
//	if (type > 0 && type < 7)
//		update_player(gdata, keycode);
//	start(gdata, keycode);
//	update_player(gdata, keycode);
	return (0);
}


static int	key_hooks_down(int keycode, t_gdata *gdata)
{
	int	type;

	type = key_type(keycode);
	if (type == 1 || type == 4)
		move_ahead(gdata);
	else if (type == 2 || type == 3)
		move_back(gdata);
	else if (type == 5)
		turn_right(gdata);
	else if (type == 6)
		turn_left(gdata);
//	start(gdata, keycode);
	if (type > 0 && type < 7)
		update_player(gdata->pdata, gdata, keycode);
	return (0);
}

static int	draw_n(t_gdata *gdata)
{
	init_rays_group(gdata);
//	calc_rays_dist(gdata);
//	draw_all(gdata);
	return (0);
}

/*static int	hook_handler(int keycode, t_mdata *mdata)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mdata->ptr, mdata->win);
		exit(1);
	}
	return (0);
}*/

void	hooks_call(t_gdata *gdata, t_mdata *mdata)
{
	mlx_hook(mdata->win, 2, 1L << 0, key_hooks_down, gdata);
	mlx_hook(mdata->win, 3, 1L << 1, key_hooks_up, gdata);
	mlx_hook(mdata->win, 17, 1L << 1, close_mlx, mdata);
	mlx_loop_hook(mdata->ptr, draw_n ,gdata);
//	mlx_key_hook(win, key_hooks, gdata);
//	mlx_hook(win, 2, 1L<<0, hook_handler, mdata);
}
