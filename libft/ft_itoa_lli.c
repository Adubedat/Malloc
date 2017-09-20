/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:46:45 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/02 21:52:41 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_lli2(long long int n, char *str, size_t size)
{
	while (n != 0)
	{
		str[size] = -(n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}

char			*ft_itoa_lli(long long int n)
{
	size_t	size;
	char	*str;

	size = ft_lli_len(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	str[size] = '\0';
	size--;
	if (n == 0 || n == -0)
		str[size] = '0';
	if (n < 0)
		str[0] = '-';
	if (n > 0)
	{
		while (n != 0)
		{
			str[size] = (n % 10) + '0';
			n = n / 10;
			size--;
		}
	}
	else
		str = ft_itoa_lli2(n, str, size);
	return (str);
}
