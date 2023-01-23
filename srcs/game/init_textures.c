/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:26:53 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/23 12:31:50 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_textures(t_tdata *tdata, t_gdata *gdata, t_mdata *mdata)
{
	int	height;
	int	width;

	tdata->no_text = mlx_xpm_file_to_image(mdata->ptr, rm_nl(gdata->no), &width, &height);
	tdata->so_text = mlx_xpm_file_to_image(mdata->ptr, rm_nl(gdata->so), &width, &height);
	tdata->ea_text = mlx_xpm_file_to_image(mdata->ptr, rm_nl(gdata->ea), &width, &height);
	tdata->we_text = mlx_xpm_file_to_image(mdata->ptr, rm_nl(gdata->we), &width, &height);
	if (!tdata->no_text || !tdata->so_text || !tdata->ea_text || !tdata->we_text)
	{
		write(1, "Invalid texture\n", 16);
		exit(0);
	}
}
