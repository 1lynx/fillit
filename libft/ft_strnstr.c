/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:39:26 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 22:28:48 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void	how_to_win_three_lines(size_t *i, size_t *j)
{
	size_t useless;

	*i = *i + 1;
	*j = *j + 1;
	useless = *i + *j;
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		start;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	j = 0;
	start = 0;
	while (s1[i] != '\0')
	{
		start = i;
		if (s1[i] == s2[0])
		{
			while (s1[i] == s2[j] && s2[j] != '\0')
				how_to_win_three_lines(&i, &j);
			if (s2[j] == '\0' && i <= n)
				return ((char *)s1 + start);
		}
		j = 0;
		i = start + 1;
	}
	return (NULL);
}
