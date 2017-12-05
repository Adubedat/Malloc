/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:58:15 by adubedat          #+#    #+#             */
/*   Updated: 2017/12/05 21:39:04 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hexdump_char(unsigned char *str, int len)
{
	int i;

	i = 0;
	ft_putstr("  ");
	while (i < len)
	{
		if ((str[i] >= 0 && str[i] <= 32)
			|| (str[i] >= 127))
			ft_putchar('.');
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void	print_byte(unsigned char byte)
{
	char	*b;

	b = "0123456789abcdef";
	ft_putchar(' ');
	ft_putchar(b[byte / 16]);
	ft_putchar(b[byte % 16]);
}

void	print_space(int space)
{
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
	}
}

void	ft_hexdump(void *memory, int len)
{
	unsigned char	*byte;
	int				i;
	int				space;

	i = 0;
	if (!memory)
		return ;
	byte = (unsigned char*)memory;
	print_addr(&byte[i]);
	while (i < len)
	{
		if (i % 16 == 0 && i != 0)
		{
			ft_hexdump_char(&byte[i - 16], 16);
			print_addr(&byte[i]);
		}
		print_byte(byte[i++]);
	}
	if (i % 16 == 0)
		space = 0;
	else
		space = (16 - (i % 16)) * 3;
	print_space(space);
	ft_hexdump_char(&byte[i - (16 - space / 3)], (16 - space / 3));
}
