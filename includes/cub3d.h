/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:34:58 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/30 16:22:45 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

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
}	t_gdata;

typedef struct	p_data
{
	int		x;
	int		y;
	char	p;
}	t_pdata;

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
int	fill_map(char *map, t_gdata *gdata, t_pdata *pdata);

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
void	flood_fill_check(t_gdata *gdata, t_pdata *pdata);

/*
 *	utils/init.c
 */
void	init_player_data(char **map, t_pdata *pdata);

/*
 * utils/strings.c
 */
int	is_player_letter(char c);
#endif
