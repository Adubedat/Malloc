/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:21:37 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/16 15:55:16 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_param(const char *str, int *i, char *c, char *param)
{
	int		j;
	int		k;

	j = *i;
	k = 0;
	while (str[*i] && ft_strchr("#0 *-+.123456789hljz", str[*i]) != NULL)
		*i = *i + 1;
	if (str[*i] == '\0')
		return (NULL);
	*c = str[*i];
	if (!(param = (char*)malloc(sizeof(char) * (*i - j + 2))))
	{
		printf("%d %d\n", *i, j);
		return (NULL);
	}
	while (j <= *i)
	{
		param[k] = str[j];
		j++;
		k++;
	}
	param[k] = '\0';
	return (param);
}

t_flags	init_flags(t_flags f)
{
	f.j = 0;
	f.diese = 0;
	f.zero = 0;
	f.moins = 0;
	f.space = 0;
	f.plus = 0;
	f.width = 0;
	f.precision = -1;
	f.modifier = 0;
	f.null = 0;
	return (f);
}

int		print_var(const char *str, int *i, va_list args)
{
	t_flags f;

	if (!(f.param = get_param(str, i, &f.conversion, f.param)))
		return (0);
	f = init_flags(f);
	if (ft_strcmp(f.param, "hhld") == 0)
		f.modifier = 4;
	f = check_first_flag(f, args);
	if (f.conversion == 's' || f.conversion == 'S'
			|| ft_strchr("sSpdDioOuUxXcC%", f.conversion) == NULL)
		return (string_conv(args, f));
	else if (f.conversion == 'i' || f.conversion == 'd' || f.conversion == 'D')
		return (signed_conv(args, f));
	else if (ft_strchr("oOuUxX", f.conversion) != NULL)
		return (unsigned_conv(args, f));
	else if (f.conversion == 'c' || f.conversion == 'C' || f.conversion == '%')
		return (char_conv(args, f));
	else if (f.conversion == 'p')
		return (pointer_conv(args, f));
	return (0);
}

int		distrib(const char *str, int i, va_list args, int result)
{
	while (str[i] != '%' && str[i])
	{
		write(1, &str[i], 1);
		i++;
		result++;
	}
	if (str[i] == '%')
	{
		i++;
		result += print_var(str, &i, args);
		if (str[i])
			i++;
	}
	if (str[i])
		return (distrib(str, i, args, result));
	return (result);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	int			result;
	va_list		args;

	result = 0;
	i = 0;
	va_start(args, str);
	result = distrib(str, i, args, result);
	va_end(args);
	return (result);
}
