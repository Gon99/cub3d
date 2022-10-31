/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2022/10/31 16:59:34 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	map_name_chequer(char *map)
{
	char *ext;

	map = ft_strtrim(map, " ");
	ext = last_four_chars(map);
	printf("EXT: %s\n", ext);
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (!map_name_chequer(argv[1]))
			return (0);
	return (1);
}
