/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:48:19 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/27 17:35:25 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_x_step_hor(float y_step, float angle)
{
	float	step;

	step = y_step / tan(angle);
	if ((is_left(angle) && step > 0) || (!is_left(angle) && step < 0))
		step *= -1;
	return (step);
}

float	get_y_step_hor(float angle)
{
	float	step;

	step = TILE_SIZE;
	if (!is_down(angle))
		step *= -1;
	return (step);
}

float	get_x_step_ver(float angle)
{
	float	step;

	step = TILE_SIZE;
	if (is_left(angle))
		step *= -1;
	return (step);

}

float	get_y_step_ver(float angle)
{
	float	step;

	step = TILE_SIZE * tan(angle);
	if ((step > 0 && !is_down(angle)) \
		|| (step < 0 && is_down(angle)))
			step *= -1;
	return (step);
}
