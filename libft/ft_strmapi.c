/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:56:47 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 23:05:25 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = ft_strnew(ft_strlen(s));
	if (str)
	{
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
