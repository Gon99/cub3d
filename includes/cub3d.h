/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:12:07 by ajimenez          #+#    #+#             */
/*   Updated: 2023/03/01 16:27:51 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include "structs_macros_cub3d.h"

/*
 * srcs/parser/check
 */
int		extension_check(char *map);

/*
 * srcs/init/init_gdata
 */
void	init_gdata(t_gdata *gdata, t_pdata *pdata, t_mdata *mdata, t_rdata *rdata);

/*
 * srcs/parser/fill_map
 */
int		fill_map(char *map, t_gdata *gdata);

void	init_pdata(t_gdata *gdata);
void	init_textures(t_tdata *tdata, t_gdata *gdata, t_mdata *mdata);
void	init_mlx(t_gdata *gdata);
void	init_rdata(t_gdata *gdata);

/*
 * SRCS/PARSER/
 */

int		map_data_check(t_gdata *gdata);
int		is_map_line(char *line);
int		is_empty_line(char *line);
int		repeated_chars_check(char **map);
int		is_whole_spaces(char *line);
int		iter_spaces_idx(char *line, int i);
int		file_length(int fd);
void	flood_fill(t_gdata *gdata, int x, int y);
int		is_player_letter(char c);
char	*rm_nl(char *line);

/*
 *	utils/init.c
 */
void	init_player_data(char **map, t_pdata *pdata);

/*
 * srcs/moves.c
 */
void	move_ws(t_gdata *gdata, int type);
void	move_ad(t_gdata *gdata, int type);
void	turn_right(t_gdata *gdata);
void	turn_left(t_gdata *gdata);

/*
 * srcs/game
 */

int		parse_color(char *str);
int		key_hook(int keycode, t_mdata *mlx);
void	ft_game(t_mdata *mdata, t_gdata *gdata, t_tdata *tdata);

/*
 * srcs/game/key_hook.c
 */
void	hooks_call(t_gdata *gdata, t_mdata *mdata);
int	key_type(int key);
void	start(t_gdata *gdata, int keycode);

/*
 * START
 */

void	update_player(t_pdata *pdata, t_gdata *gdata, int key);
void	calc_rays_dist(t_gdata *gdata);
void	raycasting(t_gdata *gdata);
//void	my_mlx_pixel_put(t_mdata *mdata, int x, int y, int color);
//int		player_colision(int x, int y, t_gdata *gdata);

/*
 * srcs/draw/draw.c
 */
//void	draw_all(t_gdata *gdata/*, int x_dest, int y_dest*/);
//void	draw_first_part_map(t_gdata *gdata);
void	draw_ceiling(t_mdata *mdata);
void	draw_floor(t_mdata *mdata);
void	draw_wall(t_gdata *gdata, int x);

/*
 * srcs/angle/angle.c
 */
double	to_radians(double angle);
double	normalize_angle(double angle);
void	set_angle(double angle, int i, t_gdata *gdata);

/*
 * srcs/math/math.c
 */
float	get_distance(float px, float py, float cx, float cy);

/*
 * srcs/game/player_dir.c
 */
int	is_down(float angle);
int	is_left(float angle);

/*
 * srcs/game/steps.c
 */
float	get_x_step_hor(float angle);
float	get_y_step_hor(float angle);
float	get_x_step_ver(float angle);
float	get_y_step_ver(float angle);

/*
 * srcs/game/ray_colision.c
 */
void	wall_hit_hor(t_gdata *gdata, float angle, int x);
void	wall_hit_ver(t_gdata *gdata, float angle, int x);
void		wall_hit(t_gdata *gdata);

/*
 * srcs/game/start.c
 */
int		player_colision(int y, int x, t_gdata *gdata);

#endif
