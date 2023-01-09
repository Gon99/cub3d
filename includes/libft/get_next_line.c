/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:40:10 by ajimenez          #+#    #+#             */
/*   Updated: 2021/12/09 09:48:50 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

#define BUFFER_SIZE 1

static void	ft_strdel(char **saved)
{
	if (saved != NULL)
	{
		free(*saved);
		*saved = NULL;
	}
}

static char	*ft_out(int fd, char *line, char **saved, char *buff)
{
	char	*ptr;
	size_t	len;

	free (buff);
	len = 0;
	while (saved[fd][len] != '\n')
		len++;
	line = ft_substr(saved[fd], 0, len + 1);
	ptr = ft_strdup(&(saved[fd][len + 1]));
	if (!ptr)
	{
		free(line);
		return (0);
	}
	free(saved[fd]);
	saved[fd] = ptr;
	return (line);
}

static char	*tmp_join(int fd, char **saved, char *buff, ssize_t chars)
{
	char	*tmp;

	tmp = ft_strjoin(saved[fd], buff);
	ft_strdel(&saved[fd]);
	saved[fd] = tmp;
	if (chars < 0)
		ft_strdel(&saved[fd]);
	return (saved[fd]);
}

static char	*get_line(int fd, char **saved, ssize_t chars, char *buff)
{
	char	*line;

	line = 0;
	while (chars > 0)
	{
		if (ft_strchr(saved[fd], '\n'))
			return (ft_out(fd, line, saved, buff));
		chars = read(fd, buff, chars);
		buff[chars] = '\0';
		if (!ft_strchr(saved[fd], '\n') && chars == 0)
		{
			line = ft_strdup(saved[fd]);
			ft_strdel(&saved[fd]);
			if (*line)
			{
				free (buff);
				return (line);
			}
		}
		saved[fd] = tmp_join(fd, saved, buff, chars);
	}
	ft_strdel(&line);
	free (buff);
	free (saved[fd]);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*saved[4096];
	ssize_t		chars;
	char		*buff;

	buff = 0;
	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
		return (0);
	if (!saved[fd])
		saved[fd] = ft_strdup("");
	if (!saved[fd])
		return (0);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	chars = BUFFER_SIZE;
	return (get_line(fd, saved, chars, buff));
}
