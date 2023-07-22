/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:26:53 by ajimenez          #+#    #+#             */
/*   Updated: 2023/06/21 18:42:36 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 ** Init texture array.
 ** Four textures to work NO(0) - SO(1) - EA(2) - WE(3).
 **
 ** @param t_tdata *tdata Texture array.
 **
 */
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

/*
 ** Texture association from mlx image to the texture array.
 ** NO = tex_num 0
 ** SO = tex_num 1
 ** EA = tex_num 2
 ** WE = tex_num 3
 **
 ** @param t_tdata *tdata Texture struct;
 ** @param t_mdata *mdata Aux mlx struct;
 ** @param int tex_num Index of the texture in the array;
 ** @param void *ptr Original Mlx pointer;
 **
*/

static void	load_tex(t_tdata *tdata, t_mdata *aux, int tex_num, void *ptr)
{
	int	x;
	int	y;

	aux->win_addr = (int *)mlx_get_data_addr(aux->win_img, \
		&aux->bpp_win, &aux->ll_win, &aux->end_win);
	if (!aux->win_addr)
	{
		mlx_destroy_image(ptr, aux->win_img);
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
			x++;
		}
		y++;
	}
	mlx_destroy_image(ptr, aux->win_img);
}

/*
 ** Assign the texture to and aux mlx img.
 ** Each img has his own height and width.
 **
 ** @param t_mdata *mdata Mlx struct;
 ** @param t_mdata *tdata Texture array;
 ** @param char *tex Texture path;
 **
*/
static void	tex_chequer(t_mdata *mdata, t_mdata *aux, char *tex)
{
	aux->win_img = mlx_xpm_file_to_image(mdata->ptr, \
		rm_nl(tex), &aux->img_w, &aux->img_h);
	if (!aux->win_img)
	{
		write(1, "Invalid texture\n", 16);
		exit(0);
	}
}

/*
 ** Initialize of textures, texture array creation, image association and values.
 **
 ** @param t_tdata *tdata Texture struct;
 ** @param t_gdata *gdata Global struct;
 ** @param t_mdata *mdata Mlx struct;
 **
 */
void	init_textures(t_tdata *tdata, t_gdata *gdata, t_mdata *mdata)
{
	t_mdata	aux;

	init_tex_arr(tdata);
	tex_chequer(mdata, &aux, gdata->no);
	load_tex(tdata, &aux, 0, mdata->ptr);
	tex_chequer(mdata, &aux, gdata->so);
	load_tex(tdata, &aux, 1, mdata->ptr);
	tex_chequer(mdata, &aux, gdata->ea);
	load_tex(tdata, &aux, 2, mdata->ptr);
	tex_chequer(mdata, &aux, gdata->we);
	load_tex(tdata, &aux, 3, mdata->ptr);
}
