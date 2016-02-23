/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:31:15 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 23:05:24 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	str = ft_strnew(ft_strlen(s));
	if (str)
	{
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
