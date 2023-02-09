/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:58:30 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/09 15:17:27 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* PINTA EL MAPA (TECHO Y SUELO) */
void	draw_first_part_map(t_gdata *gdata)
{
	int	x;
	int	y;
	int	middle;

	x = -1;
	middle = MAP_HEIGHT / 2;
	while (++x < MAP_WIDTH)
	{
		y = 0;
		while (++y < middle)
			my_mlx_pixel_put(gdata->mdata, x, y, parse_color(gdata->f));
		while (++y < MAP_HEIGHT)
			my_mlx_pixel_put(gdata->mdata, x, y, parse_color(gdata->c));
	}
}

/*static void	draw_dir_line(t_gdata *gdata)
{
	float	aux_px = gdata->pdata->x * gdata->w_prop;
	float	aux_py = gdata->pdata->y * gdata->h_prop;
	float	x_line;
	float	y_line;

	x_line = aux_px + cos(gdata->pdata->angle) * 20;
	y_line = aux_py + sin(gdata->pdata->angle) * 20;
	float c1 = x_line - aux_px;
	float c2 = y_line - aux_py;
	int hip = sqrt(pow(c1, 2) + pow(c2, 2));
	int c = 0;
	float x_step = x_line / hip;
	float y_step = y_line / hip;
	while (c < hip)
	{
		my_mlx_pixel_put(gdata->mdata, aux_px, aux_py, parse_color("0, 0, 0"));
		if (aux_px < x_line)
			aux_px += x_step;
		if (aux_py < y_line)
			aux_py += y_step;
		if (aux_px > x_line)
			aux_px -= x_step;
		if (aux_py > y_line)
			aux_py -= y_step;
		c++;
	}
}*/

static void	draw_col_line(int x_dest, int y_dest, t_gdata *gdata)
{
	float	aux_px;
	float	aux_py;
	int	y_len;
	int	x_len;
	int	c = 0;

	y_len = y_dest - gdata->pdata->y;
	x_len = x_dest - gdata->pdata->x;
	if (gdata->pdata->y > y_dest)
		y_len = gdata->pdata->y - y_dest;
	if (gdata->pdata->x > x_dest)
		x_len = gdata->pdata->x - x_dest;
	aux_px = gdata->pdata->x * gdata->w_prop;
	aux_py = gdata->pdata->y * gdata->h_prop;
//	int mul = y_dest * gdata->h_prop;
	float inc_x = gdata->pdata->vel * cos(gdata->pdata->angle);
	float inc_y = gdata->pdata->vel * sin(gdata->pdata->angle);
	while (c < y_len * gdata->h_prop || c < x_len * gdata->w_prop)
	{
		my_mlx_pixel_put(gdata->mdata, aux_px, aux_py, parse_color("0, 0, 0"));
		aux_px += inc_x;
		aux_py += inc_y;
//		if (aux_py > mul)
//			aux_py--;
//		if (aux_py < mul)
//			aux_py++;
		c++;
	}
}

void	render_wall(t_gdata *gdata)
{
	int	tile_heigth = 20;
	double	plane_dist = (gdata->width / 2) / tan(HALF_FOV);
	double	wall_heigth = tile_heigth / gdata->rdata->h_dist * plane_dist;
	//CALCULAMOS DONDE EMPIEZA Y ACABA LA LÍNEA
	float y0 = (int)gdata->height / 2 - wall_heigth / 2;
	float y1 = y0 + tile_heigth;

	float aux = y0;
	int x = 0;
	printf("Y0: %f\n", y0);
	printf("Y1: %f\n", y1);
	while (x < gdata->rdata->n_rays)
	{
		aux = y0;
		while (aux < y1)
		{
			my_mlx_pixel_put(gdata->mdata, x, aux, parse_color("0, 0, 0"));
			aux++;
		}
		x++;
	}
}

void	draw_all(t_gdata *gdata, int x_dest, int y_dest)
{
	gdata->mdata->win_img = mlx_new_image(gdata->mdata->ptr, MAP_WIDTH, MAP_HEIGHT);
	gdata->mdata->win_addr = mlx_get_data_addr(gdata->mdata->win_img, &gdata->mdata->bpp_win, &gdata->mdata->ll_win, &gdata->mdata->end_win);
	draw_first_part_map(gdata);
	draw_col_line(x_dest, y_dest, gdata); // PINTA LA LINEA DE COLISIÓN HASTA QUE ENCUENTRA UNA PARED
//	draw_dir_line(gdata); // PINTA LA LINEA PEQUEÑA
	render_wall(gdata);
	my_mlx_pixel_put(gdata->mdata, gdata->pdata->x * gdata->w_prop, gdata->pdata->y * gdata->h_prop, parse_color("0, 0, 0"));
	mlx_put_image_to_window(gdata->mdata->ptr, gdata->mdata->win, gdata->mdata->win_img, 0, 0);
}
