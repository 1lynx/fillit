/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:42:11 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 22:05:42 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	if (i == n)
		i--;
	c1 = (unsigned char)s1[i];
	c2 = (unsigned char)s2[i];
	return (int)(c1 - c2);
}
