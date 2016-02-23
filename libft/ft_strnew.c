/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:26:30 by agfernan          #+#    #+#             */
/*   Updated: 2015/11/27 20:09:21 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str)
	{
		i = 0;
		while (i <= size)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	return (NULL);
}
