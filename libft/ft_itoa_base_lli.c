/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lli.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 20:53:09 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/02 21:49:46 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lli_len_base(long long int nbr, int base)
{
	int result;

	result = 0;
	if (nbr < 0 && base == 10)
		result++;
	if (nbr == 0 || nbr == -0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		result++;
	}
	return (result);
}

static char		*ft_itoa_base_lli2(long long int v, int base, char *b, int l)
{
	char *str;

	str = (char*)malloc(sizeof(char) * l + 1);
	str[l] = '\0';
	if (v < 0)
	{
		while (v != 0)
		{
			str[l] = b[-(v % base)];
			l--;
			v /= base;
		}
	}
	else
	{
		while (v != 0)
		{
			str[l] = b[v % base];
			l--;
			v /= base;
		}
	}
	return (str);
}

char			*ft_itoa_base_lli(long long int value, int base, char c)
{
	char	*str;
	int		len;
	char	*b;

	if (c == 'x')
		b = ft_strdup("0123456789abcdef");
	else
		b = ft_strdup("0123456789ABCDEF");
	len = ft_lli_len_base(value, base);
	str = ft_itoa_base_lli2(value, base, b, len);
	if (value == 0 || value == -0)
	{
		str[0] = '0';
		return (str);
	}
	len--;
	if (value < 0 && base == 10)
		str[0] = '-';
	free(b);
	return (str);
}
