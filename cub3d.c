/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/09 10:27:28 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

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
	gdata->height = 1280;
	gdata->width = 1024;
}

static void	init_pdata(char **map, t_pdata *pdata)
{
	int	x;
	int	z;

	x = 0;
	while(map[x])
	{
		z = 0;
		while (map[x][z])
		{
			if (is_player_letter(map[x][z]))
			{
				pdata->x = x;
				pdata->y = z;
				pdata->p = map[x][z];
			}
			z++;
		}
		x++;
	}
	//initial direction of vector
	pdata->dir_x = -1;
	pdata->dir_y = 0;
	//the 2d raycaster version of camera plane
	pdata->plane_x = 0;
	pdata->plane_y = 0.66;
	//time of current frame
	pdata->time = 0;
	//time of previous frame
	pdata->old_time = 0;
}

static void	init_mlx(t_mdata *mdata, t_gdata *gdata)
{
	mdata->mlx = mlx_init();
	mdata->win = mlx_new_window(mdata->mlx, gdata->height, gdata->width, "Cub3d");
	mdata->addr = mlx_get_data_addr(mdata->win, &mdata->bpp, &mdata->line_length, &mdata->endian);
}

int	key_hook(int keycode, int x)
{
	printf("KEEEEEY: %d\n X: %d\n", keycode, x);
	return (0);
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
	if (!fill_map(argv[1], &gdata))
		return (write(1, "Error\n", 6));
	init_pdata(gdata.map, &pdata);
	flood_fill(&gdata, pdata.x, pdata.y);
	if (gdata.error)
		return (write(1, "Error\n", 6));
	init_mlx(&mdata, &gdata);
	start(&pdata, &gdata);
	mlx_hook(mdata.win, 2, 1L<<0, hook_handler, &mdata);
	mlx_key_hook(mdata.win, key_hook, 0);
	mlx_loop(mdata.mlx);
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
