/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:10:19 by goliano-          #+#    #+#             */
/*   Updated: 2023/02/09 18:13:31 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_distance(double px, double py, double cx, double cy)
{
	return (sqrt((cx - px) * (cx - px) + (cy - py) * (cy - py)));
}
