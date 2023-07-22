/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:51:22 by goliano-          #+#    #+#             */
/*   Updated: 2023/06/14 19:48:26 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	to_radians(double angle)
{
	angle = angle * (M_PI / 180);
	return (angle);
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
	{
		angle = angle + (2 * M_PI);
	}
	return (angle);
}

void	set_angle(double angle, int i, t_gdata *gdata)
{
	gdata->rdata->ray[i].angle = angle + gdata->rdata->ray[i].angle_inc;
}
