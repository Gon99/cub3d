/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:16:48 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/18 14:52:31 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_mlx(t_mlx *mlx, char *msg)
{
	printf("%s\n", msg);
	mlx_destroy_window(mlx->ptr, mlx->win);
	//TODO -> Liberar
	exit(0);
	return (0);
}

//int	key_hook(int keycode, t_mlx *mlx)
//{
//	if (keycode == 53)
//		close_mlx(mlx, "Closed");
//	else if (keycode == 0 || keycode == 123) // A Guion IZQ
//		//ft_move(mlx, mlx->map.map, LEFT_Y, LEFT_X);
//	else if (keycode == 1 || keycode == 125) // S Abajo
//		//ft_move(mlx, mlx->map.map, DOWN_Y, DOWN_X);
//	else if (keycode == 2 || keycode == 124) //D Derecha
//		//ft_move(mlx, mlx->map.map, RIGHT_Y, RIGHT_X);
//	else if (keycode == 13 || keycode == 126) //W Arriba
//		//ft_move(mlx, mlx->map.map, UP_Y, UP_X);
//	return (0);
//}
