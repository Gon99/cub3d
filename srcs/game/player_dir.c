/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:22:13 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/16 16:38:16 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_down(double angle)
{
	int	down;

	down = 0;
	if (angle < M_PI)
		down = 1;
	return (down);
}

int	is_left(double angle)
{
	int	left;

	left = 0;
	if (angle < 3 * M_PI / 2 && angle > M_PI / 2)
		left = 1;
	return (left);
}
