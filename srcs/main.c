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

int		main(int argc, char **argv)
{
	t_tetri		*tetris;
	int			nb_pcs;
	char		**map;
	char		**raw_tab;

	if (argc == 2)
	{
		nb_pcs = get_nb_pieces(get_text(argv[1]));
		raw_tab = (nb_pcs != -1) ? ft_strsplit(get_text(argv[1]), '\n') : NULL;
		tetris = (nb_pcs != -1) ? get_pieces_tab(raw_tab, nb_pcs) : NULL;
		map = create_map(nb_pcs);
		if (!map || !tetris || !tetri_checks(raw_tab) || nb_pcs > 26)
			ft_putendl(ERR_MSG);
		else
		{
			while (!resolve(map, tetris, get_pt(0, 0), get_fil(nb_pcs, 0)))
				map = create_bigger_map(map, ft_strlen(map[0]) + 1);
			put_str_tab(map);
		}
	}
	else
		ft_putendl(USAGE_MSG);
	return (0);
}
