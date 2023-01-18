/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:12:07 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/18 14:51:49 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "structs_macros_cub3d.h"


/*
 * SRCS/INIT/
 */

void	init_gdata(t_gdata *gdata, t_pdata *pdata);
void	init_pdata(char **map, t_pdata *pdata);

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
 * srcs/start,c
 */
void	start(t_pdata *pdata, t_gdata *gdata);

/*
 * srcs/moves.c
 */
void	move_up(t_gdata *gdata);
void	move_down(t_gdata *gdata);
void	move_right(t_gdata *gdata);
void	move_left(t_gdata *gdata);

/*
 * srcs/game
 */

int		key_hook(int keycode, t_mlx *mlx);
int		close_mlx(t_mlx *mlx, char *msg);
void	ft_game(t_mlx *mlx);

#endif
