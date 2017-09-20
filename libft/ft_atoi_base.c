/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:43:40 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/02 22:11:33 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		convert(int i, const char *str, int str_base)
{
	int result;
	int temp;

	result = 0;
	temp = 1;
	while (i >= 0)
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			result = result + ((str[i] - 87) % str_base) * temp;
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result + ((str[i] - 55) % str_base) * temp;
		else if (str[i] == '-')
			result = result + 0;
		else
			result = result + ((str[i] - '0') % str_base) * temp;
		temp *= str_base;
		i--;
	}
	if (str[0] == '-')
		result = -result;
	return (result);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int		i;
	char	*base;
	int		result;
	int		j;

	i = 0;
	base = "0123456789abcdef";
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < (str_base - 1) && str[i] != base[j]
				&& str[i] != base[j] - 32)
			j++;
		if (str[i] != base[j] && str[i] != base[j] - 32)
			return (0);
		i++;
	}
	i--;
	result = convert(i, str, str_base);
	return (result);
}
