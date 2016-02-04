/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:22:06 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/09 17:50:07 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define BUF_SIZE 512

typedef struct		s_point
{
	unsigned int	i;
	unsigned int	j;
}								  t_point;

typedef struct	s_tetri
{
	char					name;
	unsigned int	height;
	unsigned int	width;
	t_point				empty1;
	t_point				empty2;
}								t_tetri;

char		*get_text(char *path);
int			get_nb_pieces(char *text);
int			has_valid_chars(char *text);
int			has_valid_structure(char *text);
int			has_four_blocks(char **piece);
int			get_block_contacts_nb(unsigned int i, unsigned int j, char **piece);
int			has_enough_contacts(char **piece);
int			is_valid_tetrimino(char **tetr);
char		**get_raw_tab(char *path);
int			get_tab_min_size(int nb_tetri);
t_point	get_point(unsigned int i, unsigned int j);
t_tetri	get_tetrimino(char **piece);
t_tetri	*get_pieces_tab(char **raw_tab, int nb_pieces);
char		**create_map(int size);
int			place_tetri(char **map, t_tetri tetri, t_point start);
int			resolve(char **map, t_tetri *tetris, t_point start, int nb, int i);
void		print_str_tab(char **tab);
char		**get_partial_tab(char **tab, t_point start, int width, int height);
int			cmp_points(t_point pt1, t_point pt2);

#endif
