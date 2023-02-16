/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/16 18:11:47 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_gdata	gdata;
	t_pdata	pdata;
	t_mdata mdata;
	t_tdata	tdata;
	t_rdata	rdata;

	(void)argc;
	if (extension_check(argv[1]) < 0)
		return (write(1, "Error name\n", 11));
	init_gdata(&gdata, &pdata, &mdata, &rdata);
	if (!fill_map(argv[1], &gdata))
		return (write(1, "Error data\n", 11));
	init_pdata(&gdata);
	init_rdata(&gdata);
	flood_fill(&gdata, pdata.y / gdata.h_prop, pdata.x / gdata.w_prop);
	if (gdata.error)
		return (write(1, "Error\n", 6));
	ft_game(&mdata, &gdata, &tdata);
	return (1);
}
