/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:22:28 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/23 12:25:06 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_ws(t_gdata *gdata, int t)
{
	t_pdata *pdata;

	pdata = gdata->pdata;
	if (t == 1)
	{
		if (gdata->map[(int)pdata->y][(int)(pdata->x + pdata->dir_x * SPEED)] != '1')
			pdata->x += pdata->dir_x * SPEED;
		if (gdata->map[(int)(pdata->y + pdata->dir_y * SPEED)][(int)pdata->x] != '1')
			pdata->y += pdata->dir_y * SPEED;
	}
	if (t == 3)
	{
		if (gdata->map[(int)pdata->y][(int)(pdata->x - pdata->dir_x * SPEED)] != '1')
			pdata->x -= pdata->dir_x * SPEED;
		if (gdata->map[(int)(pdata->y - pdata->dir_y * SPEED)][(int)pdata->x] != '1')
			pdata->y -= pdata->dir_y * SPEED;
	}
}

void	move_ad(t_gdata *gdata, int t)
{
	t_pdata *pdata;

	pdata = gdata->pdata;
	if (t == 2)
	{
		if (gdata->map[(int)pdata->y][(int)(pdata->x - pdata->plane_x * SPEED)] != '1')
			pdata->x -= pdata->plane_x * SPEED;
		if (gdata->map[(int)(pdata->y - pdata->plane_y * SPEED)][(int)pdata->x] != '1')
			pdata->y -= pdata->plane_y * SPEED;
	}
	if (t == 4)
	{
		if (gdata->map[(int)pdata->y][(int)(pdata->x + pdata->plane_x * SPEED)] != '1')
			pdata->x += pdata->plane_x * SPEED;
		if (gdata->map[(int)(pdata->y + pdata->plane_y * SPEED)][(int)pdata->x] != '1')
			pdata->y += pdata->plane_y * SPEED;
	}
}

void	turn_right(t_gdata *gdata)
{
	float	aux;
	float	aux2;
	float	vspin;
	t_pdata	*pdata;

	pdata = gdata->pdata;
	aux = pdata->dir_x;
	vspin = pdata->vel_spin;
	pdata->dir_x = pdata->dir_x * cos(-vspin) - pdata->dir_y * sin(-vspin);
	pdata->dir_y = aux * sin(-vspin) + pdata->dir_y * cos(-vspin);
	aux2 = pdata->plane_x;
	pdata->plane_x = aux2 * cos(vspin) - pdata->plane_y * sin(-vspin);
	pdata->plane_y = aux2 * sin(-vspin) + pdata->plane_y * cos(-vspin);
}

void	turn_left(t_gdata *gdata)
{
	float	aux;
	float	aux2;
	float	vspin;
	t_pdata *pdata;

	pdata = gdata->pdata;
	aux = pdata->dir_x;
	vspin = pdata->vel_spin;
	pdata->dir_x = pdata->dir_x * cos(vspin) - pdata->dir_y * sin(vspin);
	pdata->dir_y = aux * sin(vspin) + pdata->dir_y * cos(vspin);
	aux2 = pdata->plane_x;
	pdata->plane_x = aux2 * cos(vspin) - pdata->plane_y * sin(vspin);
	pdata->plane_y = aux2 * sin(vspin) + pdata->plane_y * cos(vspin);
}
