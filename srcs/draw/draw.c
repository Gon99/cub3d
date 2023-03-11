/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:58:30 by goliano-          #+#    #+#             */
/*   Updated: 2023/03/01 18:48:52 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

inline static void	my_mlx_pixel_put(t_mdata *mdata, int x, int y, int color)
{
	//char	*dst;

	//Align bytes, line_length differs from the window with
	*(unsigned int *)(mdata->win_addr + (y * mdata->ll_win + x * (mdata->bpp_win / 8))) = color;
}

void	draw_ceiling(t_gdata *gdata/*, int x, int y0*/)
{
//	int	y;
//
//	y = 0;
//	while (y < y0)
//	{
//		my_mlx_pixel_put(gdata->mdata, x, y, parse_color(gdata->c));
//		y++;
//	}
	int 	i;
	int		limit;

	i = 0;
	limit = MAP_WIDTH * MAP_HEIGHT / 2;
	while (i < limit)
	{
		((unsigned int*)gdata->mdata->win_addr)[i] = 0xFF0000;
		i++;
	}
}

void	draw_floor(t_gdata *gdata/*, int x, int y1*/)
{
	int	start;
	int	limit;

	start = MAP_WIDTH * MAP_HEIGHT / 2;
	limit = MAP_WIDTH * MAP_HEIGHT;
	while (start < limit)
	{
		((unsigned int*)gdata->mdata->win_addr)[start] = 0xFFA500;
		start++;
	}
//	while (y1 < MAP_HEIGHT)
//	{
//		my_mlx_pixel_put(gdata->mdata, x, y1, parse_color(gdata->f));
//		y1++;
//	}
}

void	draw_wall(t_gdata *gdata, int y0, int y1, int x)
{
	while (y0 < y1)
	{
		my_mlx_pixel_put(gdata->mdata, x, y0, parse_color("0, 0, 0"));
		y0++;
	}
}

/* PINTA EL MAPA (TECHO Y SUELO) */
//void	draw_first_part_map(t_gdata *gdata)
//{
//	int	x;
//	int	y;
//	int	middle;
//
//	x = -1;
//	middle = MAP_HEIGHT / 2;
//	while (++x < MAP_WIDTH)
//	{
//		y = -1;
//		while (++y < middle)
//			my_mlx_pixel_put(gdata->mdata, x, y, parse_color(gdata->f));
//		while (++y < MAP_HEIGHT)
//			my_mlx_pixel_put(gdata->mdata, x, y, parse_color(gdata->c));
//	}
//}

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

/*static void	draw_col_line(int x_dest, int y_dest, t_gdata *gdata)
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
}*/

/*void	render_wall(t_gdata *gdata)
{
	int	tile_heigth = 200;
	double	plane_dist = (MAP_WIDTH / 2) / tan(HALF_FOV);
	printf("PLANE: %f\n", plane_dist);
	//CALCULAMOS DONDE EMPIEZA Y ACABA LA LÍNEA

	float aux;
	int x = 0;
	printf("N_RAYS: %d\n", gdata->rdata->n_rays);
	while (x < gdata->rdata->n_rays)
	{
		double	wall_heigth = tile_heigth / gdata->rdata->ray[x].y_dest * plane_dist;
		float y0 = MAP_HEIGHT / 2 - (int)wall_heigth / 2;
		float y1 = y0 + tile_heigth;
		printf("WALL: %f\n", wall_heigth);
		printf("y0: %f\n", y0);
		printf("XDEST: %f\n", gdata->rdata->ray[x].x_dest);
		printf("YDEST: %f\n", gdata->rdata->ray[x].y_dest);
		aux = y0;
		while (aux < y1)
		{
			my_mlx_pixel_put(gdata->mdata, x, aux, parse_color("0, 0, 0"));
			aux++;
		}
		x++;
	}
}*/

//void	render_wall(t_gdata *gdata)
//{
//	int	x;
//	int	y0;
//	int	y1;
//	float	plane_dist;
//	float	wall_height;
//
////	double	rad = to_radians(HALF_FOV);
////	printf("TN: %f\n", tan(rad));
////	plane_dist = (MAP_WIDTH / 2) / tan(HALF_FOV);
//	plane_dist = (MAP_WIDTH / 2) / tan(to_radians(HALF_FOV));
////	printf("PLANE: %f\n", plane_dist);
////	printf("HF: %f\n", HALF_FOV);
////	printf("T: %f\n", tan(HALF_FOV));
////	printf("PLANE: %f\n", plane_dist);
////	if (plane_dist < 0)
////		plane_dist *= -1;
//	x = 0;
//	while (x < gdata->rdata->n_rays)
//	{
//		wall_height = (10 / gdata->rdata->ray[x].dist) * plane_dist;
//		y0 = (int)MAP_HEIGHT / 2 - (int)wall_height / 2;
//		y1 = y0 + wall_height;
//		draw_ceiling(gdata, x, y0);
//		draw_wall(gdata, y0, y1, x);
//		draw_floor(gdata, x, y1);
//		x++;
//	}
//}
//void	draw_rays(t_gdata *gdata, int y_dest)
//{
//	int	i = 0;
//	
//	while (i < gdata->rdata->n_rays)
//	{
//		double y_len = gdata->rdata->ray[i].y - y_dest;
//		if (gdata->rdata->ray[i].y < y_dest)
//			y_len = y_dest - gdata->rdata->ray[i].y;
////		printf("Y_LEN: i: %f %d\n", y_len, i);
//		int x = 0;
//		double aux_px = gdata->rdata->ray[i].x * gdata->w_prop;
//		double aux_py = gdata->rdata->ray[i].y * gdata->h_prop;
//		double	x_step = gdata->pdata->vel * cos(gdata->rdata->ray[i].angle);
//		double	y_step = gdata->pdata->vel * sin(gdata->rdata->ray[i].angle);
//		while (x < y_len * gdata->h_prop)
//		{
//			my_mlx_pixel_put(gdata->mdata, aux_px, aux_py, parse_color("0, 0, 0"));
//			aux_px += x_step;
//			aux_py += y_step;
//			x++;
//		}
//		i++;
//	}
//}

//void	draw_all(t_gdata *gdata/*, int x_dest, int y_dest*/)
//{
////	mlx_destroy_image(gdata->mdata->ptr, gdata->mdata->win_img);
//////	mlx_clear_window(gdata->mdata->ptr, gdata->mdata->win);
////	gdata->mdata->win_img = mlx_new_image(gdata->mdata->ptr, MAP_WIDTH, MAP_HEIGHT);
////	gdata->mdata->win_addr = mlx_get_data_addr(gdata->mdata->win_img, &gdata->mdata->bpp_win, &gdata->mdata->ll_win, &gdata->mdata->end_win);
////	draw_first_part_map(gdata);
////	draw_col_line(x_dest, y_dest, gdata); // PINTA LA LINEA DE COLISIÓN HASTA QUE ENCUENTRA UNA PARED
////	draw_dir_line(gdata); // PINTA LA LINEA PEQUEÑA
////	draw_rays(gdata, y_dest);
//	render_wall(gdata);
////	my_mlx_pixel_put(gdata->mdata, gdata->pdata->x * gdata->w_prop, gdata->pdata->y * gdata->h_prop, parse_color("0, 0, 0"));
//}
