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
#include <stdio.h>
#include "fillit.h"

int		has_valid_chars(char *text)
{
	int i;

	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] != '\n' && text[i] != '#' && text[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		has_valid_structure(char *text)
{
	int nb_n;
	int nb_chars;

	nb_n = 0;
	nb_chars = 0;
	while (*text != '\0')
	{
		if (*text != '\n')
			nb_chars++;
		if (*text == '\n')
		{
			nb_n++;
			if (nb_chars > 4)
				return (0);
			else if (nb_chars == 4)
				nb_chars = 0;
			else if (nb_chars == 0)
			{
				if (!(nb_n + 1 >= 5 && nb_n + 1 % 5 == 0))
					return (0);
			}
		}
		text++;
	}
	return (1);
}

int		get_nb_pieces(char *text)
{
	int i;
	int nb_n;
	int	nb_pieces;

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
