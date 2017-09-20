/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:46:45 by adubedat          #+#    #+#             */
/*   Updated: 2016/03/10 09:47:14 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t	size;
	char	*str;

	size = ft_intlen(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	str[size] = '\0';
	size--;
	if (n == -2147483648)
		str = ft_strcpy(str, "-2147483648");
	else if (n == 0 || n == -0)
		str[size] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0 && n != -2147483648)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}
