/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:19:39 by agfernan          #+#    #+#             */
/*   Updated: 2015/11/25 12:23:32 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = malloc(size * sizeof(*ret));
	if (!ret)
		return (NULL);
	else
		ft_bzero(ret, size);
	return (ret);
}
