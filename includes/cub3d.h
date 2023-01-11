/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:34:58 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/11 19:33:37 by ajimenez         ###   ########.fr       */
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

typedef struct	p_data
{
	//player position
	double	x;
	double	y;
	char	p;
	//initial direction vector
	double	dir_x;
	double	dir_y;
	//the 2d raycaster version of camera plane
	double	plane_x;
	double	plane_y;
	//time of current frame
	double	time;
	//time of previous frame
	double	old_time;
}	t_pdata;

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
	char	**map;
	char	**file;
	size_t	file_len;
	size_t	map_len;
	int		error;
	int		height;
	int		width;
	t_pdata	*pdata;
}	t_gdata;

typedef struct	m_data
{
	void	*mlx;
	void	*win;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mdata;

typedef struct	t_data
{
	void	*no_text;
	void	*so_text;
	void	*we_text;
	void	*ea_text;
}	t_tdata;

/*
 * SRCS/INIT/
 */

void	init_gdata(t_gdata *gdata, t_pdata *pdata);
void	init_pdata(char **map, t_pdata *pdata);

/*
 * SRCS/PARSER/
 */

int		map_name_chequer(char *map);
int		map_data_chequer(t_gdata *gdata);
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
 * srcs/hooks/hooks.c
 */
void	hooks_call(void *win, t_gdata *gdata, t_mdata *mdata);

#endif
