/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:21:30 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/30 10:34:13 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	file_length(int fd)
{
	char	*line;
	size_t	l;

	line = get_next_line(fd);
	l = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		l++;
	}
	free(line);
	close(fd);
	return (l);
}
