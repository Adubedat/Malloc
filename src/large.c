/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:27:11 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/27 15:18:49 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>

extern void	*g_global_memory;

void	*get_free_space_large(size_t size)
{
	t_global_header	*global;
	t_block_list	*new_large;
	t_large_header	*header;
	size_t			map_size;
	void			*new_memory;

	global = (t_global_header*)g_global_memory;
	map_size = 0;
	while (map_size < (size + sizeof(t_block_list) + sizeof(t_large_header)))
		map_size += getpagesize();
	if ((new_memory = mmap(0, map_size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	header = (t_large_header*)new_memory;
	header->size = map_size;
	new_large = (t_block_list*)(new_memory + sizeof(t_large_header));
	new_large->next = global->large;
	global->large = new_large;
	return (new_memory + sizeof(t_block_list) + sizeof(t_large_header));
}
