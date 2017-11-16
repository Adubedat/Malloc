/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:04:48 by adubedat          #+#    #+#             */
/*   Updated: 2017/11/16 17:54:53 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define TINY_SIZE	64
# define SMALL_SIZE 4096

# define TINY_MMAP	8192
# define SMALL_MMAP	413696

# define CANARY		0xDEADBEAF
# include <unistd.h>
# include "libft.h"

typedef enum					e_type
{
	TINY,
	SMALL,
	LARGE
}								t_type;

typedef struct					s_tiny_header
{
		int						canary;
		unsigned char			size;
		unsigned char			free;
}								t_tiny_header;

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
		int						canary;
		t_tiny_header			*tiny;
		t_small_header			*small;
		t_large_header			*large;
		size_t					tiny_size;
		size_t					small_size;
		size_t					large_size;
}								t_global_header;

t_type	get_type(size_t size);
void	init_global_memory(void);
void	*get_free_space(size_t size, t_type type);

#endif
