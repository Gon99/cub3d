/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2023/07/22 18:06:16 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void leaks()
{
	system("leaks -q cub3d");
}

int	main(int argc, char **argv)
{
	t_gdata	gdata;
	t_pdata	pdata;
	t_mdata	mdata;
	t_tdata	tdata;
	t_rdata	rdata;

	atexit(leaks);
	if (argc < 2)
		return (1);
	if (extension_check(argv[1]) == false)
		return (write(1, "Error name\n", 11));
	init_gdata(&gdata, &pdata, &mdata, &rdata);
	if (!fill_map(argv[1], &gdata))
	{
		free_map(&gdata);
		return (write(1, "Error data\n", 11));
	}
	init_pdata(&gdata);
	flood_fill(&gdata, pdata.y, pdata.x);
	if (gdata.error)
	{
		free_map(&gdata);
		return (write(1, "Map error\n", 10));
	}
	ft_game(&mdata, &gdata, &tdata);
	return (1);
}
