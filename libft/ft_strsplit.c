/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:43:38 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/19 01:09:37 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_number(char const *s, char c)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		result++;
		if (s[i - 1] == c)
			result -= 1;
	}
	return (result);
}

static int	words_size(char const *s, char c, int i)
{
	int		res;

	res = 0;
	while (s[i] != c && s[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}

static char	**new_tab(char const *s, char c, int result)
{
	char	**str;
	int		i;
	int		j;
	int		word_size;

	i = 0;
	j = 0;
	if (!(str = (char**)malloc(sizeof(char*) * result + 1)))
		return (NULL);
	while (i < result)
	{
		word_size = 0;
		while (s[j] == c && s[j] != '\0')
			j++;
		word_size = words_size(s, c, j);
		while (s[j] != c && s[j] != '\0')
			j++;
		if (!(str[i] = (char*)malloc(sizeof(char) * (word_size + 1))))
			return (NULL);
		i++;
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i[2];
	int		j;
	int		w_nbr;

	i[0] = 0;
	i[1] = 0;
	w_nbr = words_number(s, c);
	if (s == NULL)
		return (NULL);
	if (!(str = new_tab(s, c, w_nbr)))
		return (NULL);
	while (i[0] < w_nbr)
	{
		j = 0;
		while (s[i[1]] == c && s[i[1]] != '\0')
			i[1]++;
		while (s[i[1]] != c && s[i[1]] != '\0')
			str[i[0]][j++] = s[i[1]++];
		str[i[0]++][j] = '\0';
	}
	str[i[0]] = NULL;
	return (str);
}
