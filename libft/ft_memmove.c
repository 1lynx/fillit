/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:48:01 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 19:20:45 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tdst;
	unsigned char *tsrc;

	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	if (dst > src)
	{
		while (len--)
		{
			tdst[len] = tsrc[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
