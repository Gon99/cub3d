/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:36 by ajimenez          #+#    #+#             */
/*   Updated: 2023/03/01 16:55:32 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 ** Finish parser and start of program, initialize textures and execution.
 ** 
 ** @param t_mdata *mdata Mlx struct;
 ** @param t_gdata *gdata Main struct;
 ** @param t_tdata *tdata Texture struct;
 **
 */
void	ft_game(t_mdata *mdata, t_gdata *gdata, t_tdata *tdata)
{
	init_mlx(gdata);
	init_textures(tdata, gdata, mdata);
	gdata->tdata = tdata;
	hooks_call(gdata, mdata);
	mlx_loop(mdata->ptr);
}
