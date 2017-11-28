/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:27:29 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/28 22:07:15 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

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
	if (header->size > TINY_SIZE && size <= TINY_SIZE)
	{
		memory = malloc(size);
		ft_memcpy(memory, ptr, size);
		free(ptr);
		return (memory);
	}
	else if (size < header->size)
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
	if (ptr == NULL)
		return (malloc(size));
	if (ptr != NULL && size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (is_large(ptr))
		return (realloc_large(ptr, size));
	else
		return (realloc_small_tiny(ptr, size));
}
