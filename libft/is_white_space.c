/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_white_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:23:12 by agfernan          #+#    #+#             */
/*   Updated: 2016/01/22 17:23:19 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char c)
{
	return (c == '\r' || c == '\f' || c == '\v'
			|| c == '\t' || c == '\n' || c == ' ') ? 1 : 0;
}