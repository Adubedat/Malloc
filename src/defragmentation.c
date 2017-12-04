/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defragmentation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:29:10 by adubedat          #+#    #+#             */
/*   Updated: 2017/12/04 22:13:23 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

void	free_memset(t_small_header *header)
{
	int	size;

	if (header->size > getpagesize())
		size = getpagesize();
	else
		size = header->size;
	if (g_env.scribble == 1)
		ft_memset(header + 1, 0x55, size);
	else
		ft_bzero(header + 1, size);
}

void	defrag_left(t_small_header *header, size_t current_place)
{
	unsigned char	*str;
	t_small_header	*prev_header;

	if (current_place <= 0)
		return ;
	str = (unsigned char*)header - 1;
	current_place--;
	while (current_place != 0
	&& (str[0] != 0xAF || str[1] != 0xBE || str[2] != 0xAD || str[3] != 0xDE))
	{
		current_place--;
		str -= 1;
	}
	if (current_place <= 0)
		return ;
	prev_header = (t_small_header*)str;
	if (prev_header->free == 1)
	{
		prev_header->size += sizeof(t_small_header) + header->size;
		free_memset(prev_header);
	}
	else
		free_memset(header);
}

void	defrag_right(t_small_header *header)
{
	t_small_header	*next_header;

	next_header = (t_small_header*)((void*)header + sizeof(t_small_header)
			+ header->size);
	if (next_header->free == 1)
		header->size += sizeof(t_small_header) + next_header->size;
	free_memset(header);
}

void	defrag_both(t_small_header *header, size_t current_place)
{
	defrag_right(header);
	defrag_left(header, current_place);
}
