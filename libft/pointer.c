/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 22:59:06 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/02 21:38:25 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				pointer_conv(va_list args, t_flags f)
{
	t_modifier	m;
	int			len;
	char		*str;

	m.v = va_arg(args, void*);
	str = ft_addr(m.v);
	if (str[2] == '\0')
		ft_strjoin_free_s1(str, "0");
	str = apply_flags(str, f);
	len = ft_strlen(str);
	free(str);
	free(f.param);
	return (len);
}
