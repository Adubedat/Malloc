/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:27:11 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/24 19:28:20 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>

extern void	*g_global_memory;

void	*get_free_space_large(size_t size)
{
	t_global_header	*global;
	t_block_list	*new_large;
	size_t			map_size;
	void			*new_memory;

	while (map_size < size + sizeof(t_block_list))
		map_size += getpagesize();
	if ((new_memory = mmap(0, map_size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	new_large = (t_block_list*)new_memory;
	new_large->next = global->large;
	global->large = new_large;
	return (new_memory + sizeof(t_block_list));
}
