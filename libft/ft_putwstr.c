/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:34:26 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/03 12:02:07 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putwstr(wchar_t *s, int precision)
{
	int		i;
	int		len;
	char	*temp;
	char	*str;

	i = 0;
	len = 0;
	str = ft_strnew(0);
	while (s[i] != '\0')
	{
		temp = ft_putwchar(s[i]);
		len += ft_strlen(temp);
		if (precision != -1)
		{
			if (len <= precision)
				str = ft_strjoin_free_s1(str, temp);
		}
		else
			str = ft_strjoin_free_s1(str, temp);
		i++;
		free(temp);
	}
	return (str);
}
