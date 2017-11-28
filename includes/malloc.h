/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:04:48 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/28 21:20:26 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define TINY_SIZE	64
# define SMALL_SIZE 4096

# define CANARY		0xDEADBEAF
# include <unistd.h>
# include "libft.h"

typedef struct				s_block_list
{
	struct s_block_list		*next;
}							t_block_list;

typedef struct				s_small_header
{
	int						canary;
	int						size;
	char					free;
}							t_small_header;

typedef struct				s_large_header
{
	size_t					size;
}							t_large_header;

typedef struct				s_global_header
{
	t_block_list			*tiny;
	t_block_list			*small;
	t_block_list			*large;
	size_t					tiny_size;
	size_t					small_size;
}							t_global_header;

void						*malloc(size_t size);
void						free(void *ptr);
void						*realloc(void *ptr, size_t size);
void						init_global_memory(void);
void						*get_free_space_tiny(size_t size,
							t_block_list *begin, size_t info_size);
void						*get_free_space_small(size_t size,
							t_block_list *begin, size_t info_size);
void						*get_free_space_large(size_t size);
void						init_global_memory(void);
t_small_header				*cut_block(t_small_header *header, size_t size);
void						expand_small(void);
void						defrag_left(t_small_header *header, size_t current_place);
void						defrag_right(t_small_header *header);
void						defrag_both(t_small_header *header, size_t current_place);
int							is_large(void *ptr);

#endif
