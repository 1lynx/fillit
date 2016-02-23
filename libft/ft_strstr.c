/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:02:38 by agfernan          #+#    #+#             */
/*   Updated: 2015/11/27 20:13:41 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_search_start_index(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = 0;
	while (str[i] != '\0')
	{
		start = i;
		if (str[i] == to_find[0])
		{
			while (str[i] == to_find[j] && to_find[j] != '\0')
			{
				i++;
				j++;
			}
			if (to_find[j] == '\0')
				return ((char *)str + start);
		}
		j = 0;
		i = start + 1;
	}
	return (NULL);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	if (s2[0] == '\0')
		return ((char *)s1);
	return (find_search_start_index(s1, s2));
}
