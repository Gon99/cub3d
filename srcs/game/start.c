/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:16:19 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/16 20:56:54 by goliano-         ###   ########.fr       */
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
	if (y < 0 || y > gdata->height)
		return (1);
	if (x < 0 || x > gdata->width)
		return (1);
	if (gdata->map[y][x] == '1')
		col = 1;
	printf("PX: %f\n", gdata->pdata->x);
	printf("PY: %f\n", gdata->pdata->y);
	printf("COL: %d\n", col);
	return (col);
}

static void	player_move(t_gdata *gdata, int key)
{
	float	new_px;
	float	new_py;
	int		type;

	type = key_type(key);
	new_px = gdata->pdata->x;
	new_py = gdata->pdata->y;
	if (type == 1 || type == 2)
	{
		new_px = gdata->pdata->x + (gdata->pdata->move * cos(gdata->pdata->angle) * gdata->pdata->vel);
		new_py = gdata->pdata->y + (gdata->pdata->move * sin(gdata->pdata->angle) * gdata->pdata->vel);
	}
	else if (type == 4 || type == 3)
	{
		//CHECK WHY
		new_px = gdata->pdata->x + (gdata->pdata->move * cos(gdata->pdata->angle + (M_PI / 2)) * gdata->pdata->vel);
		new_py = gdata->pdata->y + (gdata->pdata->move * sin(gdata->pdata->angle + (M_PI / 2)) * gdata->pdata->vel);
	}
	if (!player_colision(new_py, new_px, gdata))
	{
		printf("SETX: %f\n", new_px);
		printf("SETY: %f\n", new_py);
		gdata->pdata->x = new_px;
		gdata->pdata->y = new_py;
	}
	gdata->pdata->angle += gdata->pdata->spin * gdata->pdata->vel_spin;
	gdata->pdata->angle = normalize_angle(gdata->pdata->angle);//TODO-> check angle
}

void	get_ray_dest(t_gdata *gdata, int dest)
{
	int	i;
	int	x;
	double	x_step;
	double	aux_px;
	double	aux_py;
	double	dest_diff;

	i = 0;
	while (i < gdata->rdata->n_rays)
	{
		x = 0;
		dest_diff = gdata->rdata->ray[i].y - dest;
		if (gdata->rdata->ray[i].y < dest)
			dest_diff = dest - gdata->rdata->ray[i].y;
		aux_px = gdata->rdata->ray[i].x * gdata->w_prop;
		aux_py = gdata->rdata->ray[i].y * gdata->h_prop;
		double	y_step = gdata->pdata->vel * sin(gdata->rdata->ray[i].angle);
		x_step = gdata->pdata->vel * cos(gdata->rdata->ray[i].angle);
		while (x < dest_diff * gdata->h_prop)
		{
			aux_px += x_step;
			aux_py += y_step;
			x++;
		}
		gdata->rdata->ray[i].x_dest = aux_px;
		gdata->rdata->ray[i].y_dest = aux_py;
		i++;
	}
}

void	init_rays_group(t_gdata *gdata)
{
	int i = 0;
	while (i < gdata->rdata->n_rays)
	{
		gdata->rdata->ray[i].x = gdata->pdata->x;
		gdata->rdata->ray[i].y = gdata->pdata->y;
		set_angle(gdata->pdata->angle, i, gdata);
		i++;
	}
}

void	update_player(t_gdata *gdata, int key)
{
	player_move(gdata, key);
	wall_hit(gdata);
	get_ray_dest(gdata, gdata->rdata->wall_y);
	draw_all(gdata/*, wall_hit_x, wall_hit_y*/);
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
			gdata->pdata->x -= gdata->pdata->dir_x * gdata->pdata->vel;
		if (gdata->map[(int)(gdata->pdata->y - gdata->pdata->dir_y  * gdata->pdata->vel)][(int)(gdata->pdata->x)] == 0)
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
