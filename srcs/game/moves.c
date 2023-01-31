
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

void	move_ahead(t_gdata *gdata)
{
	gdata->pdata->move = 1;
/*	double	frame_time;
	double	move_speed;

	printf("UPP\n");
	printf("TIME: %f\n", gdata->pdata->time);
	printf("OLD_TIME: %f\n", gdata->pdata->old_time);
	frame_time = (gdata->pdata->time - gdata->pdata->old_time) / 1000.0;
	move_speed = frame_time * 5.0;
	printf("MOVE: %f\n", move_speed);
	printf("CALC: %d\n", (int)(gdata->pdata->x + gdata->pdata->dir_x * move_speed));
	if (gdata->map[(int)(gdata->pdata->x + gdata->pdata->dir_x * move_speed)][(int)gdata->pdata->y])
	{
		printf("ACT\n");
		gdata->pdata->x += gdata->pdata->dir_x * move_speed;
	}
	if (gdata->map[(int)gdata->pdata->x][(int)(gdata->pdata->y + gdata->pdata->dir_y * move_speed)])
	{
		printf("ACT2\n");
		gdata->pdata->y += gdata->pdata->dir_y * move_speed;
	}
	printf("----------------------\n");
	printf("XUP: %f\n", gdata->pdata->x);
	printf("YUP: %f\n", gdata->pdata->y);
	printf("----------------------\n");
	*/
}

void	move_back(t_gdata *gdata)
{
	gdata->pdata->move = -1;
	/*double	frame_time;
	double	move_speed;

	frame_time = (gdata->pdata->time - gdata->pdata->old_time) / 1000.0;
	move_speed = frame_time * 5.0;
	if (!gdata->map[(int)(gdata->pdata->x - gdata->pdata->dir_x * move_speed)][(int)gdata->pdata->y])
		gdata->pdata->x -= gdata->pdata->dir_x * move_speed;
	if (!gdata->map[(int)gdata->pdata->x][(int)(gdata->pdata->y - gdata->pdata->dir_y * move_speed)])
		gdata->pdata->y -= gdata->pdata->dir_y * move_speed;
		*/
}

void	turn_right(t_gdata *gdata)
{
	gdata->pdata->spin = 1;
/*	double	old_dir_x;
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
	*/
}

void	turn_left(t_gdata *gdata)
{
	gdata->pdata->spin = -1;
/*	double	old_dir_x;
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
	*/
}
