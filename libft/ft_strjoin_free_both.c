/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:44:05 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/04 16:57:24 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_both(char const *s1, char const *s2)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str)
	{
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
		free((void*)s1);
		free((void*)s2);
		return (str);
	}
	return (NULL);
}
