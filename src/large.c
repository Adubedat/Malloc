/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:27:11 by adubedat          #+#    #+#             */
/*   Updated: 2017/12/04 19:43:11 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <sys/mman.h>
#include "libft.h"

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

void	print_large_ex(t_large_header *header)
{
	ft_putnbr(header->size - sizeof(t_large_header) - sizeof(t_block_list));
	ft_putstr(" bytes allocated from ");
	print_addr((void*)header + sizeof(t_large_header) + sizeof(t_block_list));
	ft_putstr(" to ");
	print_addr((void*)header + header->size);
	ft_putchar('\n');
}

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
	pthread_mutex_lock(&g_mutex);
	header = (t_large_header*)new_memory;
	header->size = map_size;
	new_large = (t_block_list*)(new_memory + sizeof(t_large_header));
	new_large->next = global->large;
	global->large = new_large;
	if (g_env.large == 1)
		print_large_ex(header);
	pthread_mutex_unlock(&g_mutex);
	return (new_memory + sizeof(t_block_list) + sizeof(t_large_header));
}
