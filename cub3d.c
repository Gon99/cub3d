/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2022/12/13 17:05:20 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <mlx.h>

static void	init_gdata(t_gdata *gdata)
{
	gdata->no = 0;
	gdata->so = 0;
	gdata->ea = 0;
	gdata->we = 0;
	gdata->f = 0;
	gdata->c = 0;
	gdata->file_len = 0;
	gdata->map_len = 0;
	gdata->error = 0;
}

static void	init_mlx(t_mdata *mdata, t_gdata *gdata)
{
	gdata->mlx = mlx_init();
	mdata->img = mlx_new_window(gdata->mlx, 1920, 1080, "Cub3d");
	mdata->addr = mlx_get_data_addr(mdata->img, &mdata->bpp, &mdata->line_length, &mdata->endian);
}

int	main(int argc, char **argv)
{
	t_gdata	gdata;
	t_pdata	pdata;
	t_mdata	mdata;
	(void)argc;

	if (map_name_chequer(argv[1]) < 0)
		return (write(1, "Error\n", 6));
	init_gdata(&gdata);
	if (!fill_map(argv[1], &gdata, &pdata))
		return (write(1, "Error\n", 6));
	flood_fill(&gdata, pdata.x, pdata.y);
	if (gdata.error)
		return (write(1, "Error\n", 6));
	init_mlx(&mdata, &gdata);
	start(&pdata);
	mlx_loop(gdata.mlx);
	printf("NO: %s\n", gdata.no);
	printf("SO: %s\n", gdata.so);
	printf("EA: %s\n", gdata.ea);
	printf("WE: %s\n", gdata.we);
	printf("F: %s\n", gdata.f);
	printf("C: %s\n", gdata.c);
	/*int i = 0;
	while (gdata.file[i])
	{
		printf("MAP: %s\n", gdata.file[i]);
		i++;
	}*/
	return (1);
}
