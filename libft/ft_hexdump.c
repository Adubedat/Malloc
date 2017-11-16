/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:58:15 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/16 17:56:14 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hexdump_char(unsigned char *str, int len)
{
	int i;

	i = 0;
	ft_printf("  ");
	while (i < len)
	{
		if ((str[i] >= 0 && str[i] <= 32)
			|| (str[i] >= 127))
			ft_printf(".");
		else
			ft_printf("%c", str[i]);
		i++;
	}
}

void	ft_hexdump(void *memory, int len)
{
	unsigned char	*byte;
	int				i;
	int				space;

	i = 0;
	byte = (unsigned char*)memory;
	ft_printf("%p:", &byte[i]);
	while (i < len)
	{
		if (i % 16 == 0 && i != 0)
		{
			ft_hexdump_char(&byte[i - 16], 16);
			ft_printf("\n%p:", &byte[i]);
		}
		ft_printf(" %02hhx", byte[i++]);
	}
	if (i % 16 == 0)
		space = 0;
	else
		space = (16 - (i % 16)) * 3;
	ft_printf("%*s", space, "");
	ft_hexdump_char(&byte[i - (16 - space / 3)], (16 - space / 3));
	ft_putchar('\n');
}
