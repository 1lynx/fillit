/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:21:53 by agfernan          #+#    #+#             */
/*   Updated: 2015/11/27 20:37:59 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tdst;
	unsigned char	*tsrc;

	i = 0;
	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	while (i < n)
	{
		tdst[i] = tsrc[i];
		i++;
	}
	return (dst);
}
