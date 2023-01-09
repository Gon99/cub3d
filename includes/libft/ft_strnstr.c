/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:38:20 by ajimenez          #+#    #+#             */
/*   Updated: 2021/08/03 19:06:44 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	aux_h;
	size_t	aux_n;

	aux_h = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[aux_h] != '\0')
	{
		aux_n = 0;
		while (haystack[aux_h + aux_n] == needle[aux_n]
			&& (aux_h + aux_n) < len)
		{
			if (haystack[aux_h + aux_n] == '\0' && needle[aux_n] == '\0')
				return ((char *)&haystack[aux_h]);
			aux_n++;
		}
		if (needle[aux_n] == '\0')
			return ((char *)haystack + aux_h);
		aux_h++;
	}
	return (0);
}
