/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:52:22 by adubedat          #+#    #+#             */
/*   Updated: 2015/11/29 14:58:05 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int n, int power)
{
	int i;
	int result;

	i = 0;
	result = n;
	while (i < (power - 1))
	{
		result = result * n;
		i++;
	}
	return (result);
}
