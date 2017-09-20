/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:45:18 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/03 15:36:29 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	c2;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	c2 = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == c2)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
