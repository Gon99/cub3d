/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/16 14:01:03 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	main(int argc, char **argv)
{
	t_gdata	*gdata;
	t_pdata	*pdata;
	t_mlx	*mlx;
	t_tdata	*tdata;
	(void)argc;

	if (map_name_chequer(argv[1]) < 0)
		return (write(1, "Error name\n", 11));
	init_gdata(gdata, pdata);
	if (!fill_map(argv[1], gdata))
		return (write(1, "Error data\n", 11));
	init_pdata(gdata->map, pdata);
	flood_fill(gdata, pdata->x, pdata->y);
	if (gdata->error)
		return (write(1, "Error\n", 6));
	
	return (1);
}
