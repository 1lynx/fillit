/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:50:43 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 23:03:59 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		size;
	char		*cpy;
	size_t		i;

	i = 0;
	size = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(*cpy) * size + 1);
	if (!cpy)
		return (NULL);
	while (i < size)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
