/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_construction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 21:43:46 by cchampda          #+#    #+#             */
/*   Updated: 2016/02/04 21:43:49 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

unsigned int	get_min(char **piece, unsigned int i, unsigned int j, char axis)
{
	unsigned int min;

	min = 4;
	while (i < 4)
	{
		while (j < 4)
		{
			if (piece[i][j] == '#')
			{
				if (axis == 'i')
					min = (i < min) ? i : min;
				else
					min = (j < min) ? j : min;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (min);
}

unsigned int	get_max(char **piece, unsigned int i, unsigned int j, char axis)
{
	unsigned int max;

	max = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (piece[i][j] == '#')
			{
				if (axis == 'i')
					max = (i > max) ? i : max;
				else
					max = (j > max) ? j : max;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (max);
}

t_point			get_point(unsigned int i, unsigned int j)
{
	t_point point;

	point.j = j;
	point.i = i;
	return (point);
}

t_point			get_empty(unsigned int nb, t_point start,
						unsigned int width, unsigned int height, char **piece)
{
	unsigned int		i;
	unsigned int		j;

	i = start.i;
	j = start.j;
	while (i < start.i + height)
	{
		while (j < start.j + width)
		{
			if (piece[i][j] == '.')
			{
				nb--;
				if (nb == 0)
					return (get_point(i - start.i, j - start.j));
			}
			j++;
		}
		i++;
		j = start.j;
	}
	return (get_point(5, 5));
}

t_tetri			get_tetrimino(char **piece)
{
	static char	name;
	t_tetri		tetri;
	t_point		start;

	if (!name)
		name = 'A';
	else
		name++;
	tetri.name = name;
	tetri.width = get_max(piece, 0, 0, 'j') - get_min(piece, 0, 0, 'j') + 1;
	tetri.height = get_max(piece, 0, 0, 'i') - get_min(piece, 0, 0, 'i') + 1;
	start = get_point(get_min(piece, 0, 0, 'i'), get_min(piece, 0, 0, 'j'));
	tetri.empty1 = get_empty(1, start, tetri.width, tetri.height, piece);
	tetri.empty2 = get_empty(2, start, tetri.width, tetri.height, piece);
	return (tetri);
}
