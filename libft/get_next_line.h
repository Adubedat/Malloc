/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:38:53 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/04 18:15:41 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

typedef struct		s_gnl
{
	int				i;
	int				fd;
	int				nbr;
	char			buf[BUFF_SIZE + 1];
}					t_gnl;

int					get_next_line(int const fd, char **line);

#endif
