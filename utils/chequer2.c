/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chequer2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:38:54 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/30 13:41:13 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_whole_spaces(char *line)
{
	int	i;
	int	it_is;

	i = 0;
	it_is = 1;
	if (!line)
		it_is = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			it_is = 0;
		i++;
	}
	return (it_is);
}
