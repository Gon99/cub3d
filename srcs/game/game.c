/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:36 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/18 12:52:15 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_game(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 640, 480, "cub3D");
	//ft_xmp_to_struct(mlx);
	//ft_iter_map(mlx);
	mlx_hook(mlx->win, 17, 1L << 1, close_mlx, mlx);
//	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->ptr);
}
