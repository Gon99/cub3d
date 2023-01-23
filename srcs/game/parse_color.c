
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:59:32 by goliano-          #+#    #+#             */
/*   Updated: 2023/01/18 09:59:57 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_color(char *str)
{
	char	**sp;
	int	color;

	sp = ft_split(str, ',');
	color = (ft_atoi(sp[0]) << 16 | ft_atoi(sp[1]) << 8 | ft_atoi(sp[2]));
	return (color);
}
