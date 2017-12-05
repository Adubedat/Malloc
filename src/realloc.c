/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:27:29 by adubedat          #+#    #+#             */
/*   Updated: 2017/12/05 18:24:29 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

void	*realloc_large(void *ptr, size_t size)
{
	t_large_header	*header;
	void			*memory;

	header = ptr - sizeof(t_large_header) - sizeof(t_block_list);
	if (size > (header->size - getpagesize()) && size <= header->size)
		return (ptr);
	else
	{
		memory = malloc(size);
		if (size < header->size)
			ft_memcpy(memory, ptr, size);
		else
			ft_memcpy(memory, ptr, (header->size
			- sizeof(t_large_header) - sizeof(t_block_list)));
		free(ptr);
		return (memory);
	}
}

void	*realloc_small_tiny(void *ptr, size_t size)
{
	t_small_header	*header;
	void			*memory;

	header = (t_small_header*)(ptr - sizeof(t_small_header));
	if (header->canary != CANARY)
		return (NULL);
	if (header->size > TINY_SIZE && size <= TINY_SIZE)
	{
		memory = malloc(size);
		ft_memcpy(memory, ptr, size);
		free(ptr);
		return (memory);
	}
	else if ((int)size < header->size)
	{
		cut_block(header, size);
		return (ptr);
	}
	else
	{
		memory = malloc(size);
		ft_memcpy(memory, ptr, header->size);
		free(ptr);
		return (memory);
	}
}

void	*realloc(void *ptr, size_t size)
{
	void	*memory;

	if (g_env.verbose == 1)
	{
		ft_putstr("Realloc called for pointer ");
		print_addr(ptr);
		ft_putstr(" and size ");
		ft_putnbr(size);
		ft_putchar('\n');
	}
	if (ptr == NULL)
		memory = malloc(size);
	else if (ptr != NULL && size == 0)
	{
		free(ptr);
		memory = NULL;
	}
	else if (is_large(ptr))
		memory = realloc_large(ptr, size);
	else if (is_mine(ptr))
		memory = realloc_small_tiny(ptr, size);
	else
		memory = NULL;
	return (memory);
}
