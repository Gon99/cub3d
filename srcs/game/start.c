/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:16:19 by goliano-          #+#    #+#             */
/*   Updated: 2023/03/01 16:55:51 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	player_colision(int y, int x, t_gdata *gdata)
{
	int	col;
	int	l;

	col = 0;
	if (y < 0 || y >= gdata->height)
		return (1);
	if (x < 0 || x > gdata->width)
		return (1);
	l = ft_strlen(gdata->map[y]);
	if (l < x)
		return (1);
	if (gdata->map[y][x] == '1')
		col = 1;
	return (col);
}

static void	player_move(t_pdata *pdata, t_gdata *gdata, int key)
{
	float	new_px;
	float	new_py;
	int		type;

	type = key_type(key);
	new_px = pdata->x;
	new_py = pdata->y;
	//LINUX 1 / 3
	if (type == 1 || type == 3)
	{
		new_px = pdata->x + (pdata->move * cos(pdata->angle) * pdata->vel);
		new_py = pdata->y + (pdata->move * sin(pdata->angle) * pdata->vel);
	}
	//LINUX 4 / 2
	else if (type == 2 || type == 4)
	{
		//CHECK WHY
		new_px = pdata->x + (pdata->move * cos(pdata->angle + (M_PI / 2)) * pdata->vel);
		new_py = pdata->y + (pdata->move * sin(pdata->angle + (M_PI / 2)) * pdata->vel);
	}
	if (!player_colision(new_py, new_px, gdata))
	{
		pdata->x = new_px;
		pdata->y = new_py;
	}
	pdata->angle += pdata->spin * pdata->vel_spin;
	pdata->angle = normalize_angle(pdata->angle);//TODO-> check angle
}

//void	get_ray_dest(t_gdata *gdata)
//{
//	int x = 0;
//	while (x < gdata->rdata->n_rays)
//	{
//		
//		x++;
//	}
//	int	i;
//	int	x;
//	double	x_step;
//	double	aux_px;
//	double	aux_py;
//	double	dest_diff;
//
//	i = 0;
//	while (i < gdata->rdata->n_rays)
//	{
//		x = 0;
//		dest_diff = gdata->rdata->ray[i].y - dest;
//		if (gdata->rdata->ray[i].y < dest)
//			dest_diff = dest - gdata->rdata->ray[i].y;
//		aux_px = gdata->rdata->ray[i].x;
//		aux_py = gdata->rdata->ray[i].y;
//		double	y_step = gdata->pdata->vel * sin(gdata->rdata->ray[i].angle);
//		x_step = gdata->pdata->vel * cos(gdata->rdata->ray[i].angle);
//		while (x < dest_diff)
//		{
//			aux_px += x_step;
//			aux_py += y_step;
//			x++;
//		}
//		gdata->rdata->ray[i].x_dest = aux_px;
//		gdata->rdata->ray[i].y_dest = aux_py;
//		i++;
//	}
//}
//
void	get_ray_dist(t_gdata *gdata, int x)
{
	float	hor_dist;
	float	ver_dist;

	hor_dist = 99999999;
	ver_dist = 99999999;
	if (gdata->rdata->ray[x].h_hit)
		hor_dist = get_distance(gdata->rdata->ray[x].x, gdata->rdata->ray[x].y, gdata->rdata->x_inter_h, gdata->rdata->y_inter_h);
	if (gdata->rdata->ray[x].v_hit)
		ver_dist = get_distance(gdata->rdata->ray[x].x, gdata->rdata->ray[x].y, gdata->rdata->x_inter_v, gdata->rdata->y_inter_v);
//	printf("HOR_DIST: %f\n", hor_dist);
//	printf("VER_DIST: %f\n", ver_dist);
	gdata->rdata->ray[x].dist = ver_dist* gdata->h_prop;
	if (hor_dist < ver_dist)
		gdata->rdata->ray[x].dist = hor_dist * gdata->w_prop;
	gdata->rdata->ray[x].h_hit = 0;
	gdata->rdata->ray[x].v_hit = 0;
}

//void	init_rays_group0(t_gdata *gdata, t_ray *ray)
//{
//	int i;
//	int y0;
//	int	y1;
//	float	plane_dist;
//	float	wall_height;
//
//	i = 0;
//	draw_ceiling(gdata/*, i, y0*/);
//	draw_floor(gdata);
//	plane_dist = (MAP_WIDTH / 2) / tan(to_radians(HALF_FOV));
//	while (i < gdata->rdata->n_rays)
//	{
//		ray[i].x = gdata->pdata->x;
//		ray[i].y = gdata->pdata->y;
//		set_angle(gdata->pdata->angle, i, gdata);
//		wall_hit_hor(gdata, ray[i].angle, i);
//		wall_hit_ver(gdata, ray[i].angle, i);
//		get_ray_dist(gdata, i);
//		wall_height = (10 / ray[i].dist) * plane_dist;
//		y0 = (int)MAP_HEIGHT / 2 - (int)wall_height / 2;
//		y1 = y0 + wall_height;
//		draw_wall(gdata, y0, y1, i);
//		i++;
//	}
//	mlx_put_image_to_window(gdata->mdata->ptr, gdata->mdata->win, gdata->mdata->win_img, 0, 0);
//}

void	init_rays_group(t_gdata *gdata)
{
	int	x;
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;

	int	map_x;
	int	map_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	perp_wall_dist;
	int	step_x;
	int	step_y;
	int	hit;
	int	side;

	int	line_height;
	int	draw_start;
	int	draw_end;

	x = 0;
	draw_floor(gdata);
	draw_ceiling(gdata);
	while (x < MAP_WIDTH)
	{
		camera_x = 2 * gdata->pdata->x / (float)MAP_WIDTH - 1;
//		printf("CAM_X: %f\n", camera_x);
		ray_dir_x = gdata->pdata->dir_x + gdata->pdata->plane_x * camera_x;
		ray_dir_y = gdata->pdata->dir_y + gdata->pdata->plane_y * camera_x;
//		printf("RAY_X: %f\n", ray_dir_x);
//		printf("RAY_Y: %f\n", ray_dir_y);
		map_x = (int)gdata->pdata->x;
		map_y = (int)gdata->pdata->y;
		if (ray_dir_x == 0)
			delta_dist_x = 1e30;
		else
//			delta_dist_x = abs(1 / ray_dir_x);
			delta_dist_x = 1 / ray_dir_x;
		if (ray_dir_y == 0)
			delta_dist_y = 1e30;
		else
//			delta_dist_y = abs(1 / ray_dir_y);
			delta_dist_y = 1 / ray_dir_y;
		if (delta_dist_x < 0)
			delta_dist_x *= -1;
		if (delta_dist_y < 0)
			delta_dist_y *= -1;
//		printf("DELTA_X: %f\n", delta_dist_x);
//		printf("DELTA_Y: %f\n", delta_dist_y);
		hit = 0;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (gdata->pdata->x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - gdata->pdata->x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (gdata->pdata->y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - gdata->pdata->y) * delta_dist_y;
		}
//		printf("SIDE_X: %f\n", side_dist_x);
//		printf("SIDE_Y: %f\n", side_dist_y);
		while (hit == 0)
		{
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
			if (gdata->map[map_y][map_x] > 0)
			{
			//	printf("COL: %d - %d\n", map_y, map_x);
				hit = 1;
			}
		}
//		printf("SIDE_X: %f\n", side_dist_x);
//		printf("SIDE_Y: %f\n", side_dist_y);
//		printf("DELTA_X: %f\n", delta_dist_x);
//		printf("DELTA_Y: %f\n", delta_dist_y);
//		printf("SIDE: %d\n", side);
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		//printf("PERP: %f\n", perp_wall_dist);
//		printf("SIDE: %d\n", side);
		line_height = (int)(MAP_HEIGHT / perp_wall_dist);
	//	printf("LINE: %d\n", line_height);
		draw_start = -line_height / 2 + MAP_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + MAP_HEIGHT / 2;
	//	printf("END0: %d\n", draw_end);
		if (draw_end >= MAP_HEIGHT)
			draw_end = MAP_HEIGHT - 1;
	//	printf("ST: %d\n", draw_start);
	//	printf("END: %d\n", draw_end);
		draw_wall(gdata, draw_start, draw_end, x);
		x++;
	}
	mlx_put_image_to_window(gdata->mdata->ptr, gdata->mdata->win, gdata->mdata->win_img, 0, 0);
}

//void	calc_rays_dist(t_gdata *gdata)
//{
//	int		x;
//
//	x = 0;
//	while (x < gdata->rdata->n_rays)
//	{
////		printf("ANGLE: %f\n", gdata->rdata->ray[x].angle);
//		x++;
//	}
//}

void	update_player(t_pdata *pdata, t_gdata *gdata, int key)
{
	player_move(pdata, gdata, key);
//	init_rays_group(gdata);
//	calc_rays_dist(gdata);
////	wall_hit(gdata);
////	get_ray_dest(gdata);
//	draw_all(gdata/*, wall_hit_x, wall_hit_y*/);
}

/*void	player_move2(t_gdata *gdata, int keycode)
{
	int	type = key_type(keycode);
	
	if (type == 1)
	{
		if (gdata->map[(int)(gdata->pdata->y)][(int)(gdata->pdata->x + gdata->pdata->dir_x * gdata->pdata->vel)] == 0)
			gdata->pdata->x += gdata->pdata->dir_x * gdata->pdata->vel;
		if (gdata->map[(int)(gdata->pdata->y + gdata->pdata->dir_y * gdata->pdata->vel)][(int)(gdata->pdata->x)] == 0)
			gdata->pdata->y += gdata->pdata->dir_y * gdata->pdata->vel;
	}
	if (type == 3)
	{
		if (gdata->map[(int)(gdata->pdata->y)][(int)(gdata->pdata->x - gdata->pdata->dir_x * gdata->pdata->vel)] == 0)
			gdata->pdata->y -= gdata->pdata->dir_y * gdata->pdata->vel;
	}
}

void	start(t_gdata *gdata, int keycode)
{
	player_move2(gdata, keycode);
	int x = 0;
	while (x < MAP_WIDTH)
	{
		double	cam_x = 2 * x / (double)MAP_WIDTH - 1; //x-coord in camera space
		double	ray_dir_x = gdata->pdata->dir_x + gdata->pdata->plane_x * cam_x;
		double	ray_dir_y = gdata->pdata->dir_y + gdata->pdata->plane_y * cam_x;
		//Which box of the map we are in
		int map_x = (int)gdata->pdata->x;
		int map_y = (int)gdata->pdata->y;
		//length of ray from current position to next x or y-side
		double side_dist_x;
		double side_dist_y;
		//length of ray from one x or y-side to next x or y-side
		double delta_dist_x = (ray_dir_x == 0) ? 1e30 : abs(1 / ray_dir_x);
		double delta_dist_y = (ray_dir_y == 0) ? 1e30 : abs(1 / ray_dir_y);
		double perp_wall_dist;
		//direction to step in x or y-direction (either +1 or -1)
		int step_x;
		int step_y;
		//wall hit
		int hit = 0;
		//NS or EW wall hit
		int side;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (gdata->pdata->x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1 - gdata->pdata->x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (gdata->pdata->y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1 - gdata->pdata->y) * delta_dist_y;
		}
		//DDA
		while (hit == 0)
		{
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
			if (gdata->map[map_y][map_x] > 0)
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = side_dist_x - delta_dist_x;
		else
			perp_wall_dist = side_dist_y - delta_dist_y;
		int line_height = (int)(MAP_HEIGHT / perp_wall_dist);
		int draw_start = -line_height / 2 + MAP_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + MAP_HEIGHT / 2;
		if (draw_end >= MAP_HEIGHT)
			draw_end = MAP_HEIGHT - 1;

		x++;
	}
	gdata->mdata->win_img = mlx_new_image(gdata->mdata->ptr, MAP_WIDTH, MAP_HEIGHT);
	gdata->mdata->win_addr = mlx_get_data_addr(gdata->mdata->win_img, &gdata->mdata->bpp_win, &gdata->mdata->ll_win, &gdata->mdata->end_win);
	draw_first_part_map(gdata);
}*/
