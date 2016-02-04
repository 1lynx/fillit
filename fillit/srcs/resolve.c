/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 21:43:31 by cchampda          #+#    #+#             */
/*   Updated: 2016/02/04 21:43:34 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		is_empty(t_point pt, t_point start, t_tetri tetri)
{
	pt.i -= start.i;
	pt.j -= start.j;
	if (pt.i == tetri.empty1.i && pt.j == tetri.empty1.j)
		return (1);
	if (pt.i == tetri.empty2.i && pt.j == tetri.empty2.j)
		return (1);
	return (0);
}

int		get_tab_min_size(int nb_tetri)
{
	int i;

	i = 2;
	while (i * i < nb_tetri * 4)
		i++;
	return (i);
}

char	**create_map(int nb_pieces)
{
	char **tab;
	int i;
	int size;

	i = 0;
	size = get_tab_min_size(nb_pieces);
	tab = malloc(sizeof(*tab) * size + 1);
	while (i < size)
	{
		tab[i] = ft_strnew(size);
		ft_memset(tab[i], '.', size);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int		clean_tetri(char **map, t_tetri tetri, t_point start)
{
	t_point pt;

	pt = get_point(start.i, start.j);
	while (pt.i < start.i + tetri.height && map[pt.i] != NULL)
	{
		while (pt.j < (start.j + tetri.width) && map[pt.i][pt.j] != '\0')
		{
			if (map[pt.i][pt.j] == tetri.name)
				map[pt.i][pt.j] = '.';
				pt.j++;
		}
		pt.i++;
		pt.j = start.j;
	}
	return (0);
}

int		place_tetri(char **map, t_tetri tetri, t_point start)
{
	t_point pt;

	pt = get_point(start.i, start.j);
	while (pt.i < start.i + tetri.height)
	{
		if (map[pt.i] == NULL)
			return (clean_tetri(map, tetri, start));
		while (pt.j < start.j + tetri.width)
		{
			if ((ft_isalpha(map[pt.i][pt.j]) && !is_empty(pt, start, tetri))
					|| map[pt.i][pt.j] == '\0')
				return (clean_tetri(map, tetri, start));
			if (!is_empty(pt, start, tetri))
				map[pt.i][pt.j] = tetri.name;
			pt.j++;
		}
		pt.i++;
		pt.j = start.j;
	}
	return (1);
}

int		move_pt(char **map, t_point *pt, t_tetri tetri)
{
	pt->j++;
	if (map[pt->i][pt->j] == '\0' && pt->j + tetri.width > ft_strlen(map[0]))
	{
		pt->i++;
		pt->j = 0;
	}
	if (map[pt->i] == NULL || pt->i + tetri.height > ft_strlen(map[0]))
		return (0);
	return (1);
}

int		test_move_pt(char **map, t_point pt, t_tetri tetri)
{
	pt.j++;
	if (map[pt.i][pt.j] == '\0' && pt.j + tetri.width > ft_strlen(map[0]))
	{
		pt.i++;
		pt.j = 0;
	}
	if (map[pt.i] == NULL || pt.i + tetri.height > ft_strlen(map[0]))
		return (0);
	return (1);
}

int		resolve(char **map, t_tetri *tetris, t_point start, int nb, int i)
{
	if (i == nb)
		return (1);
	if (!test_move_pt(map, start, tetris[i]) && i == 0)
		return (0);
	if (!(place_tetri(map, tetris[i], start)))
	{
		if (move_pt(map, &start, tetris[i]))
			return (resolve(map, tetris, start, nb, i));
		else
			return (0);
	}
	else
	{
		if (!resolve(map, tetris, get_point(0, 0), nb, i + 1))
		{
			clean_tetri(map, tetris[i], start);
			if (move_pt(map, &start, tetris[i]))
				return (resolve(map, tetris, start, nb, i));
		}
		else
			return (1);
	}
	return (0);
}
