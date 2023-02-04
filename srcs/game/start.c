/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:16:19 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/04 11:54:36 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_mdata *mdata, int x, int y, int color)
{
	char	*dst;

	//Align bytes, line_length differs from the window with
	dst = mdata->win_addr + (y * mdata->ll_win + x * (mdata->bpp_win / 8));
	*(unsigned int *)dst = color;
}

int	player_colision(int y, int x, t_gdata *gdata)
{
	int	col;

	col = 0;
	printf("XCOL:: %d\n", x);
	printf("YCOL:: %d\n", y);
//	y = y / gdata->h_prop;
//	x = x / gdata->w_prop;
	printf("X_PROP: %d\n", x * gdata->w_prop);
	printf("Y_PROP: %d\n", y * gdata->h_prop);
	if (y < 0 || y > gdata->height)
		return (1);
	if (x < 0 || x > gdata->width)
		return (1);
//	if (gdata->map[y - 1][x] == '1' || gdata->map[y + 1][x] == '1')
//		col = 1;
	if (gdata->map[y][x] == '1')
		col = 1;
	printf("MAP[x][y]: %c\n", gdata->map[y][x]);
	printf("COL: %d\n", col);
	printf("--------------\n");
	return (col);
/*	int	col;
	int	pxm;
	int	pym;

	pxm = (int)px / TILE_SIZE;
	pym = (int)py / TILE_SIZE;
	col = 1;
	printf("POSX: %d\n", (int)px);
	printf("POSY: %d\n", (int)py);
	printf("POSXM: %d\n", pxm);
	printf("POSYM: %d\n", pym);
	printf("CASILLA: %c\n", gdata->map[pym][pxm]);
	if (gdata->map[pym][pxm] == 0)
		col = 0;
	return (col);
	*/
}

double	normalize_angle(double angle)
{
//	if (angle > 2 * M_PI)
//		angle -= 2 * M_PI;	
	//TODO -> resetea a 0 el angulo
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
	{
		angle = angle + (2 * M_PI);
	}
	return (angle);
}

//double set_angle(double angle, double increment)
//{
//	return (normalize_angle(angle + increment);
//}

void	update_player(t_gdata *gdata, int key)
{
	float	new_px;
	float	new_py;
	int	type;

	//printf("----------------\n");
	//printf("X: %f\n", pdata->x);
	//printf("Y: %f\n", pdata->y);
	//printf("DIR: %d\n", pdata->move);
	//printf("SP: %d\n", pdata->spin);
	type = key_type(key);
	new_px = gdata->pdata->x;
	new_py = gdata->pdata->y;
	//printf(">>>>>>>>>>>>>>>>\n");
	//int	x = 0;
	//while (gdata->map[x])
	//{
	//	printf("%s\n", gdata->map[x]);
	//	x++;
	//}
	//printf("<<<<<<<<<<<<<<<<\n");
	if (type == 1 || type == 3)
	{
		new_px = gdata->pdata->x + (gdata->pdata->move * cos(gdata->pdata->angle) * gdata->pdata->vel);
		new_py = gdata->pdata->y + (gdata->pdata->move * sin(gdata->pdata->angle) * gdata->pdata->vel);
	}
	else if (type == 4 || type == 2)
	{
		//CHECK WHY
		new_px = gdata->pdata->x + (gdata->pdata->move * cos(gdata->pdata->angle + (M_PI / 2)) * gdata->pdata->vel);
		new_py = gdata->pdata->y + (gdata->pdata->move * sin(gdata->pdata->angle + (M_PI / 2)) * gdata->pdata->vel);
	}
//	gdata->pdata->x = new_px;
//	gdata->pdata->y = new_py;
	if (!player_colision(new_py, new_px, gdata))
	{
		gdata->pdata->x = new_px;
		gdata->pdata->y = new_py;
		printf("NEW_PX: %f\n", gdata->pdata->x);
		printf("NEW_PY: %f\n", gdata->pdata->y);
	}
//	new_px = pdata->x + (pdata->move * cos(pdata->angle) * pdata->vel);
//	new_py = pdata->y + (pdata->move * sin(pdata->angle) * pdata->vel);
	gdata->pdata->angle += gdata->pdata->spin * gdata->pdata->vel_spin;
	gdata->pdata->angle = normalize_angle(gdata->pdata->angle);//TODO-> check angle
//	gdata->pdata->angle = set_angle(gdata->pdata->angle);
//	int	ray;
	//RAY DIRECTION 0 -> -- M_PI <- -- 3 * M_PI / 2 (ARR) -- M_PI / 2 (AB)
	int	down = 0;
	int	left = 0;
	if (gdata->pdata->angle < M_PI)
		down = 1;
	if (gdata->pdata->angle < 3 * M_PI / 2 && gdata->pdata->angle > M_PI / 2)
		left = 1;
	//HORIZONTAL HIT
	float	x_intercept = 0;
	float	y_intercept = gdata->pdata->y;
	int	hor_hit = 0;
//CHEECCK
//	y_intercept = floor(gdata->pdata->y / TILE_SIZE) * TILE_SIZE;

	//SI APUNTA HACIA ABAJO, INCREMENTAMOS UN TILE
	if (down)
		y_intercept += TILE_SIZE;
	float	adyacent = (y_intercept - gdata->pdata->y) / tan(gdata->pdata->angle);
	x_intercept = gdata->pdata->x + adyacent;
//	printf("ANGLE: %f\n", gdata->pdata->angle);
//	printf("TAN: %f\n", tan(gdata->pdata->angle));
//	printf("ADY: %f\n", adyacent);
//	printf("Y_INTER: %f\n", y_intercept);
//	printf("X_INTER: %f\n", x_intercept);
	//CALCULAMOS LA DISTANCIA DE CADA PASO
	float y_step = 1;
	float x_step = y_step / tan(gdata->pdata->angle);
	//SI VAMOS HACIA ARRIBA INVERTIMOS STEP Y
	if (!down)
		y_step = -y_step;
	//COMPROBAMOS QUE EL PASO X ES COHERENTE
	if ((left && x_step > 0) || (!left && x_step < 0))
		x_step = -x_step;
	float	next_x_hor = x_intercept;
	float	next_y_hor = y_intercept;
	//SI APUNTA HACIA ARRIBA RESTO UN PIXEL PARA FORZAR LA COLISIÓN CON LA CASILLA
	if (!down)
		next_y_hor--;
	//DONDE EL RAYO HACE COLISION
	int wall_hit_x = 0;
	int wall_hit_y = 0;

	int wall_hit_x_hor = 0;
	int wall_hit_y_hor = 0;
//	int wall_hit_x_ver = 0;
//	int wall_hit_y_ver = 0;
	//BUCLE PARA BUSCAR PUNTO DE COLISIÓN
	printf("Y_INTER: %f\n", y_intercept);
	printf("X_INTER: %f\n", x_intercept);
	printf("X_STEP: %f\n", x_step);
	printf("Y_STEP: %f\n", y_step);
	while (!hor_hit)
	{
		//OBTENEMOS LA CASILLA (REDONDEANDO POR ABAJO)
	//	int	cas_x = next_x_hor / TILE_SIZE;
	//	int	cas_y = next_y_hor / TILE_SIZE;
		if (player_colision(next_y_hor, next_x_hor, gdata))
		{
			hor_hit = 1;
			wall_hit_x_hor = next_x_hor;
			wall_hit_y_hor = next_y_hor;
		}
		else
		{
			next_x_hor += x_step;
			next_y_hor += y_step;
		}
	}
	//MOSTRAR LINEA RAYO
	int x_dest;
	int y_dest;
	wall_hit_x = wall_hit_x_hor;
	wall_hit_y = wall_hit_y_hor;
	printf("COL X EN: %d\n", wall_hit_x);
	printf("COL Y EN: %d\n", wall_hit_y);
	x_dest = wall_hit_x;
	y_dest = wall_hit_y;
	draw_all(gdata, x_dest, y_dest);
}

/*void	start(t_pdata *pdata, t_gdata *gdata)
{
	//count
	int	x;

	x = 0;
	while (x < gdata->width)
	{
		//height of line to draw on screen
		int	line_height;
		int	draw_start;
		int	draw_end;

		//calculate ray position and direction
		double	camera_x = 2 * x / (double)gdata->width - 1; //x-coord in camera space
		double	ray_dir_x = pdata->dir_x + pdata->plane_x * camera_x;
		double	ray_dir_y = pdata->dir_y + pdata->plane_y * camera_x;
		//which box of the map we are in
		int		map_x = (int)pdata->x;
		int		map_y = (int)pdata->y;
		//length of ray from current position to next x or y-side
		double	side_dist_x;
		double	side_dist_y;
		//direction to step in x or y-direction (+1 or -1)
		int		step_x;
		int		step_y;
		//was there a wall hit
		int		hit = 0;
		//was NS or EW wall hit
		int	side;
		//length of ray from one x or y-side to next x or y-side
		double	perp_wall_dist;
		double	delta_dist_x = 1e30;
		double	delta_dist_y = 1e30;
		if (ray_dir_x != 0)
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y != 0)
			delta_dist_y = fabs(1 / ray_dir_y);
		//calculate step and initial sideDist
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (pdata->x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - pdata->x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (pdata->y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - pdata->y) * delta_dist_y;
		}
		//DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall
			//printf("MAP_X: %d\nMAP_Y: %d\n", map_x, map_y);
			//printf("MAP: %c\n", gdata->map[map_x][map_y]);
			if (gdata->map[map_x][map_y] > 0)
				hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0)
			perp_wall_dist = side_dist_x - delta_dist_x;
		else
			perp_wall_dist = side_dist_y - delta_dist_y;
		//Calculate height of line to draw on screen
		line_height = (int)(gdata->height / perp_wall_dist);
		//calculate lowest and highest pixel to fill in current stripe
		draw_start = -line_height / 2 + gdata->height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + gdata->height / 2;
		if (draw_end >= gdata->height)
			draw_end = gdata->height - 1;
		//check colors
		int	color;
		if (gdata->map[map_x][map_y] == 1)
			color = 0x802020;
		else if (gdata->map[map_x][map_y] == 0)
			color = 0xffffff;
		if (side == 1)
			color = color / 2;
		x++;
	}
	//timing for input and FPS counter
	pdata->old_time = pdata->time;
//	pdata->time = getTicks();
	//frameTime is the time this frame has take, in seconds
	double	frame_time = (pdata->time - pdata->old_time) / 1000.0;
	//FPS counter
	printf("%f\n", 1.0 / frame_time);
	//redraw();
	//cls();
	//speed_modifiers
	//double	move_speed = frame_time * 5.0;
//	double	rot_speed = frame_time * 3.0;
}*/
