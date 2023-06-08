/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:30:32 by ajimenez          #+#    #+#             */
/*   Updated: 2023/02/21 14:55:38 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 ** Init coordinates of player in map.
 **
 ** @param t_gdata *gdata global gdata struct.
*/

static void	init_player_coords(t_gdata *gdata)
{
	int	x;
	int	z;

	x = 0;
	while(gdata->map[x])
	{
		z = 0;
		while (gdata->map[x][z])
		{
			if (is_player_letter(gdata->map[x][z]))
			{
				gdata->pdata->x = z + 0.5;
				gdata->pdata->y = x + 0.5;
				gdata->pdata->p = gdata->map[x][z];
			}
			z++;
		}
		x++;
	}
	gdata->pdata->dir_x = 0.0;
	gdata->pdata->dir_y = 0.0;
	gdata->pdata->plane_x = 0.0;
	gdata->pdata->plane_y = 0.0; 
}

/*
 ** Init player struct.
 ** rir_   Direction vector of player.
 ** plane_ Plane vector.
 **
 ** @param t_gdata *gdata global gdata struct.
*/
void	init_pdata(t_gdata *gdata)
{
	init_player_coords(gdata);
	gdata->pdata->vel_spin = 0.08;
	if (gdata->pdata->p == 'N')
	{
		gdata->pdata->dir_y = 1;
		gdata->pdata->plane_x = 0.66;
	}
	else if (gdata->pdata->p == 'S')
	{
		gdata->pdata->dir_y = -1.0;
		gdata->pdata->plane_x = -0.66;
	}
	else if (gdata->pdata->p == 'E')
	{
		gdata->pdata->dir_x = 1.0;
		gdata->pdata->plane_y = -0.66;
	}
	else
	{
		gdata->pdata->dir_x = -1.0;
		gdata->pdata->dir_y = 0.66;
	}
}
