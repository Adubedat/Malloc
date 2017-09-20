/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:51:12 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/11 18:45:32 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_size;
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_size = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (s_size + 1));
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
