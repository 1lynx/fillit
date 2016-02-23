/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_partial_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:22:30 by agfernan          #+#    #+#             */
/*   Updated: 2016/01/22 17:24:17 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**get_partial_tab(char **tab, t_point start, int width, int height)
{
	unsigned int	i;
	char			**ret;

	i = start.i;
	ret = malloc(sizeof(*ret) * height + 1);
	if (!ret)
		return (NULL);
	while (i <= start.i + height - 1)
	{
		ret[i - start.i] = ft_strsub(tab[i], start.j, width);
		i++;
	}
	ret[height] = NULL;
	return (ret);
}
