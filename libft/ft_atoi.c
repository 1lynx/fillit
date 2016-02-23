/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:17:27 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 22:01:40 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		negative;

	negative = 0;
	result = 0;
	while (is_white_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		negative = (*str == '-') ? 1 : 0;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (negative == 1) ? result * (-1) : result;
}
