/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:00:33 by agfernan          #+#    #+#             */
/*   Updated: 2015/11/27 20:14:27 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
