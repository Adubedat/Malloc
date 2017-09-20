/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:37:00 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/03 15:45:15 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*temp;
	t_list	*temp2;

	list = f(lst);
	temp = list;
	lst = lst->next;
	while (lst)
	{
		if (!(temp2 = f(lst)))
			return (NULL);
		temp->next = temp2;
		temp = temp2;
		lst = lst->next;
	}
	return (list);
}
