/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:51:12 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/01 20:27:46 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strwdup(const wchar_t *s)
{
	size_t	s_size;
	wchar_t	*str;
	int		i;

	i = 0;
	s_size = ft_strwlen(s);
	str = (wchar_t *)malloc(sizeof(*str) * (s_size + 1));
	if (str)
	{
		while (s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
