/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:10:49 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/03 15:37:03 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	unsigned char		c1;
	size_t				i;

	i = 0;
	s1 = s;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
