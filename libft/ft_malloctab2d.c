/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloctab2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:28:24 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/10 21:13:27 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloctab2d(size_t x, size_t y)
{
	char	**tab;
	size_t	i;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * y + 1)))
		return (NULL);
	while (i < y)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * x + 1)))
			return (NULL);
		tab[i][x] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
