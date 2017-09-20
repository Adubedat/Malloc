/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:46:45 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/02 21:53:06 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_ulli(unsigned long long int n)
{
	size_t	size;
	char	*str;

	size = ft_ulli_len(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	str[size] = '\0';
	size--;
	if (n == 0)
		str[size] = '0';
	while (n != 0)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}
