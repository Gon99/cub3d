/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:16:19 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/23 14:33:11 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_mdata *mdata, int x, int y, int color)
{
	char	*dst;

	//Align bytes, line_length differs from the window with
	dst = mdata->addr + (y * mdata->line_length + x * (mdata->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_first_part_map(t_gdata *gdata, t_mdata *mdata)
{
	int	x;
	int	y;
	int	middle;

	x = -1;
	middle = gdata->height / 2;
	while (++x < gdata->width)
	{
		y = 0;
		while (++y < middle)
			my_mlx_pixel_put(mdata, x, y, parse_color(gdata->f));
		while (++y < gdata->height)
			my_mlx_pixel_put(mdata, x, y, parse_color(gdata->c));
	}
}

void	draw_dir_line(float x_line, float y_line, t_mdata *mdata, float px)
{
	while (x_line > px)
	{
		my_mlx_pixel_put(mdata, x_line, y_line, parse_color("0, 0, 0"));
		x_line--;
	}
}

int	player_colision(float px, float py, t_gdata *gdata)
{
	int	col;
	int	pxm;
	int	pym;

	pxm = (int)px / gdata->width;
	pym = (int)py / gdata->height;
	col = 1;
	printf("CASILLA: %c\n", gdata->map[pym][pxm]);
	if (gdata->map[pym][pxm] != 0)
		col = 1;
	return (col);
}

int	normalize_angle(float angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;	
	angle = angle % (2 * M_PI);
	if (angle < 0)
	{
		angle = angle + (2 * M_PI);
	}
}
	

void	update_player(t_mdata *mdata, t_pdata *pdata, t_gdata *gdata)
{
	float	new_px;
	float	new_py;
	float	x_line;
	float	y_line;

	printf("----------------\n");
	printf("X: %f\n", pdata->x);
	printf("Y: %f\n", pdata->y);
	printf("DIR: %d\n", pdata->move);
	printf("SP: %d\n", pdata->spin);
	new_px = pdata->x;
	new_py = pdata->y;
	/*if (!player_colision(pdata->x, pdata->y, gdata))
	{
		new_px = pdata->x + (pdata->move * cos(pdata->angle) * pdata->vel);
		new_py = pdata->y + (pdata->move * sin(pdata->angle) * pdata->vel);
	}*/
	new_px = pdata->x + (pdata->move * cos(pdata->angle) * pdata->vel);
	new_py = pdata->y + (pdata->move * sin(pdata->angle) * pdata->vel);
	pdata->x = new_px;
	pdata->y = new_py;
	pdata->angle += pdata->spin * pdata->vel_spin;
	pdata->angle = normalize_angle(pdata->angle);//TODO-> check angle
	printf("SPIN: %d\n", pdata->spin);
	printf("VSPIN: %f\n", pdata->vel_spin);
	printf("ANGLE: %f\n", pdata->angle);
	x_line = pdata->x + cos(pdata->angle) * 20;
	y_line = pdata->y + sin(pdata->angle) * 20;
	printf("X_L: %f\n", x_line);
	printf("Y_L: %f\n", y_line);
	mdata->img = mlx_new_image(mdata->ptr, gdata->height, gdata->width);
	mdata->addr = mlx_get_data_addr(mdata->img, &mdata->bpp, &mdata->line_length, &mdata->endian);
	draw_first_part_map(gdata, mdata);
	draw_dir_line(x_line, y_line, mdata, pdata->x);
	my_mlx_pixel_put(mdata, pdata->x, pdata->y, parse_color("0, 0, 0"));
	mlx_put_image_to_window(mdata->ptr, mdata->win, mdata->img, 0, 0);
	printf("----------------\n");
}

void	start(t_pdata *pdata, t_gdata *gdata, t_mdata *mdata)
{
	update_player(mdata, pdata, gdata);
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
