/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:02:37 by adubedat          #+#    #+#             */
/*   Updated: 2017/12/05 21:53:58 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

void	print_alloc(void *start, void *end, size_t size)
{
	print_addr(start);
	ft_putstr(" - ");
	print_addr(end);
	ft_putstr(" : ");
	ft_putnbr(size);
	ft_putstr(" octets\n");
}

void	print_large(void *ptr)
{
	ft_putstr("LARGE : ");
	print_addr(ptr);
	ft_putchar('\n');
}

void	print_total(size_t total)
{
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putstr(" octets\n");
}

void	print_free(void *ptr)
{
	ft_putstr("Free called for pointer ");
	print_addr(ptr);
	ft_putchar('\n');
}
