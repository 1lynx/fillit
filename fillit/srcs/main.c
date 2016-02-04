/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:21:28 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/09 18:55:45 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	t_tetri *tetriminos;
	int nb_pieces;
	char **map = NULL;

	if (argc == 2)
	{
		nb_pieces = get_nb_pieces(get_text(argv[1]));
		tetriminos = get_pieces_tab(get_raw_tab(argv[1]), nb_pieces);
		map = create_map(nb_pieces);
		while (!resolve(map, tetriminos, get_point(0, 0), nb_pieces, 0))
		{
			map = create_map(ft_strlen(map[0]) + 1);
		}
		print_str_tab(map);
	}
	else
		ft_putendl("error");
	return (0);
}
