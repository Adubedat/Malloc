/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:33:17 by adubedat          #+#    #+#             */
/*   Updated: 2015/11/30 17:04:41 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*lstnext;

	if (alst && *alst && del)
	{
		temp = *alst;
		while (temp && del)
		{
			lstnext = temp->next;
			(*del)(temp->content, temp->content_size);
			free(temp);
			temp = lstnext;
		}
		*alst = NULL;
	}
}
