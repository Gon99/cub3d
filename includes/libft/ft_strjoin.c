/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:04:26 by ajimenez          #+#    #+#             */
/*   Updated: 2021/08/08 16:31:08 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	int		i;
	int		aux_s2;

	if (!s1 || !s2)
		return (0);
	sjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sjoin)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		sjoin[i] = s1[i];
		i++;
	}
	aux_s2 = 0;
	while (s2[aux_s2] != '\0')
	{
		sjoin[i] = s2[aux_s2];
		i++;
		aux_s2++;
	}
	sjoin[i] = '\0';
	return (sjoin);
}
