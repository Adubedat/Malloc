/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:04:48 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/07 18:40:22 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define TINY_SIZE	64
# define SMALL_SIZE 4096

# include <unistd.h>
//# include "libft.h"

typedef enum					e_type
{
	TINY,
	SMALL,
	LARGE
}								t_type;

typedef enum					e_bool
{
	true,
	false
}								t_bool;

typedef struct					s_mmap_block
{
		int						canary;
		t_type					type;
		struct s_mmap_block		*next;
		struct s_memory_block	*memory_block;
}								t_mmap_block;

typedef struct					s_memory_block
{
		int						canary;
		size_t					size;
		t_bool					free;
		struct s_memory_block	*next;
		void					*memory;
}								t_memory_block;

t_type	get_type(size_t size);
void	*get_free_block(size_t size, t_type type);
void	*get_free_space(t_mmap_block *block, size_t size, t_type type);
#endif
