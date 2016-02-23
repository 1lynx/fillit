/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:22:38 by agfernan          #+#    #+#             */
/*   Updated: 2016/01/22 17:24:42 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point			get_point(unsigned int i, unsigned int j)
{
	t_point point;

	point.j = j;
	point.i = i;
	return (point);
}
