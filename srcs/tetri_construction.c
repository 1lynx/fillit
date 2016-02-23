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

t_point			get_pt(unsigned int i, unsigned int j)
{
	t_point point;

	point.j = j;
	point.i = i;
	return (point);
}

t_point			get_empty(unsigned int nb, char **piece)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	while (piece[i] != NULL)
	{
		while (piece[i][j] != '\0')
		{
			if (piece[i][j] == '.')
			{
				nb--;
				if (nb == 0)
					return (get_pt(i, j));
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (get_pt(5, 5));
}

t_tetri			get_tetrimino(char **piece)
{
	static char	name;
	t_tetri		tetri;
	t_point		start;
	char		**cut_piece;

	if (!name)
		name = 'A';
	else
		name++;
	tetri.name = name;
	tetri.width = get_max(piece, 0, 0, 'j') - get_min(piece, 0, 0, 'j') + 1;
	tetri.height = get_max(piece, 0, 0, 'i') - get_min(piece, 0, 0, 'i') + 1;
	start = get_pt(get_min(piece, 0, 0, 'i'), get_min(piece, 0, 0, 'j'));
	cut_piece = get_partial_tab(piece, start, tetri.width, tetri.height);
	tetri.empty1 = get_empty(1, cut_piece);
	tetri.empty2 = get_empty(2, cut_piece);
	free(cut_piece);
	return (tetri);
}
