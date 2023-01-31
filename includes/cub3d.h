/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:12:07 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/23 15:20:01 by goliano-         ###   ########.fr       */
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
 * SRCS/INIT/
 */

void	init_gdata(t_gdata *gdata, t_pdata *pdata, t_mdata *mdata);
void	init_pdata(char **map, t_pdata *pdata);
void	init_textures(t_tdata *tdata, t_gdata *gdata, t_mdata *mdata);
void	init_mlx(t_mdata *mdata);

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
 * utils/strings.c
 */


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
void	draw_first_part_map(t_gdata *gdata, t_mdata *mdata);
void	my_mlx_pixel_put(t_mdata *mdata, int x, int y, int color);
void	draw_dir_line(float x_line, float y_line, t_mdata *mdata, t_pdata *pdata);
int		player_colision(float px, float py, t_gdata *gdata);

#endif
