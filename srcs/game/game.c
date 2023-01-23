/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:36 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/23 15:20:39 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_game(t_mdata *mdata, t_gdata *gdata, t_tdata *tdata, t_pdata *pdata)
{
	init_mlx(mdata);
	init_textures(tdata, gdata, mdata);
	start(pdata, gdata, mdata);
	hooks_call(mdata->win, gdata, mdata);
	mlx_loop(mdata->ptr);
}
