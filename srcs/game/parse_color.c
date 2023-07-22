/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:18:09 by ajimenez          #+#    #+#             */
/*   Updated: 2023/07/21 22:19:06 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 ** Parse color to int value.
 ** Red    0x00FF0000.
 ** Green  0x0000FF00.
 ** Blue   0x000000FF.
 ** Bitshifting.
 **
 ** @param char *str Color value in str value from input file;
 ** @return int The color value as integer;
*/

int	parse_color(char *str)
{
	char	**sp;
	int		color;
	int		i;

	sp = ft_split(str, ',');
	color = (ft_atoi(sp[0]) << 16 | ft_atoi(sp[1]) << 8 | ft_atoi(sp[2]));
	i = 0;
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
	return (color);
}
