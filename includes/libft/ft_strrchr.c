/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:04:58 by ajimenez          #+#    #+#             */
/*   Updated: 2021/08/22 12:52:46 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*last;

	last = s;
	i = ft_strlen(s);
	s += i;
	while (s != last && c != *s)
		s--;
	if ((unsigned char)c == (unsigned char)*s)
		return ((char *)s);
	return (0);
}
