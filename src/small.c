/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:13:46 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/17 15:15:08 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>

extern void	*g_global_memory;

void	expand_small(t_small_header *memory)
{
	t_global_header	*global;
	void			*new_memory;
	int				size;

	while (size < (100 * SMALL_SIZE))
		size += getpagesize();
	global = (t_global_header*)g_global_memory;
	size = global->small_size + size;
	new_memory = mmap(0, size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0);
	ft_memcpy(new_memory, global->small, global->small_size);
	munmap(global->small, global->small_size);
	global->small = (t_small_header*)new_memory;
	global->small_size = size;
}
