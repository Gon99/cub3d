/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:20:05 by ajimenez          #+#    #+#             */
/*   Updated: 2021/08/22 12:59:58 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

unsigned int	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	unsigned int	a;
	unsigned int	b;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	a = ft_strlen(dst);
	b = 0;
	while (src[b] != '\0' && a + 1 < dstsize)
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[b]));
}
