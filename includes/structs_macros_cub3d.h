/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_macros_cub3d.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:08:17 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/16 14:15:49 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MACROS_CUB3D_H
# define STRUCT_MACROS_CUB3D_H

# include <fcntl.h>

/*
** MAP ERROR MACROS
*/
# define UP_Y		-1
# define UP_X		0

# define RIGHT_Y	0
# define RIGHT_X	1

# define DOWN_X		0
# define DOWN_Y		1

# define LEFT_Y		0
# define LEFT_X		-1

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

typedef struct	m_mlx
{
	void	*ptr;
	void	*win;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct	t_data
{
	void	*no_text;
	void	*so_text;
	void	*we_text;
	void	*ea_text;
}	t_tdata;

#endif
