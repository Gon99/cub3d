/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:22:28 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/09 11:28:19 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_gdata *gdata, t_pdata *pdata)
{
	double	frame_time;
	double	move_speed;

	frame_time = (pdata->time - pdata->old_time) / 1000.0;
	move_speed = frame_time * 5.0;
	if (!gdata->map[(int)(pdata->x + pdata->dir_x * move_speed)][(int)pdata->y])
		pdata->x += pdata->dir_x * move_speed;
	if (!gdata->map[(int)pdata->x][(int)(pdata->y + pdata->dir_y * move_speed)])
		pdata->y += pdata->dir_y * move_speed;
}

void	move_down(t_gdata *gdata, t_pdata *pdata)
{
	double	frame_time;
	double	move_speed;

	frame_time = (pdata->time - pdata->old_time) / 1000.0;
	move_speed = frame_time * 5.0;
	if (!gdata->map[(int)(pdata->x - pdata->dir_x * move_speed)][(int)pdata->y])
		pdata->x -= pdata->dir_x * move_speed;
	if (!gdata->map[(int)pdata->x][(int)(pdata->y - pdata->dir_y * move_speed)])
		pdata->y -= pdata->dir_y * move_speed;
}

void	move_right(t_pdata *pdata)
{
	double	old_dir_x;
	double	old_plane_x;
	double	frame_time;
	double	rot_speed;

	frame_time = (pdata->time - pdata->old_time) / 1000.0;
	rot_speed = frame_time * 3.0;
	old_dir_x = pdata->dir_x;
	pdata->dir_x = pdata->dir_x * cos(-rot_speed) - pdata->dir_y * sin(-rot_speed);
	pdata->dir_y = old_dir_x * sin(-rot_speed) + pdata->dir_y * cos(-rot_speed);
	old_plane_x = pdata->plane_x;
	pdata->plane_x = pdata->plane_x * cos(-rot_speed) - pdata->plane_y * sin(-rot_speed);
	pdata->plane_y = old_plane_x * sin(-rot_speed) + pdata->plane_y * cos(rot_speed);
}

void	move_left(t_pdata *pdata)
{
	double	old_dir_x;
	double	old_plane_x;
	double	frame_time;
	double	rot_speed;

	frame_time = (pdata->time - pdata->old_time) / 1000.0;
	rot_speed = frame_time * 5.0;
	old_dir_x = pdata->dir_x;
	pdata->dir_x = pdata->dir_x * cos(rot_speed) - pdata->dir_y * sin(rot_speed);
	pdata->dir_y = old_dir_x * sin(rot_speed) + pdata->dir_y * cos(rot_speed);
	old_plane_x = pdata->plane_x;
	pdata->plane_x = pdata->plane_x * cos(rot_speed) - pdata->plane_y * sin(rot_speed);
	pdata->plane_y = old_plane_x * sin(rot_speed) + pdata->plane_y * cos(rot_speed);
}
