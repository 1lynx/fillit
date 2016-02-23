/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 21:43:06 by cchampda          #+#    #+#             */
/*   Updated: 2016/02/04 21:43:16 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		has_four_blocks(char **piece)
{
	unsigned int i;
	unsigned int j;
	unsigned int nb_blocks;

	i = 0;
	j = 0;
	nb_blocks = 0;
	while (piece[i] != NULL)
	{
		while (piece[i][j] != '\0')
		{
			if (piece[i][j] == '#')
				nb_blocks++;
			j++;
		}
		j = 0;
		i++;
	}
	return (nb_blocks == 4) ? 1 : 0;
}

int		get_block_contacts_nb(unsigned int i, unsigned int j, char **piece)
{
	unsigned int nb_contacts;

	nb_contacts = 0;
	if (i != 0)
		nb_contacts += (piece[i - 1][j] == '#') ? 1 : 0;
	if (j != 0)
		nb_contacts += (piece[i][j - 1] == '#') ? 1 : 0;
	if (i != 3)
		nb_contacts += (piece[i + 1][j] == '#') ? 1 : 0;
	if (j != 3)
		nb_contacts += (piece[i][j + 1] == '#') ? 1 : 0;
	return (nb_contacts);
}

int		has_enough_contacts(char **piece)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	nb_contacts;

	i = 0;
	j = 0;
	nb_contacts = 0;
	while (piece[i] != NULL)
	{
		while (piece[i][j] != '\0')
		{
			if (piece[i][j] == '#')
				nb_contacts += get_block_contacts_nb(i, j, piece);
			j++;
		}
		j = 0;
		i++;
	}
	return ((nb_contacts >= 6) ? 1 : 0);
}

int		is_valid_tetrimino(char **piece)
{
	return (has_four_blocks(piece) && has_enough_contacts(piece));
}

int		tetri_checks(char **raw_tab)
{
	int		i;
	char	**piece;

	i = 0;
	piece = malloc(sizeof(piece) * 5);
	if (!piece)
		return (0);
	while (raw_tab[i] != NULL)
	{
		piece[i % 4] = ft_strdup(raw_tab[i]);
		if ((i + 1) % 4 == 0)
		{
			piece[4] = NULL;
			if (!is_valid_tetrimino(piece))
				return (0);
		}
		i++;
	}
	free(piece);
	return (1);
}
