/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:33:36 by goliano-          #+#    #+#             */
/*   Updated: 2022/10/31 16:59:37 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*last_four_chars(char *s)
{
	int		l;
	int		i;
	char	*new;

	l = ft_strlen(s) - 5;
	i = -1;
	new = ft_calloc(4, sizeof(char *));
	if (!new)
		return (0);
	while (s[l])
		new[++i] = s[++l];
	return (new);
}

