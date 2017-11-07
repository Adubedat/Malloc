/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:00:19 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/07 18:42:02 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>

void	*global_memory = NULL;

void	*malloc(size_t size)
{
	t_type	type;
	void	*memory_space;

    type = get_type(size);
	if ((memory_space = get_free_block(size, type)) == NULL)
		printf ("bwah\n");
	else
		printf ("bouyaka\n");
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

void	*get_free_block(size_t size, t_type type)
{
	t_mmap_block	*current;
	void			*memory;

	current = global_memory;
	while (current != NULL)
	{
		if (current->type == type 
			&& (memory = get_free_space(current, size, type)) != NULL)
			return (memory);
		current = current->next;
	}
	return (NULL);
}

void	*get_free_space(t_mmap_block *block, size_t size, t_type type)
{
	printf ("test");
	return (NULL);
}
