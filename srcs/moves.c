/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:22:28 by goliano-          #+#    #+#             */
/*   Updated: 2022/12/28 16:26:37 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up(t_gdata *gdata, t_pdata *pdata, int move_speed)
{
	if (!gdata->map[int(gdata->x + pdata->dir_x * move_speed)][int(gdata->y)])
		gdata->x += pdata->dir_x * move_speed;
	if (!gdata->map[int(gdata->x)][int(gdata->y + pdata->dir_y * move_speed)])
		gdata->y += pdata->dir_y * move_speed;
}

void	move_down(t_gdata *gdata, t_pdata *pdata, int move_speed)
{
	if (!gdata->map[int(gdata->x - pdata->dir_x * move_speed)][int(gdata->y)])
		gdata->x -= pdata->dir_x * move_speed;
	if (!gdata->map[int(gdata->x)][int(gdata->y - pdata->dir_y * move_speed)])
		gdata->y -= pdata->dir_y * move_speed;
}

void	move_right(t_gdata *gdata, t_pdata *pdata, int rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pdata->dir_x;
	pdata->dir_x = pdata->dir_x * cos(-rot_speed) - pdata->dir_y * sin(-rot_speed);
	pdata->dir_y = old_dir_x * sin(-rot_speed) + pdata->dir_y * cos(-rot_speed);
	old_plane_x = pdata->plane_x;
	pdata->plane_x = pdata->plane_x * cos(-rot_speed) - pdata->plane_y * sin(-rot_speed);
	pdata->plane_y = old_plane_x * sin(-rot_speed) + pdata->plane_y * cos(rot_speed);
}

void	move_left(t_gdata *gdata, t_pdata *pdata, int rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pdata->dir_x;
	pdata->dir_x = pdata->dir_x * cos(rot_speed) - pdata->dir_y * sin(rot_speed);
	pdata->dir_y = old_dir_x * sin(rot_speed) + pdata->dir_y * cos(rot_speed);
	old_plane_x = pdata->plane_x;
	pdata->plane_x = pdata->plane_x * cos(rot_speed) - pdata->plane_y * sin(rot_speed);
	pdata->plane_y = old_plane_x * sin(rot_speed) + pdata->plane_y * cos(rot_speed);
}
