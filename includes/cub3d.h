/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:34:58 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/09 14:45:02 by goliano-         ###   ########.fr       */
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
}	t_gdata;

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

typedef struct	m_data
{
	void	*mlx;
	void	*win;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mdata;

/*
 * utils/chequer.c
 */
int	map_name_chequer(char *map);
int	map_data_chequer(t_gdata *gdata);
int	is_map_line(char *line);
int	is_empty_line(char *line);
int	repeated_chars_check(char **map);

/*
 * utils/chequer2.c
 */
int	is_whole_spaces(char *line);

/*
 * utils/map.c
 */
int	fill_map(char *map, t_gdata *gdata);

/*
 *	utils/index.c
 */
int	iter_spaces_idx(char *line, int i);

/*
 *	utils/open.c
 */
int	open_file(char *file);

/*
 * utils/length.c
 */
int	file_length(int fd);

/*
 *	srcs/flood_fill.c
 */
//void	flood_fill_check(t_gdata *gdata, t_pdata *pdata);
void	flood_fill(t_gdata *gdata, int x, int y);

/*
 *	utils/init.c
 */
void	init_player_data(char **map, t_pdata *pdata);

/*
 * utils/strings.c
 */
int	is_player_letter(char c);

/*
 * srcs/start,c
 */
void	start(t_pdata *pdata, t_gdata *gdata);


/*
 * hooks/hooks.c
 */
int		hook_handler(int keycode, t_mdata *mdata);

/*
 * srcs/moves.c
 */
void	move_up(t_gdata *gdata, t_pdata *pdata);
void	move_down(t_gdata *gdata, t_pdata *pdata);
void	move_right(t_pdata *pdata);
void	move_left(t_pdata *pdata);

#endif
