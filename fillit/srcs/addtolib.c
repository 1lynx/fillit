/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtolib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 21:42:32 by cchampda          #+#    #+#             */
/*   Updated: 2016/02/04 21:42:40 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	print_str_tab(char **tab)
{
	unsigned int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

char	**get_partial_tab(char **tab, t_point start, int width, int height)
{
	unsigned int	i;
	char			**ret;
	i = start.i;
	ret = malloc(sizeof(*ret) * height + 1);
	while (i <= start.i + height - 1)
	{
		ret[i - start.i] = ft_strsub(tab[start.i], start.j, width);
		i++;
	}
	ret[height] = NULL;
	return (ret);
}

int		cmp_points(t_point pt1, t_point pt2)
{
	return (pt1.i == pt2.i && pt1.j == pt2.j) ? 1 : 0;
}
