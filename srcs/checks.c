/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:31:40 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/09 18:13:25 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		has_valid_chars(char *text)
{
	int i;
	int nb_blocks;

	i = 0;
	nb_blocks = 0;
	while (text[i] != '\0')
	{
		if (text[i] != '\n' && text[i] != '#' && text[i] != '.')
			return (0);
		if (text[i] == '#')
			nb_blocks++;
		i++;
	}
	return (nb_blocks >= 4) ? 1 : 0;
}

int		has_valid_structure(char *text, int nb_n, int nb_chars, int i)
{
	while (text[i + 1] != '\0')
	{
		if (text[i] != '\n')
			nb_chars++;
		else if (text[i] == '\n')
		{
			nb_n++;
			if (nb_chars > 4)
				return (0);
			else if (nb_chars == 4)
				nb_chars = 0;
			else if (nb_chars == 0)
			{
				if (!(nb_n >= 5 && nb_n % 5 == 0))
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int		get_nb_pieces(char *text)
{
	int i;
	int nb_n;
	int	nb_pieces;

	if (!text || ft_strlen(text) < 5 * 4)
		return (-1);
	if (!has_valid_structure(text, 0, 0, 0) || !has_valid_chars(text))
		return (-1);
	nb_pieces = 0;
	i = 0;
	nb_n = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '\n')
		{
			nb_n++;
			if (nb_n % 5 == 0)
				nb_pieces++;
		}
		i++;
	}
	nb_n++;
	nb_pieces++;
	return ((double)nb_pieces == (double)nb_n / 5) ? nb_pieces : -1;
}
