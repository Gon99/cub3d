/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:01:47 by ajimenez          #+#    #+#             */
/*   Updated: 2021/08/08 15:59:27 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s_dup;

	s_dup = (char *)malloc(ft_strlen(s1) + 1);
	if (!s_dup)
		return (0);
	ft_memcpy(s_dup, s1, ft_strlen(s1) + 1);
	return (s_dup);
}
