/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:59:33 by ajimenez          #+#    #+#             */
/*   Updated: 2023/07/22 18:33:04 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_tex(t_tdata *tdata)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(tdata->tex_arr[i]);
		i++;
	}
	free(tdata->tex_arr);
}

void	free_map(t_gdata *gdata)
{
	int	i;

	i = 0;
	while (gdata->file[i])
	{
		free(gdata->file[i]);
		i++;
	}
	free(gdata->map);
	free(gdata->file);
}
