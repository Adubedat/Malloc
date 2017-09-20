/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:24:34 by adubedat          #+#    #+#             */
/*   Updated: 2015/11/29 14:26:03 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		*fill_result_when_end_is_higher(int start, int end, int *result)
{
	int i;

	i = 0;
	while (i <= (end - start))
	{
		result[i] = end - i;
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int		*fill_result_when_end_is_lower(int start, int end, int *result)
{
	int i;

	i = 0;
	while (i <= (start - end))
	{
		result[i] = end + i;
		i++;
	}
	result[i] = '\0';
	return (result);
}

int				*ft_rrange(int start, int end)
{
	int *result;

	if (end >= start)
	{
		result = (int*)malloc(sizeof(*result) * (end - start + 1));
		fill_result_when_end_is_higher(start, end, result);
	}
	else
	{
		result = (int*)malloc(sizeof(*result) * (start - end + 1));
		fill_result_when_end_is_lower(start, end, result);
	}
	return (result);
}
