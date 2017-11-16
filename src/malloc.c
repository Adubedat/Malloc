/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:00:19 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/16 17:37:22 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>

void	*global_memory = NULL;

void	*my_malloc(size_t size)
{
	t_type	type;
	void	*memory_space;

	if (global_memory == NULL)
		init_global_memory();
    type = get_type(size);
	ft_hexdump(global_memory, 256);
/*	if ((memory_space = get_free_block(size, type)) == NULL)
		printf ("bwah\n");
	else
		printf ("bouyaka\n");*/
	return (global_memory);
}

void	init_global_memory(void)
{
	void			*memory;
	t_global_header	*global;

	memory = mmap(0, TINY_MMAP, PROT_READ | PROT_WRITE,
		   	MAP_ANON | MAP_PRIVATE, -1, 0);
	global_memory = memory;
	global = (t_global_header*)global_memory;
	global->canary = CANARY;
	global->tiny = memory + sizeof(t_global_header);
	global->small = NULL;
	global->large = NULL;
	global->tiny_size = TINY_MMAP;
	global->small_size = 0;
	global->large_size = 0;
}

t_type	get_type(size_t size)
{
	t_type type;

	if (size <= TINY_SIZE)
		type = TINY;
	else if (size <= SMALL_SIZE)
		type = SMALL;
	else
		type = LARGE;
	return (type);
}

void	*get_free_space(size_t size, t_type type)
{
	t_global_header global;
	void *memory = NULL;

	return (memory);
}
