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

void	flood_fill(t_gdata *gdata, int x, int y)
{
	if (!gdata->map[x])
	{
		gdata->error = 1;
		return ;
	}
	if (gdata->map[x][y] == '0' || is_player_letter(gdata->map[x][y]))
	{
//		if (!is_player_letter(gdata->map[x][y]))
		gdata->map[x][y] = '2';
//		else
//			gdata->map[x][y] = '4';
		flood_fill(gdata, x + 1, y);
		flood_fill(gdata, x - 1, y);
		flood_fill(gdata, x, y + 1);
		flood_fill(gdata, x, y - 1);
	}
}
