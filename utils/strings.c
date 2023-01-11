/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:19:23 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/11 13:33:44 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_player_letter(char c)
{
	int	r;

	r = 0;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		r = 1;
	return (r);
}

char	*rm_nl(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}
