/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:12:07 by ajimenez          #+#    #+#             */
/*   Updated: 2023/02/14 11:12:55 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include "structs_macros_cub3d.h"


/*
 * SRCS/INIT/
 */

void	init_gdata(t_gdata *gdata, t_pdata *pdata, t_mdata *mdata, t_rdata *rdata);
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
int		fill_map(char *map, t_gdata *gdata);
int		iter_spaces_idx(char *line, int i);
int		file_length(int fd);
void	flood_fill(t_gdata *gdata, int x, int y);
int		is_player_letter(char c);
char	*rm_nl(char *line);
int		extension_check(char *map);

/*
 *	utils/init.c
 */
void	init_player_data(char **map, t_pdata *pdata);

/*
 * srcs/moves.c
 */
void	move_ahead(t_gdata *gdata);
void	move_back(t_gdata *gdata);
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

/*
 * START
 */

void	update_player(t_gdata *gdata, int key);
void	my_mlx_pixel_put(t_mdata *mdata, int x, int y, int color);
//int		player_colision(int x, int y, t_gdata *gdata);

/*
 * srcs/draw/draw.c
 */
void	draw_all(t_gdata *gdata, int x_dest, int y_dest);
void	draw_first_part_map(t_gdata *gdata);

/*
 * srcs/angle/angle.c
 */
double	to_radians(double angle);
double	normalize_angle(double angle);
void	set_angle(double angle, int i, t_gdata *gdata);

/*
 * srcs/math/math.c
 */
int	get_distance(int px, int py, int cx, int cy);

#endif
