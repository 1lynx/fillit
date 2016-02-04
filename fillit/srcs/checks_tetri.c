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

int		has_four_blocks(char **piece)
{
	unsigned int i;
	unsigned int j;
	unsigned int nb_blocks;

	i = 0;
	j = 0;
	nb_blocks = 0;
	while (i < 4)
	{
		while (tetr[i][j] != '\0')
		{
			if (tetr[i][j] == '#')
				nb_blocks++;
			j = 0;
			i++;
		}
	}
	return (nb_blocks == 4) ? 1 : 0;
}

int		get_block_contacts_nb(unsigned int i, unsigned int j, char **piece)
{
	unsigned int nb_contacts;

	nb_contacts = 0;
	if (i != 0)
		nb_contacts += (piece[i - 1][j] == '#') ? 1 : 0;
	if (i != 0)
		nb_contacts += (piece[i][j - 1] == '#') ? 1 : 0;
	if (i != 0)
		nb_contacts += (piece[i + 1][j] == '#') ? 1 : 0;
	if (i != 0)
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
	while (i < 4)
	{
		while (j < 4)
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
