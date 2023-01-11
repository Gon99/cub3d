/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/11 15:49:15 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	init_gdata(t_gdata *gdata, t_pdata *pdata)
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
	gdata->pdata = pdata;
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

void	init_textures(t_tdata *tdata, t_gdata *gdata, t_mdata *mdata)
{
	int height;
	int	width;

	tdata->no_text = mlx_xpm_file_to_image(mdata->mlx, rm_nl(gdata->no), &width, &height);
	tdata->so_text = mlx_xpm_file_to_image(mdata->mlx, rm_nl(gdata->so), &width, &height);
	tdata->ea_text = mlx_xpm_file_to_image(mdata->mlx, rm_nl(gdata->ea), &width, &height);
	tdata->we_text = mlx_xpm_file_to_image(mdata->mlx, rm_nl(gdata->we), &width, &height);
	if (!tdata->no_text || !tdata->so_text || !tdata->ea_text || !tdata->we_text)
	{
		write(1, "Invalid texture\n", 16);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_gdata	gdata;
	t_pdata	pdata;
	t_mdata	mdata;
	t_tdata	tdata;
	(void)argc;

	if (map_name_chequer(argv[1]) < 0)
		return (write(1, "Error name\n", 11));
	init_gdata(&gdata, &pdata);
	if (!fill_map(argv[1], &gdata))
		return (write(1, "Error data\n", 11));
	init_pdata(gdata.map, &pdata);
	flood_fill(&gdata, pdata.x, pdata.y);
	if (gdata.error)
		return (write(1, "Error\n", 6));
	init_mlx(&mdata, &gdata);
	init_textures(&tdata, &gdata, &mdata);
	/* 
	 * PUT IMAGES
	mlx_put_image_to_window(mdata.mlx, mdata.win, tdata.no_text, 0, 100);
	mlx_put_image_to_window(mdata.mlx, mdata.win, tdata.so_text, 0, 200);
	mlx_put_image_to_window(mdata.mlx, mdata.win, tdata.ea_text, 0, 300);
	mlx_put_image_to_window(mdata.mlx, mdata.win, tdata.we_text, 0, 0);
	*/
	start(&pdata, &gdata);
	ft_putmatrix(gdata.map);
	printf("NO: %s\n", gdata.no);
	printf("SO: %s\n", gdata.so);
	printf("EA: %s\n", gdata.ea);
	printf("WE: %s\n", gdata.we);
	printf("F: %s\n", gdata.f);
	printf("C: %s\n", gdata.c);
	hooks_call(mdata.win, &gdata, &mdata);
	mlx_loop(mdata.mlx);
	/*int i = 0;
	while (gdata.file[i])
	{
		printf("MAP: %s\n", gdata.file[i]);
		i++;
	}*/
	return (1);
}
