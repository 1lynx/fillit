/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:02:32 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 22:00:01 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_nb_elements(const char *s, char c)
{
	int i;
	int nb;
	int isword;

	i = 0;
	nb = 0;
	isword = (s[i] == c) ? 0 : 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && isword == 1)
		{
			nb++;
			isword = 0;
		}
		else if (s[i] != c && isword == 0)
			isword = 1;
		i++;
	}
	return (isword) ? nb + 1 : nb;
}

static int	get_next_word_start_index(const char *s, int i, char c)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int	get_word_end_index(const char *s, int i, char c)
{
	while (s[i + 1] != c && s[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		nb_elem;
	int		j;

	i = 0;
	nb_elem = get_nb_elements(s, c);
	j = 0;
	tab = (char **)malloc(sizeof(*tab) * nb_elem + 1);
	if (!tab)
		return (NULL);
	if (*s == '\0')
	{
		tab[0] = NULL;
		return (tab);
	}
	while (j < nb_elem)
	{
		i = get_next_word_start_index(s, i, c);
		tab[j] = ft_strsub(s, i, get_word_end_index(s, i, c) - i + 1);
		j++;
		i = get_word_end_index(s, i, c) + 1;
	}
	tab[j] = NULL;
	return (tab);
}
