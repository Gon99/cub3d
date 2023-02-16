/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:48:19 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/16 17:51:21 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_x_step(double y_step, double angle)
{
	double	step;

	step = y_step / tan(angle);
	if ((is_left(angle) && step > 0) || (!is_left(angle) && step < 0))
		step = -step;
	return (step);
}

double	get_y_step(double angle)
{
	double	step;

	step = 1;
	if (!is_down(angle))
		step = -step;
	return (step);
}
