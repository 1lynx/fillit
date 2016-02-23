/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opening.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:01:50 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/09 18:58:21 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

char	*get_text(char *path)
{
	char	buf[BUF_SIZE];
	int		ret;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
		return (NULL);
	buf[ret] = '\0';
	close(fd);
	return (ft_strdup(buf) != NULL) ? ft_strdup(buf) : NULL;
}

t_tetri	*get_pieces_tab(char **raw_tab, int nb_pieces)
{
	t_tetri	*lst;
	int		i;
	char	**piece;

	i = 0;
	piece = malloc(sizeof(piece) * 5);
	lst = malloc(sizeof(*lst) * nb_pieces + 1);
	if (!piece || !lst)
		return (NULL);
	while (raw_tab[i] != NULL)
	{
		piece[i % 4] = ft_strdup(raw_tab[i]);
		if ((i + 1) % 4 == 0)
		{
			piece[4] = NULL;
			lst[i / 4] = get_tetrimino(piece);
		}
		i++;
	}
	free(piece);
	lst[i].name = '0';
	return (lst);
}
