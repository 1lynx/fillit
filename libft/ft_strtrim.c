/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:22:52 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 22:09:15 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	find_start_index(char const *s)
{
	int i;

	i = 0;
	while (is_white_space(s[i]))
		i++;
	return (i);
}

static int	find_end_index(char const *s)
{
	int i;

	i = (int)ft_strlen(s) - 1;
	while (is_white_space(s[i]))
		i--;
	return (i);
}

static int	is_only_white_spaces(char const *s)
{
	int i;

	i = 0;
	while (is_white_space(s[i]))
		i++;
	if (s[i] == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i_start;
	int		i_end;
	int		i;

	if (is_only_white_spaces(s))
		return ("");
	i = -1;
	i_start = find_start_index(s);
	i_end = find_end_index(s);
	str = (char *)malloc(sizeof(*str) * (i_end - i_start + 2));
	if (!str)
		return (NULL);
	while (i <= (i_end - i_start))
	{
		str[i] = s[i_start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
