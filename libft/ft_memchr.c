/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:18:05 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 18:59:13 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	if (n == 0)
		return (NULL);
	i = 0;
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (*str == chr)
			return ((void *)str);
		i++;
		str++;
	}
	return (NULL);
}
