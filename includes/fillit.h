/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:22:06 by agfernan          #+#    #+#             */
/*   Updated: 2016/02/07 22:31:28 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define BUF_SIZE 512
# define ERR_MSG "error"
# define USAGE_MSG "usage: ./fillit tetriminos_file"
# include "libft.h"

typedef struct		s_tetri
{
	char			name;
	unsigned int	height;
	unsigned int	width;
	t_point			empty1;
	t_point			empty2;
}					t_tetri;

typedef struct		s_fillit
{
	int				i;
	int				nb;
}					t_fillit;

t_fillit			get_fil(int nb, int i);
char				*get_text(char *path);
int					get_nb_pieces(char *text);
int					has_valid_chars(char *text);
int					has_valid_structure(char *text, int nb_n,
						int nb_pieces, int i);
int					has_four_blocks(char **piece);
int					get_block_contacts_nb(unsigned int i,
				unsigned int j, char **piece);
int					has_enough_contacts(char **piece);
int					is_valid_tetrimino(char **tetr);
int					get_tab_min_size(int nb_tetri);
t_point				get_pt(unsigned int i, unsigned int j);
t_tetri				get_tetrimino(char **piece);
t_tetri				*get_pieces_tab(char **raw_tab, int nb_pieces);
char				**create_map(int size);
int					is_empty(t_point pt, t_point start, t_tetri tetri);
int					place_tetri(char **map, t_tetri tetri, t_point start);
int					resolve(char **map, t_tetri *tetris,
						t_point start, t_fillit fil);
char				**get_partial_tab(char **tab, t_point start,
				int width, int height);
int					tetri_checks(char **raw_tab);
char				**create_bigger_map(char **map, int new_size);

#endif
