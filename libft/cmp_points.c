/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:23:01 by agfernan          #+#    #+#             */
/*   Updated: 2016/01/22 17:23:02 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cmp_points(t_point pt1, t_point pt2)
{
	return (pt1.i == pt2.i && pt1.j == pt2.j) ? 1 : 0;
}
