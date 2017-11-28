/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:00:19 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/28 19:42:17 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>

void	*g_global_memory = NULL;

void	*malloc(size_t size)
{
	t_global_header	*global;
	void			*memory_space;

	if (g_global_memory == NULL)
		init_global_memory();
	if ((global = (t_global_header*)g_global_memory) == NULL)
		return (NULL);
	if (size > 0 && size <= TINY_SIZE)
		return (get_free_space_tiny(size, global->tiny,
		sizeof(t_global_header) + sizeof(t_block_list)));
	else if (size > TINY_SIZE && size <= SMALL_SIZE)
	{
		if (global->small == NULL)
			expand_small();
		return (get_free_space_small(size, global->small,
			sizeof(t_block_list)));
	}
	else if (size > SMALL_SIZE)
		return (get_free_space_large(size));
	else
		return (NULL);
}

void	init_tiny_header(void *memory, unsigned short size)
{
	t_small_header	*tiny;
	t_global_header	*global;

	global = (t_global_header*)memory;
	tiny = (t_small_header*)(memory + size);
	tiny->canary = CANARY;
	tiny->size = global->tiny_size - size - sizeof(t_small_header);
	tiny->free = 1;
}

void	init_global_memory(void)
{
	void			*memory;
	t_global_header	*global;
	t_block_list	*tiny;
	int				size;

	size = 0;
	while (size < ((100 * (TINY_SIZE + sizeof(t_small_header))
		+ sizeof(t_global_header))))
		size += getpagesize();
	if ((memory = mmap(0, size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return ;
	g_global_memory = memory;
	tiny = (t_block_list*)(memory + sizeof(t_global_header));
	tiny->next = NULL;
	global = (t_global_header*)g_global_memory;
	global->tiny = tiny;
	global->small = NULL;
	global->large = NULL;
	global->tiny_size = size;
	while (size < ((100 * (SMALL_SIZE + sizeof(t_small_header))
		+ sizeof(t_block_list))))
		size += getpagesize();
	global->small_size = size;
	init_tiny_header(memory, sizeof(t_global_header) + (sizeof(t_block_list)));
}
