/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:22:28 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/09 16:45:06 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_gdata *gdata)
{
	double	frame_time;
	double	move_speed;

	frame_time = (gdata->pdata->time - gdata->pdata->old_time) / 1000.0;
	move_speed = frame_time * 5.0;
	if (!gdata->map[(int)(gdata->pdata->x + gdata->pdata->dir_x * move_speed)][(int)gdata->pdata->y])
		gdata->pdata->x += gdata->pdata->dir_x * move_speed;
	if (!gdata->map[(int)gdata->pdata->x][(int)(gdata->pdata->y + gdata->pdata->dir_y * move_speed)])
		gdata->pdata->y += gdata->pdata->dir_y * move_speed;
}

void	move_down(t_gdata *gdata)
{
	double	frame_time;
	double	move_speed;

	frame_time = (gdata->pdata->time - gdata->pdata->old_time) / 1000.0;
	move_speed = frame_time * 5.0;
	if (!gdata->map[(int)(gdata->pdata->x - gdata->pdata->dir_x * move_speed)][(int)gdata->pdata->y])
		gdata->pdata->x -= gdata->pdata->dir_x * move_speed;
	if (!gdata->map[(int)gdata->pdata->x][(int)(gdata->pdata->y - gdata->pdata->dir_y * move_speed)])
		gdata->pdata->y -= gdata->pdata->dir_y * move_speed;
}

void	move_right(t_gdata *gdata)
{
	double	old_dir_x;
	double	old_plane_x;
	double	frame_time;
	double	rot_speed;

	frame_time = (gdata->pdata->time - gdata->pdata->old_time) / 1000.0;
	rot_speed = frame_time * 3.0;
	old_dir_x = gdata->pdata->dir_x;
	gdata->pdata->dir_x = gdata->pdata->dir_x * cos(-rot_speed) - gdata->pdata->dir_y * sin(-rot_speed);
	gdata->pdata->dir_y = old_dir_x * sin(-rot_speed) + gdata->pdata->dir_y * cos(-rot_speed);
	old_plane_x = gdata->pdata->plane_x;
	gdata->pdata->plane_x = gdata->pdata->plane_x * cos(-rot_speed) - gdata->pdata->plane_y * sin(-rot_speed);
	gdata->pdata->plane_y = old_plane_x * sin(-rot_speed) + gdata->pdata->plane_y * cos(rot_speed);
}

void	move_left(t_gdata *gdata)
{
	double	old_dir_x;
	double	old_plane_x;
	double	frame_time;
	double	rot_speed;

	frame_time = (gdata->pdata->time - gdata->pdata->old_time) / 1000.0;
	rot_speed = frame_time * 3.0;
	old_dir_x = gdata->pdata->dir_x;
	gdata->pdata->dir_x = gdata->pdata->dir_x * cos(rot_speed) - gdata->pdata->dir_y * sin(rot_speed);
	gdata->pdata->dir_y = old_dir_x * sin(rot_speed) + gdata->pdata->dir_y * cos(rot_speed);
	old_plane_x = gdata->pdata->plane_x;
	gdata->pdata->plane_x = gdata->pdata->plane_x * cos(rot_speed) - gdata->pdata->plane_y * sin(rot_speed);
	gdata->pdata->plane_y = old_plane_x * sin(rot_speed) + gdata->pdata->plane_y * cos(rot_speed);
}
