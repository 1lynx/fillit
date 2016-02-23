/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:58:14 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 18:32:46 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	get_final_len(int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n /= 10)
		i++;
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			nb_digit;
	int			negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb_digit = get_final_len(n);
	negative = (n < 0) ? 1 : 0;
	n *= (n < 0) ? -1 : 1;
	str = (char *)malloc(sizeof(*str) * (nb_digit + 1));
	if (!str)
		return (NULL);
	str[nb_digit] = '\0';
	nb_digit--;
	while (nb_digit > 0)
	{
		str[nb_digit] = (n % 10) + '0';
		n /= 10;
		nb_digit--;
	}
	str[0] = (negative) ? '-' : (n % 10) + '0';
	return (str);
}
