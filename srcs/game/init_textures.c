/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:26:53 by ajimenez          #+#    #+#             */
/*   Updated: 2023/05/16 18:08:39 by ajimenez         ###   ########.fr       */
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

static void	load_tex(t_tdata *tdata, t_mdata *aux, int tex_num, t_mdata *mdata)
{
	int	x;
	int	y;

	aux->win_addr = (int *)mlx_get_data_addr(aux->win_img, \
		&aux->bpp_win, &aux->ll_win, &aux->end_win);
//	printf("LL: %d\n", aux->ll_win);
//	printf("END: %d\n", aux->end_win);
//	printf("BPP: %d\n", aux->bpp_win);
	if (!aux->win_addr)
	{
		mlx_destroy_image(mdata->ptr, aux->win_img);
		exit(0);
	}
	y = 0;
	while (y < aux->img_h)
	{
		x = 0;
		while (x < aux->img_w)
		{
			tdata->tex_arr[tex_num][TEX_WIDTH * y + x] = \
				aux->win_addr[aux->img_w * y + x];
//			printf("VAL: %d\n", aux->win_addr[aux->img_w*y+x]);
//			printf("W: %d\n", aux->img_w);
//			printf("Y: %d\n", y);
//			printf("X: %d\n", x);
//			printf("---------------\n");
			x++;
		}
//		printf("VUELTA: %d\n", c);
		y++;
	}
	mlx_destroy_image(mdata->ptr, aux->win_img);
}

static void	tex_chequer(t_mdata *mdata, t_mdata *aux, char *tex)
{

	aux->win_img = mlx_xpm_file_to_image(mdata->ptr, \
		rm_nl(tex), &aux->img_w, &aux->img_h);
//	printf("W: %d\n", aux->img_w);
//	printf("H: %d\n", aux->img_h);
//	printf("TEX: %s\n", rm_nl(tex));
//	printf("WIN: %p\n", aux->win_img);
	if (!aux->win_img)
	{
		write(1, "Invalid texture\n", 16);
		exit(0);
	}
}

void	init_textures(t_tdata *tdata, t_gdata *gdata, t_mdata *mdata)
{
	t_mdata aux;

	init_tex_arr(tdata);
	tex_chequer(mdata, &aux, gdata->no);
	load_tex(tdata, &aux, 0, mdata);
	tex_chequer(mdata, &aux, gdata->so);
	load_tex(tdata, &aux, 1, mdata);
	tex_chequer(mdata, &aux, gdata->ea);
	load_tex(tdata, &aux, 2, mdata);
	tex_chequer(mdata, &aux, gdata->we);
	load_tex(tdata, &aux, 3, mdata);
}
