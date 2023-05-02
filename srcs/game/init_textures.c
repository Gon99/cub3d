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
	}
	tdata->tex_arr = tex_arr;
}

static void	load_tex(t_tdata *tdata, t_mdata *mdata, void *tex, int tex_num)
{
	int	i;
	int	j;

	tdata->img_addr = mlx_get_data_addr(tex, &tdata->bpp, &tdata->ll, &tdata->end);
	if (!tdata->img_addr)
	{
		mlx_destroy_image(mdata->ptr, tex);
		exit(0);
	}
	i = 0;
	while (i < tdata->height)
	{
		j = 0;
		while (j < tdata->width)
		{
			tdata->tex_arr[tex_num][TEX_WIDTH * i + j] = tdata->img_addr[tdata->width * i + j];
			j++;
		}
	}
}

static void	*tex_chequer(t_tdata *tdata, t_mdata *mdata, char *tex)
{
	void	*ret;

	ret = mlx_xpm_file_to_image(mdata->ptr, \
		rm_nl(tex), &tdata->width, &tdata->height);
	if (!ret)
	{
		write(1, "Invalid texture\n", 16);
		exit(0);
	}
	return (ret);
}

void	init_textures(t_tdata *tdata, t_gdata *gdata, t_mdata *mdata)
{
	init_tex_arr(tdata);
	tdata->no_text = tex_chequer(tdata, mdata, gdata->no);
	load_tex(tdata, mdata, tdata->no_text, 0);
	tdata->so_text = tex_chequer(tdata, mdata, gdata->so);
	load_tex(tdata, mdata, tdata->so_text, 1);
	tdata->ea_text = tex_chequer(tdata, mdata, gdata->ea);
	load_tex(tdata, mdata, tdata->ea_text, 2);
	tdata->we_text = tex_chequer(tdata, mdata, gdata->we);
	load_tex(tdata, mdata, tdata->we_text, 3);
}
