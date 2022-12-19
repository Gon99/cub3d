/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:19:23 by goliano-          #+#    #+#             */
/*   Updated: 2022/12/15 11:29:13 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_player_letter(char c)
{
	int	r;

	r = 0;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		r = 1;
	return (r);
}
