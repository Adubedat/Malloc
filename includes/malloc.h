/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:04:48 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/22 18:12:30 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define TINY_SIZE	64
# define SMALL_SIZE 4096

# define CANARY		0xDEADBEAF
# include <unistd.h>
# include "libft.h"

typedef enum					e_type
{
	TINY,
	SMALL,
	LARGE
}								t_type;

typedef struct					s_block_list
{
		struct s_block_list		*next;
}								t_block_list;

typedef struct					s_small_header
{
		int						canary;
		unsigned short			size;
		unsigned char			free;
}								t_small_header;

typedef struct					s_large_header
{
		int						canary;
		size_t					size;
		unsigned char			free;
}								t_large_header;

typedef struct					s_global_header
{
		t_block_list			*tiny;
		t_block_list			*small;
		t_block_list			*large;
		size_t					tiny_size;
		size_t					small_size;
}								t_global_header;

void	*my_malloc(size_t size);
t_type	get_type(size_t size);
void	init_global_memory(void);
void	*get_free_space_tiny(size_t size, t_block_list *begin,
		size_t info_size);
void	init_global_memory(void);

#endif
