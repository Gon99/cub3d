/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:57:38 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/11 19:13:51 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 ** Checks if map is closed in the player mov range.
 **
 ** @param t_gdata *gdata The global struct;
 ** @param int y The position of the player in the y-axis;
 ** @param int x The position of the player in the x-axis;
*/
void	flood_fill(t_gdata *gdata, int y, int x)
{
	if (!gdata->map[y] || !gdata->map[y][x])
	{
		gdata->error = 1;
		return ;
	}
	if (gdata->map[y][x] == '0' || is_player_letter(gdata->map[y][x]))
	{
		gdata->map[y][x] = '2';
		flood_fill(gdata, y + 1, x);
		flood_fill(gdata, y - 1, x);
		flood_fill(gdata, y, x + 1);
		flood_fill(gdata, y, x - 1);
	}
}
