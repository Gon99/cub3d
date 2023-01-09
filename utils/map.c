/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:21:34 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/09 12:40:37 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	copy_map(t_gdata *gdata, int r)
{
	int	x;
	int	i;

	x = r;
	i = 0;
	while (is_map_line(gdata->file[r]))
	{
		gdata->map_len++;
		r++;
	}
	gdata->map = calloc(sizeof(char *), r + 1);
	if (!gdata->map)
		return ;
	while (is_map_line(gdata->file[x]))
	{
		gdata->map[i] = gdata->file[x];
		i++;
		x++;
	}
}

static void	copy_map_data(t_gdata *gdata)
{
	int		i;
	size_t	r;

	r = -1;
	i = 0;
	while (gdata->file[++r])
	{
		i = iter_spaces_idx(gdata->file[r], i);
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
		if (is_map_line(gdata->file[r]))
			break ;
		i = 0;
	}
	copy_map(gdata, r);
}

static void	copy_file(char *map, t_gdata *gdata)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open_file(map);
	gdata->file_len = file_length(fd);
	gdata->file = calloc(sizeof(char *), gdata->file_len + 1);
	fd = open_file(map);
	line = get_next_line(fd);
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
	copy_file(map, gdata);
	copy_map_data(gdata);
	if (repeated_chars_check(gdata->map))
	{
		return (0);
	}
	if (!map_data_chequer(gdata))
	{
		return (0);
	}
	return (1);
}
