/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:24:56 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 23:05:23 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	while (dest[i] && i < size)
		i++;
	len_dst = i;
	while (src[i - len_dst] && i < size - 1)
	{
		dest[i] = src[i - len_dst];
		i++;
	}
	if (len_dst < size)
		dest[i] = '\0';
	return (len_dst + ft_strlen(src));
}
