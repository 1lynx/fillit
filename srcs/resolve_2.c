/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 05:05:26 by agfernan          #+#    #+#             */
/*   Updated: 2016/02/08 05:06:08 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_fillit	get_fil(int nb, int i)
{
	t_fillit fil;

	fil.nb = nb;
	fil.i = i;
	return (fil);
}

int			is_empty(t_point pt, t_point start, t_tetri tetri)
{
	pt.i -= start.i;
	pt.j -= start.j;
	if (pt.i == tetri.empty1.i && pt.j == tetri.empty1.j)
		return (1);
	if (pt.i == tetri.empty2.i && pt.j == tetri.empty2.j)
		return (1);
	return (0);
}

int			get_tab_min_size(int nb_tetri)
{
	int i;

	i = 2;
	while (i * i < nb_tetri * 4)
		i++;
	return (i);
}

char		**create_map(int nb_pieces)
{
	char	**tab;
	int		i;
	int		size;

	if (nb_pieces <= 0)
		return (NULL);
	i = 0;
	size = get_tab_min_size(nb_pieces);
	tab = malloc(sizeof(*tab) * size + 1);
	while (i < size)
	{
		tab[i] = ft_strnew(size);
		ft_memset(tab[i], '.', size);
		tab[i][size] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char		**create_bigger_map(char **map, int new_size)
{
	char	**tab;
	int		i;

	free(map);
	if (new_size <= 0)
		return (NULL);
	i = 0;
	tab = malloc(sizeof(*tab) * new_size + 1);
	while (i < new_size)
	{
		tab[i] = ft_strnew(new_size);
		ft_memset(tab[i], '.', new_size);
		tab[i][new_size] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
