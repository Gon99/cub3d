/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_macros_cub3d.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:08:17 by ajimenez          #+#    #+#             */
/*   Updated: 2023/05/17 19:41:48 by ajimenez         ###   ########.fr       */
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
 
# define ESC          53
# define ESC_L        65307
 
# define MAP_HEIGHT	480
# define MAP_WIDTH 640
# define TEX_HEIGHT 64
# define TEX_WIDTH 64

# define TILE_SIZE 1.0
# define FOV 60.00
# define HALF_FOV FOV / 2
# define SPEED 0.08

/*
 * PLAYER_DATA
 */
typedef struct	p_data
{
	float	x;
	float	y;
	char	p;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;
	float	map_x;
	float	map_y;
	float	perp;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	float	step_x;
	float	step_y;
	int	side;
	float	vel_spin;
}	t_pdata;

/*
 * MLX DATA
 */
typedef struct	m_data
{
	void	*ptr;
	void	*win;
	void	*win_img;
	int	*win_addr;
	int		bpp_win;
	int		ll_win;
	int		end_win;
	int	img_w;
	int	img_h;
}	t_mdata;

typedef struct ray
{
	float	x;
	float	y;
	float	x_dest;
	float	y_dest;
	float	angle;
	float	angle_inc;
	int		h_hit;
	int		v_hit;
	float	dist;
}	t_ray;

/*
 * RAY DATA
 */
typedef struct r_data
{
	int	n_rays;
	float	angle_inc;
	float	angle_init;
	float	angle_ray;
	int	h_dist;
	int	h_type;
	float	x_inter_h;
	float	y_inter_h;
	float	x_inter_v;
	float	y_inter_v;
//	int	h_hit;
	int	v_hit;
	int	wall_x;
	int	wall_y;
	t_ray	*ray;
}	t_rdata;

/*
 * TEXTURE DATA
 */
typedef struct	t_data
{
	int	**tex_arr;
	int	height;
	int	width;
	int	tex_num;
}	t_tdata;

/*
 * GLOBAL DATA
 */
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
	t_mdata *mdata;
	t_rdata *rdata;
	t_tdata *tdata;
}	t_gdata;

#endif
