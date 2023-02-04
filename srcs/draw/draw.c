/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:58:30 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/04 12:56:23 by goliano-         ###   ########.fr       */
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

static void	draw_dir_line(t_gdata *gdata)
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
//	printf("--------\n");
//	printf("X_LINE: %f\n", x_line);
//	printf("Y_LINE: %f\n", x_line);
//	printf("PX: %f\n", aux_px);
//	printf("PY: %f\n", aux_py);
//	printf("HIP: %d\n", hip);
//	printf("ANGLE: %f\n", pdata->angle);
//	printf("----------\n");
//	printf("Y: %f\n", y_line);
//	printf("HIP: %d\n", hip);
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
}

static void	draw_col_line(int x_dest, int y_dest, t_gdata *gdata)
{
	float	aux_px;
	float	aux_py;
	int	y_len = gdata->pdata->y - y_dest;
	int	c = 0;

	printf("----------COL:\n");
	printf("Y_LEN: %d\nY_LEN_PROP: %d\n", y_len, y_len * gdata->h_prop);
	printf("X_DEST: %d\n", x_dest);
	printf("Y_DEST: %d\n", y_dest);
	aux_px = gdata->pdata->x * gdata->w_prop;
	aux_py = gdata->pdata->y * gdata->h_prop;
	printf("AUX_PX_PROP: %f\n", aux_px);
	printf("AUX_PY_PROP: %f\n", aux_py);
	while (c <  y_len * gdata->h_prop)
	{
		my_mlx_pixel_put(gdata->mdata, aux_px, aux_py, parse_color("0, 0, 0"));
		aux_py--;
		c++;
	}
	printf("---------------\n");
	printf("---------------\n");
	printf("---------------\n");
}

void	draw_all(t_gdata *gdata, int x_dest, int y_dest)
{
	gdata->mdata->win_img = mlx_new_image(gdata->mdata->ptr, MAP_WIDTH, MAP_HEIGHT);
	gdata->mdata->win_addr = mlx_get_data_addr(gdata->mdata->win_img, &gdata->mdata->bpp_win, &gdata->mdata->ll_win, &gdata->mdata->end_win);
	draw_first_part_map(gdata);
	draw_col_line(x_dest, y_dest, gdata); // PINTA LA LINEA DE COLISIÓN HASTA QUE ENCUENTRA UNA PARED
	draw_dir_line(gdata); // PINTA LA LINEA PEQUEÑA
	my_mlx_pixel_put(gdata->mdata, gdata->pdata->x * gdata->w_prop, gdata->pdata->y * gdata->h_prop, parse_color("0, 0, 0"));
	mlx_put_image_to_window(gdata->mdata->ptr, gdata->mdata->win, gdata->mdata->win_img, 0, 0);
//	printf("----------------\n");
}
