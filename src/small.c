/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:11:26 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/24 19:42:57 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>
#include <signal.h>

extern void	*g_global_memory;

void			add_to_small_list(t_block_list *list, void *new_memory)
{
	while (list->next != NULL)
		list = list->next;
	list->next = (t_block_list*)new_memory;
	list->next->next = NULL;
}

void			expand_small(void)
{
	t_global_header	*global;
	t_block_list	*temp;
	t_small_header	*new_header;
	void			*new_memory;

	global = (t_global_header*)g_global_memory;
	if ((new_memory = mmap(0, global->small_size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return ;
	temp = global->small;
	if (temp == NULL)
	{
		global->small = (t_block_list*)new_memory;
		global->small->next = NULL;
	}
	else
		add_to_small_list(temp, new_memory);
	new_header = (t_small_header*)(new_memory + sizeof(t_block_list));
	new_header->canary = CANARY;
	new_header->size = global->small_size - sizeof(*new_header) - sizeof(*temp);
	new_header->free = 1;
}

void			*go_to_next_block(size_t size, t_block_list *begin)
{
	if (begin->next == NULL)
		expand_small();
	return (get_free_space_small(size, begin->next, sizeof(*begin)));
}

void			*get_free_space_small(size_t size, t_block_list *begin,
		size_t info_size)
{
	t_small_header	*header;
	t_global_header	*global;
	unsigned int	total_size;
	unsigned int	current_place;

	current_place = 0;
	if (begin == NULL)
		return (NULL);
	global = (t_global_header*)g_global_memory;
	total_size = global->small_size - info_size;
	header = (t_small_header*)(begin + 1);
	while (!header->free || header->size < size)
	{
		if (header->canary != 0xDEADBEAF)
			raise(SIGSEGV);
		current_place += sizeof(*header) + header->size;
		if (current_place >= total_size)
			return (go_to_next_block(size, begin));
		header = (t_small_header*)((void*)header + (sizeof(*header)
					+ header->size));
	}
	header->free = 0;
	header = cut_block(header, size);
	return ((void*)(header + 1));
}
