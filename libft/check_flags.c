/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 12:30:58 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/11 20:31:58 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flags		check_first_flag(t_flags f, va_list args)
{
	if (ft_strchr("#0- +", f.param[f.j]) == NULL
			&& ft_strchr(".*123456789hljz", f.param[f.j]) != NULL)
		return (check_second_flag(f, args));
	else if (ft_strchr("#0 -*+.123456789hljz", f.param[f.j]) == NULL)
		return (f);
	else
	{
		if (f.param[f.j] == '#' && ft_strchr("oOxX", f.conversion) != NULL
				&& f.diese == 0)
			f.diese = 1;
		else if (f.param[f.j] == '0' && f.zero == 0 && f.moins == 0)
			f.zero = 1;
		else if (f.param[f.j] == '-' && f.moins == 0)
		{
			f.zero = 0;
			f.moins = 1;
		}
		else if (f.param[f.j] == ' ' && f.space == 0 && f.plus == 0
				&& ft_strchr("dDi", f.conversion) != NULL)
			f.space = 1;
		else if (f.param[f.j] == '+')
			f = check_first_flag2(f);
		f.j++;
		return (check_first_flag(f, args));
	}
}

t_flags		check_first_flag2(t_flags f)
{
	if (f.param[f.j] == '+' && f.plus == 0
			&& ft_strchr("dDi", f.conversion) != NULL)
	{
		f.space = 0;
		f.plus = 1;
	}
	return (f);
}

t_flags		check_second_flag(t_flags f, va_list args)
{
	if (!(f.param[f.j] >= '0' && f.param[f.j] <= '9') && f.param[f.j] != '*')
		return (check_third_flag(f, args));
	else
	{
		if (f.param[f.j] == '*')
		{
			f.width = va_arg(args, int);
			f.j++;
		}
		else
		{
			while (f.param[f.j] >= '0' && f.param[f.j] <= '9')
			{
				f.width = f.width * 10 + f.param[f.j] - '0';
				f.j++;
			}
		}
		return (check_first_flag(f, args));
	}
}

t_flags		check_third_flag(t_flags f, va_list args)
{
	if (f.param[f.j] != '.')
		return (check_fourth_flag(f, args));
	else
	{
		f.precision = 0;
		f.j++;
		while (f.param[f.j] >= '0' && f.param[f.j] <= '9')
		{
			f.precision = f.precision * 10 + f.param[f.j] - '0';
			f.j++;
		}
		return (check_first_flag(f, args));
	}
}

t_flags		check_fourth_flag(t_flags f, va_list args)
{
	if (ft_strchr("hljz", f.param[f.j]) == NULL)
	{
		f.j++;
		return (check_first_flag(f, args));
	}
	else
	{
		if (f.param[f.j] == 'h' && f.param[f.j + 1] == 'h' && f.modifier == 0)
			f.modifier = 1;
		else if (f.param[f.j] == 'h' && f.modifier == 0)
			f.modifier = 2;
		else if (f.param[f.j] == 'l' && f.param[f.j + 1] == 'l'
				&& f.modifier == 0)
			f.modifier = 3;
		else if (f.param[f.j] == 'l' && f.modifier == 0)
			f.modifier = 4;
		else if (f.param[f.j] == 'j' && f.modifier == 0)
			f.modifier = 5;
		else if (f.param[f.j] == 'z' && f.modifier == 0)
			f.modifier = 6;
		f.j++;
		return (check_first_flag(f, args));
	}
}
