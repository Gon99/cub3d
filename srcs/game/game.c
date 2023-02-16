/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:36 by ajimenez          #+#    #+#             */
/*   Updated: 2023/02/04 12:56:26 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_game(t_mdata *mdata, t_gdata *gdata, t_tdata *tdata)
{
	init_mlx(gdata);
	init_textures(tdata, gdata, mdata);
	draw_all(gdata);
	hooks_call(gdata, mdata);
	mlx_loop(mdata->ptr);
}
