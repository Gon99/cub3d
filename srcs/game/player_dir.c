/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:22:13 by goliano-          #+#    #+#             */
/*   Updated: 2023/06/14 20:16:26 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_down(float angle)
{
	int	down;

	down = 0;
	if (angle < M_PI)
		down = 1;
	return (down);
}

int	is_left(float angle)
{
	int	left;

	left = 0;
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		left = 1;
	return (left);
}
