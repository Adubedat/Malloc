/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:36:19 by adubedat          #+#    #+#             */
/*   Updated: 2015/11/26 23:44:40 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int t;

	i = 0;
	while (s[i + 1] != '\0')
	{
		i++;
		t = i + 1;
	}
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	if (c == '\0')
		return ((char *)s + t);
	return (NULL);
}
