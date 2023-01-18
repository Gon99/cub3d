/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:26:20 by ajimenez          #+#    #+#             */
/*   Updated: 2023/01/18 14:48:18 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
