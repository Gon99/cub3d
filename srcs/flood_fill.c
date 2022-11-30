/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:57:38 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/30 16:38:19 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	flood_fill(t_gdata *gdata, int x, int y)
{
	if (gdata->map[x][y] == '0' || is_player_letter(gdata->map[x][y]))
	{
		if (!is_player_letter(gdata->map[x][y]))
			gdata->map[x][y] = '2';
		flood_fill(gdata, x + 1, y);
		flood_fill(gdata, x - 1, y);
		flood_fill(gdata, x, y + 1);
		flood_fill(gdata, x, y - 1);
	}
}

void	flood_fill_check(t_gdata *gdata, t_pdata *pdata)
{
	int x = 0;
	while (gdata->map[x])
	{
		flood_fill(gdata, pdata->x, pdata->y);
//		printf("MAP: %s\n", map[x]);
		x++;
	}
	int r = 0;
	while (gdata->map[r])
	{
		printf("MAP[R]: %s\n", gdata->map[r]);
		r++;
	}
	printf("PX: %d\n", pdata->x);
	printf("PY: %d\n", pdata->y);
	printf("PX: %c\n", pdata->p);
//	printf("PX: %d\n", pdata->x);
//	printf("PY: %d\n", pdata->y);
}
