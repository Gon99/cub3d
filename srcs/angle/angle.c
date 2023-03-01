/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:51:22 by goliano-          #+#    #+#             */
/*   Updated: 2023/03/01 15:50:10 by goliano-         ###   ########.fr       */
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
	//TODO -> resetea a 0 el angulo
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
	{
		angle = angle + (2 * M_PI);
	}
	return (angle);
}

void	set_angle(double angle, int i, t_gdata *gdata)
{
//	NO HACE FALTA SE HACE EN PLAYR_MOVE PONERLO EN UNO DE LOS DOS LADOS
//	gdata->pdata->angle = angle;
	//gdata->rdata->ray[i].angle = normalize_angle(angle + gdata->rdata->ray[i].angle_inc);
	gdata->rdata->ray[i].angle = angle + gdata->rdata->ray[i].angle_inc;
//	printf("ANGLE: %f\n", gdata->rdata->ray[i].angle);
//	printf("ANGLE_INC: %f\n", gdata->rdata->ray[i].angle_inc);
}
