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

void	flood_fill(t_gdata *gdata, int y, int x)
{
	if (!gdata->map[y])
	{
		gdata->error = 1;
		return ;
	}
	if (gdata->map[y][x] == '0' || is_player_letter(gdata->map[y][x]))
	{
//		if (!is_player_letter(gdata->map[x][y]))
		gdata->map[y][x] = '2';
//		else
//			gdata->map[x][y] = '4';
		flood_fill(gdata, y + 1, x);
		flood_fill(gdata, y - 1, x);
		flood_fill(gdata, y, x + 1);
		flood_fill(gdata, y, x - 1);
	}
}
