/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 20:48:22 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/18 20:53:52 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		unsigned_conv(va_list args, t_flags f)
{
	t_modifier	m;
	int			len;
	char		*str;

	str = NULL;
	initialize_m(&m);
	if (f.modifier == 0 && f.conversion != 'O' && f.conversion != 'U')
	{
		m.ui = va_arg(args, unsigned int);
		if (f.conversion == 'o')
			str = ft_itoa_base_ulli((unsigned long long int)m.ui, 8, 'o');
		else if (f.conversion == 'x')
			str = ft_itoa_base_ulli((unsigned long long int)m.ui, 16, 'x');
		else if (f.conversion == 'X')
			str = ft_itoa_base_ulli((unsigned long long int)m.ui, 16, 'X');
		else if (f.conversion == 'u')
			str = ft_itoa_ulli((unsigned long long int)m.ui);
	}
	str = unsigned_conv2(str, args, f, m);
	str = apply_flags(str, f);
	len = ft_strlen(str);
	free(str);
	free(f.param);
	return (len);
}

char	*unsigned_conv2(char *str, va_list args, t_flags f, t_modifier m)
{
	if (f.modifier == 1 && f.conversion != 'O' && f.conversion != 'U')
	{
		m.uc = va_arg(args, unsigned int);
		if (f.conversion == 'o')
			return (ft_itoa_base_ulli((unsigned long long int)m.uc, 8, 'o'));
		else if (f.conversion == 'x')
			return (ft_itoa_base_ulli((unsigned long long int)m.uc, 16, 'x'));
		else if (f.conversion == 'X')
			return (ft_itoa_base_ulli((unsigned long long int)m.uc, 16, 'X'));
		else if (f.conversion == 'u')
			return (ft_itoa_ulli((unsigned long long int)m.uc));
	}
	else if (f.modifier == 2 && f.conversion != 'O' && f.conversion != 'U')
	{
		m.usi = va_arg(args, unsigned int);
		if (f.conversion == 'o')
			return (ft_itoa_base_ulli((unsigned long long int)m.usi, 8, 'o'));
		else if (f.conversion == 'x')
			return (ft_itoa_base_ulli((unsigned long long int)m.usi, 16, 'x'));
		else if (f.conversion == 'X')
			return (ft_itoa_base_ulli((unsigned long long int)m.usi, 16, 'X'));
		else if (f.conversion == 'u')
			return (ft_itoa_ulli((unsigned long long int)m.usi));
	}
	return (unsigned_conv3(str, args, f, m));
}

char	*unsigned_conv3(char *str, va_list args, t_flags f, t_modifier m)
{
	if (f.modifier == 3 && f.conversion != 'O' && f.conversion != 'U')
	{
		m.ulli = va_arg(args, unsigned long long int);
		if (f.conversion == 'o')
			return (ft_itoa_base_ulli((unsigned long long int)m.ulli, 8, 'o'));
		else if (f.conversion == 'x')
			return (ft_itoa_base_ulli((unsigned long long int)m.ulli, 16, 'x'));
		else if (f.conversion == 'X')
			return (ft_itoa_base_ulli((unsigned long long int)m.ulli, 16, 'X'));
		else if (f.conversion == 'u')
			return (ft_itoa_ulli((unsigned long long int)m.ulli));
	}
	else if (f.modifier == 4 || f.conversion == 'O' || f.conversion == 'U')
	{
		m.uli = va_arg(args, unsigned long int);
		if (f.conversion == 'o' || f.conversion == 'O')
			return (ft_itoa_base_ulli((unsigned long long int)m.uli, 8, 'o'));
		else if (f.conversion == 'x')
			return (ft_itoa_base_ulli((unsigned long long int)m.uli, 16, 'x'));
		else if (f.conversion == 'X')
			return (ft_itoa_base_ulli((unsigned long long int)m.uli, 16, 'X'));
		else if (f.conversion == 'u' || f.conversion == 'U')
			return (ft_itoa_ulli((unsigned long long int)m.uli));
	}
	return (unsigned_conv4(str, args, f, m));
}

char	*unsigned_conv4(char *str, va_list args, t_flags f, t_modifier m)
{
	if (f.modifier == 5 && f.conversion != 'O' && f.conversion != 'U')
	{
		m.uimt = va_arg(args, uintmax_t);
		if (f.conversion == 'o')
			return (ft_itoa_base_ulli((unsigned long long int)m.uimt, 8, 'o'));
		else if (f.conversion == 'x')
			return (ft_itoa_base_ulli((unsigned long long int)m.uimt, 16, 'x'));
		else if (f.conversion == 'X')
			return (ft_itoa_base_ulli((unsigned long long int)m.uimt, 16, 'X'));
		else if (f.conversion == 'u')
			return (ft_itoa_ulli((unsigned long long int)m.uimt));
	}
	else if (f.modifier == 6 && f.conversion != 'O' && f.conversion != 'U')
	{
		m.st = va_arg(args, size_t);
		if (f.conversion == 'o')
			return (ft_itoa_base_ulli((unsigned long long int)m.st, 8, 'o'));
		else if (f.conversion == 'x')
			return (ft_itoa_base_ulli((unsigned long long int)m.st, 16, 'x'));
		else if (f.conversion == 'X')
			return (ft_itoa_base_ulli((unsigned long long int)m.st, 16, 'X'));
		else if (f.conversion == 'u')
			return (ft_itoa_ulli((unsigned long long int)m.st));
	}
	return (str);
}
