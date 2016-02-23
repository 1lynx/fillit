/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:59:39 by agfernan          #+#    #+#             */
/*   Updated: 2015/12/01 22:01:53 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	tmp = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = (*f)(lst);
		tmp = tmp->next;
	}
	return (new);
}
