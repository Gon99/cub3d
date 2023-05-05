/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:26:53 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/23 12:31:50 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_tex_arr(t_tdata *tdata)
{
	int	**tex_arr;
	int	*tex;
	int	i;
	int	tot;

	tex_arr = ft_calloc(sizeof(int *), 4);
	if (!tex_arr)
		return ;
	i = 0;
	tot = TEX_HEIGHT * TEX_WIDTH;
	while (i < 4)
	{
		tex = ft_calloc(sizeof(int), tot);
		if (!tex)
		{
			free(tex_arr);
			return ;
		}
		tex_arr[i] = tex;
		i++;
	}
	tdata->tex_arr = tex_arr;
}

static void	load_tex(t_tdata *tdata, t_mdata *mdata, int tex_num)
{
	int	x;
	int	y;

	mdata->win_addr = (int *)mlx_get_data_addr(mdata->win_img, \
		&mdata->bpp_win, &mdata->ll_win, &mdata->end_win);
	if (!mdata->win_addr)
	{
		mlx_destroy_image(mdata->ptr, mdata->win_img);
		exit(0);
	}
	x = 0;
	while (x < tdata->height)
	{
		y = 0;
		while (y < tdata->width)
		{
			tdata->tex_arr[tex_num][TEX_WIDTH * x + y] = \
				mdata->win_addr[tdata->width * x + y];
			y++;
		}
		x++;
	}
	mlx_destroy_image(mdata->ptr, mdata->win_img);
}

static void	tex_chequer(t_tdata *tdata, t_mdata *mdata, char *tex)
{

	mdata->win_img = mlx_xpm_file_to_image(mdata->ptr, \
		rm_nl(tex), &tdata->width, &tdata->height);
	if (!mdata->win_img)
	{
		write(1, "Invalid texture\n", 16);
		exit(0);
	}
}

void	init_textures(t_tdata *tdata, t_gdata *gdata, t_mdata *mdata)
{
	init_tex_arr(tdata);
	tex_chequer(tdata, mdata, gdata->no);
	load_tex(tdata, mdata, 0);
	tex_chequer(tdata, mdata, gdata->so);
	load_tex(tdata, mdata, 1);
	tex_chequer(tdata, mdata, gdata->ea);
	load_tex(tdata, mdata, 2);
	tex_chequer(tdata, mdata, gdata->we);
	load_tex(tdata, mdata, 3);
}
