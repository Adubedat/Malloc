/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:34:37 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/28 22:46:28 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>

extern void	*g_global_memory;

int		is_large(void *ptr)
{
	t_global_header	*global;
	t_block_list	*temp;

	global = (t_global_header*)g_global_memory;
	temp = global->large;
	while (temp != NULL)
	{
		if ((void*)(temp + 1) == ptr)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	free_large(void	*ptr)
{
	t_global_header	*global;
	t_block_list	*temp;
	t_large_header	*header;

	global = (t_global_header*)g_global_memory;
	temp = global->large;
	ptr = ptr - sizeof(t_block_list);
	header = (t_large_header*)(ptr - sizeof(t_large_header));
	if (temp == ptr)
	{
		global->large = temp->next;
		munmap(ptr - sizeof(t_large_header), header->size);
		return ;
	}
	while (temp->next != NULL)
	{
		if (temp->next == ptr)
		{
			temp->next = temp->next->next;
			munmap(ptr - sizeof(t_large_header), header->size);
			return ;
		}
		temp = temp->next;
	}
}

void	small_defragmentation(t_small_header *header)
{
	t_global_header	*global;
	t_block_list	*temp;
	size_t			current_place;

	global = (t_global_header*)g_global_memory;
	temp = global->small;
	while (((void*)header - (void*)temp < 0
			|| (void*)header - (void*)temp > global->small_size)
			&& (temp != NULL))
		temp = temp->next;
	if (temp == NULL)
		return ;
	if (temp == global->small)
		current_place = (void*)header - (void*)temp + sizeof(t_global_header);
	else
		current_place = (void*)header - (void*)temp;
	if ((t_small_header*)(temp + 1) == header)
		defrag_right(header);
	else if (current_place + sizeof(t_small_header) + header->size
			>= global->small_size)
		defrag_left(header, current_place);
	else
		defrag_both(header, current_place);
}


void	tiny_defragmentation(t_small_header	*header)
{
	t_global_header	*global;
	t_block_list	*temp;
	size_t			current_place;

	global = (t_global_header*)g_global_memory;
	temp = global->tiny;
	while (((void*)header - (void*)temp < 0
			|| (void*)header - (void*)temp > global->tiny_size)
			&& (temp != NULL))
		temp = temp->next;
	if (temp == NULL)
		return (small_defragmentation(header));
	if (temp == global->tiny)
		current_place = (void*)header - (void*)temp + sizeof(t_global_header);
	else
		current_place = (void*)header - (void*)temp;
	if ((t_small_header*)(temp + 1) == header)
		defrag_right(header);
	else if (current_place + sizeof(t_small_header) + header->size
			>= global->tiny_size)
		defrag_left(header, current_place);
	else
		defrag_both(header, current_place);
}

void	free(void *ptr)
{
	t_small_header	*header;

	if (ptr == NULL)
		return ;
	if (is_large(ptr))
		free_large(ptr);
	else
	{
		header = (t_small_header*)(ptr - sizeof(t_small_header));
		header->free = 1;
		tiny_defragmentation(header);
	}
}
