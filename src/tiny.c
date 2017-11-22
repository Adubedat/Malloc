/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:11:26 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/22 18:15:12 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>
#include <signal.h>

extern void	*g_global_memory;

void			expand_tiny(void)
{
	t_global_header	*global;
	t_block_list	*temp;
	t_small_header	*new_header;
	void			*new_memory;

	global = (t_global_header*)g_global_memory;
	new_memory = mmap(0, global->tiny_size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0);
	temp = global->tiny;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (t_block_list*)new_memory;
	temp->next->next = NULL;
	new_header = (t_small_header*)(new_memory + sizeof(t_small_header));
	new_header->canary = CANARY;
	new_header->size = global->tiny_size - sizeof(new_header) - sizeof(temp);
	new_header->free = 1;
}

t_small_header	*cut_block(t_small_header *header, size_t size)
{
	t_small_header	*new_header;
	void			*temp;

	temp = (void*)header;
	if (header->size > (size + sizeof(header)))
	{
		new_header = (t_small_header*)(temp + sizeof(header) + size);
		new_header->canary = CANARY;
		new_header->size = header->size - size - sizeof(header);
		new_header->free = 1;
		header->size = size;
	}
	return (header);
}

void			*get_free_space_tiny(size_t size, t_block_list *begin,
		size_t info_size)
{
	t_small_header	*header;
	t_global_header	*global;
	unsigned short	total_size;
	unsigned short	current_place;

	current_place = 0;
	global = (t_global_header*)g_global_memory;
	total_size = global->tiny_size - info_size;
	header = (t_small_header*)(begin + 1);
	while (!header->free || header->size < size)
	{
		if (header->canary != 0xDEADBEAF)
			raise(SIGSEGV);
		current_place += sizeof(header) + header->size;
		if (current_place >= total_size)
		{
			if (begin->next == NULL)
				expand_tiny();
			return (get_free_space_tiny(size, begin->next, sizeof(begin)));
		}
		header = (t_small_header*)((void*)header + (sizeof(header)
					+ header->size));
	}
	header->free = 0;
	header = cut_block(header, size);
	return ((void*)(header + 1));
}
