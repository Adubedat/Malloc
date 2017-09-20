/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:24:57 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/04 19:35:24 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*char_conv2(va_list args, t_flags f, char *str)
{
	t_modifier m;

	if (f.modifier == 4 || f.conversion == 'C')
	{
		m.wit = va_arg(args, wint_t);
		if (m.wit == 0)
			return (NULL);
		str = ft_putwchar(m.wit);
	}
	else if (f.conversion == '%')
	{
		free(str);
		str = ft_strdup("%");
		str = apply_flags(str, f);
	}
	else
	{
		m.i = va_arg(args, int);
		if (m.i == 0)
			return (NULL);
		str = ft_strdup((const char*)&m.i);
	}
	return (str);
}

int		char_conv(va_list args, t_flags f)
{
	int			len;
	char		*str;

	len = 0;
	str = NULL;
	str = char_conv2(args, f, str);
	if (str == NULL)
	{
		str = ft_strnew(0);
		f.null = 1;
	}
	if (f.conversion != '%' && str)
	{
		str = apply_flags(str, f);
		len = ft_strlen(str);
		if (f.null == 1 && str[0] == '\0')
			len = ft_strlen(str) + 1;
	}
	else if (f.conversion == '%')
		len = ft_strlen(str);
	free(str);
	free(f.param);
	return (len);
}

void	ft_putstr_0(char *str)
{
	int i;

	i = 1;
	if (str[0] == '\0')
	{
		ft_putchar('\0');
		return ;
	}
	while (str[i - 1])
	{
		ft_putchar(str[i]);
		i++;
	}
}
