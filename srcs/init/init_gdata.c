/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:28:57 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/11 19:30:02 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_gdata(t_gdata *gdata, t_pdata *pdata)
{
	gdata->no = 0;
	gdata->so = 0;
	gdata->ea = 0;
	gdata->we = 0;
	gdata->f = 0;
	gdata->c = 0;
	gdata->file_len = 0;
	gdata->map_len = 0;
	gdata->error = 0;
	gdata->height = 1280;
	gdata->width = 1024;
	gdata->pdata = pdata;
}

