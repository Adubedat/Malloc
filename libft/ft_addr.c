/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 23:23:21 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/03 17:08:20 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addr(void *v)
{
	unsigned long int	nbr;
	int					base[2];
	char				*str;
	char				*b;

	b = "0123456789abcdef";
	base[0] = 16;
	nbr = (unsigned long int)v;
	base[1] = ft_ulli_len_base(nbr, 16) + 2;
	str = (char*)malloc(sizeof(char) * base[1] + 1);
	str[base[1]] = '\0';
	str[0] = '0';
	str[1] = 'x';
	base[1]--;
	if (nbr == 0)
		str[2] = '0';
	while (nbr != 0)
	{
		str[base[1]] = b[nbr % 16];
		base[1]--;
		nbr /= 16;
	}
	return (str);
}
