/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:21:34 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/21 16:01:38 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	file_length(int fd)
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

static void	fill_map_data(t_gdata *gdata)
{
	int		i;
	size_t	r;

	r = -1;
	while (gdata->file[++r])
	{
		i = iter_spaces_idx(gdata->file[r], i);
		if (is_map_line(gdata->file[r]))
			break ;
		if (ft_strncmp(&gdata->file[r][i], "NO", 2) == 0)
			gdata->no = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 2)];
		else if (ft_strncmp(&gdata->file[r][i], "SO", 2) == 0)
			gdata->so = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 2)];
		else if (ft_strncmp(&gdata->file[r][i], "WE", 2) == 0)
			gdata->we = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 2)];
		else if (ft_strncmp(&gdata->file[r][i], "EA", 2) == 0)
			gdata->ea = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 2)];
		else if (ft_strncmp(&gdata->file[r][i], "F", 1) == 0)
			gdata->f = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 1)];
		else if (ft_strncmp(gdata->file[r], "C", 1) == 0)
			gdata->c = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 1)];
		i = 0;
	}
}

static void	fill_map_matrix(t_gdata *gdata, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		gdata->file[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	fill_map(char *map, t_gdata *gdata)
{
	int	fd;

	fd = open_file(map);
	gdata->file_len = file_length(fd);
	gdata->file = calloc(sizeof(char *), gdata->file_len + 1);
	fd = open_file(map);
	fill_map_matrix(gdata, fd);
	fill_map_data(gdata);
	if (!map_data_chequer(gdata))
		return (0);
	return (1);
}
