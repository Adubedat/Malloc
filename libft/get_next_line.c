/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:17:44 by adubedat          #+#    #+#             */
/*   Updated: 2016/01/04 18:13:34 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*fill_str(int const fd, char *str, t_gnl *t, int j)
{
	int			ret;
	int			p;

	p = t[j].i;
	t[j].buf[BUFF_SIZE] = '\0';
	while (t[j].buf[t[j].i] != '\n' && t[j].buf[t[j].i] != '\0')
		t[j].i++;
	if (t[j].buf[t[j].i] == '\0')
	{
		str = ft_strjoin_free_both(str, ft_strsub(t[j].buf, p, (t[j].i - p)));
		if ((ret = read(fd, t[j].buf, BUFF_SIZE)) == -1)
			return (NULL);
		if (ret == 0)
			return (str);
		t[j].buf[ret] = '\0';
	}
	else if (t[j].buf[t[j].i] == '\n')
	{
		str = ft_strjoin_free_both(str, ft_strsub(t[j].buf, p, (t[j].i++ - p)));
		if (str[0] == '\0')
			str = ft_strdup("\n");
		return (str);
	}
	t[j].i = 0;
	return (fill_str(fd, str, t, j));
}

static int		check_fd(int const fd, t_gnl *t)
{
	int			j;

	j = 0;
	while (t[j].nbr != 0)
	{
		if (t[j].fd == fd)
			return (j);
		j++;
	}
	t[j].fd = fd;
	t[j].nbr = j + 1;
	return (j);
}

int				get_next_line(int const fd, char **line)
{
	char			*str;
	char			**tmp;
	int				index;
	static t_gnl	t[1024] = {{0, 0, 0, {0}}};

	index = check_fd(fd, t);
	tmp = line;
	if (!(str = ft_strnew(0)))
		return (-1);
	if (!(str = fill_str(fd, str, t, index)))
		return (-1);
	if (str[0] == '\0')
		return (0);
	if (!(line = (char**)malloc(sizeof(char*) * 1)))
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (str[0] != '\n')
	{
		if (!(*line = ft_strjoin_free_s2(*line, str)))
			return (-1);
	}
	*tmp = *line;
	return (1);
}
