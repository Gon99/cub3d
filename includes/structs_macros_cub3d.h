/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_macros_cub3d.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:08:17 by ajimenez          #+#    #+#             */
/*   Updated: 2023/02/27 17:28:05 by goliano-         ###   ########.fr       */
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

# define MAP_HEIGHT	480
# define MAP_WIDTH 640

# define TILE_SIZE 1.0
# define FOV 60.00
# define HALF_FOV FOV / 2

/*
 * PLAYER_DATA
 */
typedef struct	p_data
{
	//player position
	double	x;
	double	y;
	char	p;
	
	int	move;
	int	spin;
	double	angle;
	double	vel;
	double	vel_spin;

	//initial direction vector
//	double	dir_x;
//	double	dir_y;
//	//the 2d raycaster version of camera plane
//	double	plane_x;
//	double	plane_y;
//	//time of current frame
//	double	time;
//	//time of previous frame
//	double	old_time;
}	t_pdata;

/*
 * MLX DATA
 */
typedef struct	m_data
{
	void	*ptr;
	void	*win;
	void	*win_img;
	void	*map_img;
	char	*win_addr;
	char	*map_addr;
	int		bpp_win;
	int		bpp_map;
	int		ll_win;
	int		ll_map;
	int		end_win;
	int		end_map;
}	t_mdata;

typedef struct ray
{
	double	x;
	double	y;
	double	x_dest;
	double	y_dest;
	double	angle;
	double	angle_inc;
	int		h_hit;
	int		v_hit;
	double	dist;
}	t_ray;

/*
 * RAY DATA
 */
typedef struct r_data
{
	int	n_rays;
	double	angle_inc;
	double	angle_init;
	double	angle_ray;
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
	double	h_prop;
	double	w_prop;
	t_pdata	*pdata;
	t_mdata *mdata;
	t_rdata *rdata;
}	t_gdata;

/*
 * TEXTURE DATA
 */
typedef struct	t_data
{
	void	*no_text;
	void	*so_text;
	void	*we_text;
	void	*ea_text;
}	t_tdata;

#endif
