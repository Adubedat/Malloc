/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:32:15 by adubedat          #+#    #+#             */
/*   Updated: 2015/11/30 17:05:18 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*lst_next;

	if (alst && *alst && del)
	{
		temp = *alst;
		lst_next = temp->next;
		(*del)(temp->content, temp->content_size);
		free(temp);
		temp->next = lst_next;
		*alst = NULL;
	}
}
