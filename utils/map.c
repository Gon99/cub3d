/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:21:34 by goliano-          #+#    #+#             */
/*   Updated: 2022/11/11 14:07:45 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 *	BUENA
 */

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
	printf("L: %zu\n", l);
	return (l);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (0);
	}
	return (fd);
}

static void	fill_map_data(t_gdata *gdata)
{
	int		i;
	size_t	r;

	i = 0;
	r = -1;
	/*while (r < gdata->file_len)
	{
		printf("FILE[%zu]: %s\n", r, gdata->file[r]);
		r++;
	}*/
	printf("EY\n");
	while (++r < gdata->file_len)
	{
		printf("0\n");
		i = iter_spaces_idx(gdata->file[r], i);
		printf("1\n");
		if (ft_strncmp(&gdata->file[r][i], "NO", 2) == 0)
		{
			gdata->no = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 2)];
			printf("2\n");
		}else if (ft_strncmp(&gdata->file[r][i], "SO", 2) == 0)
			gdata->so = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 2)];
		else if (ft_strncmp(&gdata->file[r][i], "WE", 2) == 0)
			gdata->we = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 2)];
		else if (ft_strncmp(&gdata->file[r][i], "EA", 2) == 0)
			gdata->ea = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 2)];
		else if (ft_strncmp(&gdata->file[r][i], "F", 1) == 0)
			gdata->f = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 2)];
		else if (ft_strncmp(gdata->file[r], "C", 1) == 0)
			gdata->c = &gdata->file[r][iter_spaces_idx(gdata->file[r], i + 1)];
	}
}

/*static int	map_length(int fd)
{
	char	*line;
	int		l;

	l = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_empty_line(line))
			break ;
		line = get_next_line(fd);
		l++;
	}
	printf("LEN: %d\n", l);
	return (l);
}
*/
static void	fill_map_matrix(t_gdata *gdata, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	printf("LINE: %s\n", line);
	i = 0;
	while (line)
	{
		gdata->file[i] = line;
		line = get_next_line(fd);
		i++;
	}
	printf("LLINE: %s\n", line);
	gdata->file[i] = line;
	/*size_t r = 0;
	while (r < gdata->file_len)
	{
		printf("FILEAAA: %s\n", gdata->file[r]);
		r++;
	}*/
	close(fd);
}

//static int	read_map(int fd, t_gdata *gdata)
//{
	//char	*line;

	//gdata->file = calloc(sizeof(char *), map_length());
	/*line = get_next_line(fd);
	while (line)
	{

		fill_map_data(line, gdata);
		line = get_next_line(fd);
		if (is_map_line(line))
		{
			gdata->map = calloc(sizeof(char *), map_length(fd) + 1);
		}
	}
	if (!map_data_chequer(gdata))
		return (0);
	fill_map_matrix(gdata, fd);*/
//	return (1);
//}

int	fill_map(char *map, t_gdata *gdata)
{
	int	fd;

	fd = open_file(map);
	gdata->file_len = file_length(fd);
	gdata->map = calloc(sizeof(char *), gdata->file_len + 1);
	fd = open_file(map);
	fill_map_matrix(gdata, fd);
	fill_map_data(gdata);
	/*if (!read_map(fd, gdata))
		return (0);*/
	return (1);
}
