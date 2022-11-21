/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/21 15:26:33 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	init_gdata(t_gdata *gdata)
{
	gdata->no = 0;
	gdata->so = 0;
	gdata->ea = 0;
	gdata->we = 0;
	gdata->f = 0;
	gdata->c = 0;
}

int	main(int argc, char **argv)
{
	t_gdata	gdata;
	(void)argc;

	if (map_name_chequer(argv[1]) < 0)
		return (write(1, "Error\n", 6));
	init_gdata(&gdata);
	if (!fill_map(argv[1], &gdata))
		return (write(1, "Error\n", 6));
	printf("NO: %s\n", gdata.no);
	printf("SO: %s\n", gdata.so);
	printf("EA: %s\n", gdata.ea);
	printf("WE: %s\n", gdata.we);
	printf("F: %s\n", gdata.f);
	printf("C: %s\n", gdata.c);
	/*int i = 0;
	while (gdata.file[i])
	{
		printf("MAP: %s\n", gdata.file[i]);
		i++;
	}*/
	return (1);
}
