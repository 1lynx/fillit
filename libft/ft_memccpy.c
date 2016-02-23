/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:02:57 by agfernan          #+#    #+#             */
/*   Updated: 2015/11/30 15:00:47 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;
	unsigned char	*tdst;
	unsigned char	*tsrc;

	i = 0;
	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	chr = (unsigned char)c;
	while (i < n)
	{
		tdst[i] = tsrc[i];
		if (tsrc[i] == chr)
		{
			return ((void *)(tdst + i + 1));
		}
		i++;
	}
	return (NULL);
}
