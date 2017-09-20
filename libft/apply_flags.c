/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:15:01 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/04 19:13:41 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_flags(char *str, t_flags f)
{
	if (f.diese == 1 && str[0] != '0')
	{
		if (f.conversion == 'o' || f.conversion == 'O')
			str = ft_strjoin_free_s2("0", str);
		else if (f.conversion == 'x')
			str = ft_strjoin_free_s2("0x", str);
		else if (f.conversion == 'X')
			str = ft_strjoin_free_s2("0X", str);
	}
	if (f.space == 1 && str[0] != '-')
		str = ft_strjoin_free_s2(" ", str);
	if (f.plus == 1 && str[0] != '-')
		str = ft_strjoin_free_s2("+", str);
	return (apply_precision(str, f));
}

char	*apply_precision(char *str, t_flags f)
{
	if (f.precision != -1 && (f.conversion == 's' || f.conversion == 'S')
			&& ft_strlen(str) > (size_t)f.precision)
		str = ft_strsub_free(str, 0, f.precision);
	if (f.precision == 0 && (f.conversion == 'x' || f.conversion == 'X'))
	{
		free(str);
		str = ft_strdup("");
	}
	if (f.precision == 0 && ft_strchr("dDioOuUp", f.conversion) != NULL)
	{
		if (str[0] == '0' && f.diese == 0)
		{
			free(str);
			if (f.conversion == 'p')
				str = ft_strdup("0x");
			else
				str = ft_strdup("");
		}
	}
	else if (f.precision != -1 && ft_strchr("dDioOuUxXp", f.conversion) != NULL)
		str = apply_precision2(str, f);
	return (apply_width(str, f));
}

char	*apply_precision2(char *str, t_flags f)
{
	char	c;
	char	*str2;

	c = str[0];
	if (!(c >= '0' && c <= '9') && f.conversion != 'x' && f.conversion != 'X'
		&& (size_t)f.precision >= ft_strlen(str))
	{
		str[0] = '0';
		while ((size_t)f.precision > ft_strlen(str))
			str = ft_strjoin_free_s2("0", str);
		str2 = ft_strnew(1);
		str2[0] = c;
		str = ft_strjoin_free_s2(str2, str);
		free(str2);
	}
	if (f.conversion == 'p' || (f.conversion == 'x' && f.diese == 1))
	{
		str[1] = '0';
		while ((size_t)f.precision > ft_strlen(str) - 2)
			str = ft_strjoin_free_s2("0", str);
		str[1] = 'x';
	}
	while ((size_t)f.precision > ft_strlen(str))
		str = ft_strjoin_free_s2("0", str);
	return (str);
}

char	*apply_width(char *str, t_flags f)
{
	if (f.precision < f.width && f.precision != -1
			&& ft_strchr("dDioOuUxXp", f.conversion) != NULL)
		f.zero = 0;
	while (ft_strlen(str) < (size_t)f.width)
	{
		if (f.zero == 0 && f.moins == 0)
			str = ft_strjoin_free_s2(" ", str);
		str = apply_width2(str, f);
		if (f.zero == 0 && f.moins == 1)
			str = ft_strjoin_free_s1(str, " ");
		else if (f.zero == 1 && f.moins == 1)
			str = ft_strjoin_free_s1(str, "0");
	}
	if (f.null == 0)
		ft_putstr(str);
	else
		ft_putstr_0(str);
	return (str);
}

char	*apply_width2(char *str, t_flags f)
{
	char c;

	c = str[0];
	if (f.zero == 1 && f.moins == 0 && !(c >= '0' && c <= '9')
			&& ft_strchr("dDioOuUp", f.conversion) != NULL)
	{
		str[0] = '0';
		str = ft_strjoin_free_s2("0", str);
		str[0] = c;
		return (str);
	}
	else if (f.zero == 1 && f.moins == 0 && (f.conversion == 'p'
			|| (f.diese == 1 && (f.conversion == 'x' || f.conversion == 'X'))))
	{
		str[1] = '0';
		str = ft_strjoin_free_s2("0", str);
		if (f.conversion == 'x' || f.conversion == 'p')
			str[1] = 'x';
		else
			str[1] = 'X';
		return (str);
	}
	else if (f.zero == 1 && f.moins == 0)
		return (ft_strjoin_free_s2("0", str));
	return (str);
}
