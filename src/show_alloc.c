/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:41:32 by adubedat          #+#    #+#             */
/*   Updated: 2017/12/05 21:57:53 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

long long int	parse_small(t_block_list *begin, int total_size, int count)
{
	t_small_header	*header;
	t_global_header	*global;
	int				current_place;

	global = (t_global_header*)g_global_memory;
	current_place = 0;
	if (begin == NULL)
		return (count);
	header = (t_small_header*)(begin + 1);
	while (current_place + header->size + sizeof(t_small_header)
			< (size_t)total_size)
	{
		if (!header->free)
		{
			print_alloc(header + 1, (void*)(header + 1) + header->size,
					header->size);
			count += header->size;
		}
		current_place += header->size + sizeof(t_small_header);
		header = (t_small_header*)((void*)(header + 1) + header->size);
	}
	return (parse_small(begin->next, global->small_size
				- sizeof(t_block_list), count));
}

long long int	parse_tiny(t_block_list *begin, int total_size, int count)
{
	t_small_header	*header;
	t_global_header	*global;
	int				current_place;

	global = (t_global_header*)g_global_memory;
	current_place = 0;
	if (begin == NULL)
		return (count);
	header = (t_small_header*)(begin + 1);
	while (current_place + header->size + sizeof(t_small_header)
			< (size_t)total_size)
	{
		if (!header->free)
		{
			print_alloc(header + 1, (void*)(header + 1) + header->size,
					header->size);
			count += header->size;
		}
		current_place += header->size + sizeof(t_small_header);
		header = (t_small_header*)((void*)(header + 1) + header->size);
	}
	return (parse_tiny(begin->next, global->tiny_size
				- sizeof(t_block_list), count));
}

t_sorted_list	*insert(t_block_list *elem, t_sorted_list *sorted_large)
{
	t_sorted_list	*new;

	pthread_mutex_unlock(&g_mutex);
	new = malloc(sizeof(t_sorted_list));
	pthread_mutex_lock(&g_mutex);
	new->address = elem;
	if (sorted_large == NULL)
	{
		new->next = NULL;
		sorted_large = new;
		return (sorted_large);
	}
	while (sorted_large->address < elem && sorted_large->next != NULL)
		sorted_large = sorted_large->next;
	if (sorted_large->address < elem)
	{
		new->next = sorted_large->next;
		sorted_large->next = new;
	}
	else
	{
		new->next = sorted_large;
		sorted_large = new;
	}
	return (sorted_large);
}

long long int	parse_large(t_block_list *begin, long long int count)
{
	t_sorted_list	*sorted_large;
	t_sorted_list	*temp;
	t_large_header	*header;

	sorted_large = NULL;
	while (begin != NULL)
	{
		sorted_large = insert(begin, sorted_large);
		begin = begin->next;
	}
	if (sorted_large != NULL)
		print_large((void*)sorted_large->address - sizeof(*header));
	while (sorted_large != NULL)
	{
		header = (t_large_header*)sorted_large->address - 1;
		print_alloc((void*)(header + 1) + sizeof(*begin), (void*)header
			+ header->size, header->size - sizeof(*header) - sizeof(*begin));
		count += header->size - sizeof(*header) - sizeof(*begin);
		temp = sorted_large->next;
		pthread_mutex_unlock(&g_mutex);
		free(sorted_large);
		pthread_mutex_lock(&g_mutex);
		sorted_large = temp;
	}
	return (count);
}

void			show_alloc_mem(void)
{
	t_global_header	*global;
	long long int	total;

	pthread_mutex_lock(&g_mutex);
	total = 0;
	global = (t_global_header*)g_global_memory;
	if (global->tiny)
	{
		ft_putstr("TINY : ");
		print_addr(global->tiny);
		ft_putchar('\n');
	}
	total += parse_tiny(global->tiny, (global->tiny_size
			- sizeof(t_global_header) - sizeof(t_block_list)), 0);
	if (global->small)
	{
		ft_putstr("SMALL : ");
		print_addr(global->small);
		ft_putchar('\n');
	}
	total += parse_small(global->small, (global->small_size
			- sizeof(t_block_list)), 0);
	total += parse_large(global->large, 0);
	print_total(total);
	pthread_mutex_unlock(&g_mutex);
}
