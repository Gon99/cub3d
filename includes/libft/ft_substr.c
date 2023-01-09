/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:47:50 by ajimenez          #+#    #+#             */
/*   Updated: 2021/08/10 17:00:35 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			aux_start;
	size_t			cont_substr;

	if (!s)
		return (0);
	aux_start = start;
	cont_substr = 0;
	while (cont_substr < len && s[aux_start++])
		cont_substr++;
	substr = (char *)malloc(cont_substr + 1);
	if (!substr)
		return (0);
	aux_start = start;
	cont_substr = 0;
	while (cont_substr < len && aux_start < ft_strlen(s))
		substr[cont_substr++] = s[aux_start++];
	substr[cont_substr] = '\0';
	return (substr);
}
