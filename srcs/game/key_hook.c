/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:16:48 by ajimenez          #+#    #+#             */
/*   Updated: 2023/06/14 20:16:03 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 ** Close window functionality.
 **
 ** @t_mdata *mdata Mlx struct;
 ** @return int Return 0;
 **
*/
static int	close_mlx(t_gdata *gdata, char *msg)
{
	t_mdata	*mlx;
	t_tdata	*tdata;

	mlx = gdata->mdata;
	tdata = gdata->tdata;
	printf("%s", msg);
	mlx_destroy_window(mlx->ptr, mlx->win);
	free_map(gdata);
	free_tex(tdata);
	exit(0);
	return (0);
}

/*
 ** Key 13  | 133 = w.
 ** Key 1   | 97  = s.
 ** Key 0   | 115 = a.
 ** Key 2   | 100 = d.
 ** Key 123 | 65363 = <-.
 ** Key 124 | 65361 = ->.
 **
 ** @param int key Integer representation of holded key;
 ** @return int The keycode represented in the program.
 **
*/
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

/*
 ** Key hook functionality.
 **
 ** @param int keycode Integer that represents the key;
 ** @param t_gdata *gdata Main struct;
 **
*/
static int	key_hooks_down(int keycode, t_gdata *gdata)
{
	int	type;

	type = key_type(keycode);
	if (keycode == ESC || keycode == ESC_L)
		close_mlx(gdata, "ESC\n");
	else if (type == 1 || type == 3)
		move_ws(gdata, type);
	else if (type == 2 || type == 4)
		move_ad(gdata, type);
	else if (type == 5)
		turn_right(gdata);
	else if (type == 6)
		turn_left(gdata);
	return (0);
}

/*
 ** Loop hook main function execution.
 ** 
 ** @param t_gdata *gdata Main struct;
 **
 */

static int	draw_n(t_gdata *gdata)
{
	raycasting(gdata);
	return (0);
}

/*
 ** Event association, player movement, window management.
 ** Loop hook, callback execution of main function.
 **
 ** @param t_gdata *gdata Global struct;
 ** @param t_mdata *mdata Mlx struct;
 **
 */

void	hooks_call(t_gdata *gdata, t_mdata *mdata)
{
	mlx_hook(mdata->win, 2, 1L << 0, key_hooks_down, gdata);
	mlx_loop_hook(mdata->ptr, draw_n, gdata);
}
