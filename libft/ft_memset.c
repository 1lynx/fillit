/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:18:33 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 18:37:03 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	if (len == 0)
		return (b);
	str = (char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return ((void *)str);
}
