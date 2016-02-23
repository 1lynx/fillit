/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:40:41 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 22:03:15 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		find;
	char	*str;
	char	chr;

	chr = (char)c;
	str = (char *)s;
	find = 0;
	i = 0;
	while (s[i] != '\0' && find != 1)
	{
		if (s[i] == chr)
			return (str + i);
		i++;
	}
	if (s[i] == chr)
		return (str + i);
	else
		return (NULL);
}
