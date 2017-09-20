/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 15:44:32 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/18 20:55:11 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*signed_conv3(char *str, va_list args, t_flags f, t_modifier m)
{
	if (f.modifier == 5 && f.conversion != 'D')
	{
		m.imt = va_arg(args, intmax_t);
		return (ft_itoa_lli((long long int)m.imt));
	}
	else if (f.modifier == 6 & f.conversion != 'D')
	{
		m.st = va_arg(args, size_t);
		return (ft_itoa_lli((long long int)m.st));
	}
	return (str);
}

int			signed_conv(va_list args, t_flags f)
{
	t_modifier	m;
	char		*str;

	str = NULL;
	initialize_m(&m);
	if (f.modifier == 0 && f.conversion != 'D')
	{
		m.i = va_arg(args, int);
		str = ft_itoa(m.i);
	}
	else if (f.modifier == 1 && f.conversion != 'D')
	{
		m.c = va_arg(args, int);
		str = ft_itoa_lli((long long int)m.c);
	}
	str = signed_conv2(str, args, f, m);
	str = apply_flags(str, f);
	f.diese = ft_strlen(str);
	free(str);
	free(f.param);
	return (f.diese);
}

char		*signed_conv2(char *str, va_list args, t_flags f, t_modifier m)
{
	if (f.modifier == 2 && f.conversion != 'D')
	{
		m.si = va_arg(args, int);
		str = ft_itoa_lli((long long int)m.si);
	}
	else if (f.modifier == 3 && f.conversion != 'D')
	{
		m.lli = va_arg(args, long long int);
		return (ft_itoa_lli(m.lli));
	}
	else if (f.modifier == 4 || f.conversion == 'D')
	{
		m.li = va_arg(args, long int);
		return (ft_itoa_lli((long long int)m.li));
	}
	str = signed_conv3(str, args, f, m);
	return (str);
}
